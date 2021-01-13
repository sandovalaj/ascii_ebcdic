#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deciBi(int input, int base);
void parity(int par, int n, int array[]);
void ebcdic(char input);

int main(int argc, char* argv[])
{
    int x = strlen(*(argv + 1));

    char input[x];
    int ascii[x];

    strcpy(input, *(argv + 1));

    printf("\nASCII VALUES: \n");
    for (int a = 0; a < x; a++)
    {
        printf("%c is %d\n", input[a], input[a]);
        ascii[a] = input[a];
    }

    printf("\n");
    for (int a = 0; a < x; a++)
    {
        printf("%c: ", input[a]);
        deciBi(ascii[a], 2);
        printf("\n");
    }

    printf("\nEBCDIC VALUES: \n");
    for (int a = 0; a < x; a++)
    {
        printf("%c: ", input[a]);
        ebcdic(input[a]);
    }


    //printf("%d", x);
}

void ebcdic(char input)
{
    char ebcdic[62][2] =
    {
        {"81"},
        {"82"},
        {"83"},
        {"84"},
        {"85"},
        {"86"},
        {"87"},
        {"88"},
        {"89"},
        {"91"},
        {"92"},
        {"93"},
        {"94"},
        {"95"},
        {"96"},
        {"97"},
        {"98"},
        {"99"},
        {"A2"},
        {"A3"},
        {"A4"},
        {"A5"},
        {"A6"},
        {"A7"},
        {"A8"},
        {"A9"},
        {"C1"},
        {"C2"},
        {"C3"},
        {"C4"},
        {"C5"},
        {"C6"},
        {"C7"},
        {"C8"},
        {"C9"},
        {"D1"},
        {"D2"},
        {"D3"},
        {"D4"},
        {"D5"},
        {"D6"},
        {"D7"},
        {"D8"},
        {"D9"},
        {"E2"},
        {"E3"},
        {"E4"},
        {"E5"},
        {"E6"},
        {"E7"},
        {"E8"},
        {"E9"},
        {"F0"},
        {"F1"},
        {"F2"},
        {"F3"},
        {"F4"},
        {"F5"},
        {"F6"},
        {"F7"},
        {"F8"},
        {"F9"}
    };

    char regular[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};
    int decimal[] = {129, 130, 131, 132, 133, 134, 135, 136, 137, 145, 146, 147, 148, 149, 150, 151, 152, 153, 162, 163, 164, 165, 166, 167, 168, 169, 193, 194, 195, 196, 197, 198, 199, 200, 201, 209, 210, 211, 212, 213, 214, 215, 216, 217, 226, 227, 228, 229, 230, 231, 232, 233, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249};

    for (int a = 0; a < 62; a++)
    {
        if (input == regular[a])
        {
            for (int b = 0; b < 2; b++)
            {
                printf("%c", ebcdic[a][b]);
            }
            printf("\t");
            deciBi(decimal[a], 2);
            printf("\n");
        }
    }
}

void deciBi(int input, int base){ 
    int rem;
    int digit = 0;
    int temp = input;

    while (input > 0)
    {
        input = input / base;
        digit++;
    }

    int printMe[digit];
    input = temp;
    int x = 0;

    while (input > 0)
    {
        rem = input % base;
        printMe[x] = rem;
        x++;
        input = input / base;
    }

    for (int a = digit - 1; a >= 0; a--)
    {
        printf("%d", printMe[a]);
        if (a % 4 == 0)
            printf(" ");
    }

    printf("\t\t Even Parity: ");
    parity(0, digit, printMe);
    printf("\t\t Odd Parity: ");
    parity(1, digit, printMe);

}

void parity(int par, int n, int array[])
{
    int sum = 0;

    for (int a = n - 1; a >= 0; a--)
    {
        sum += array[a];
    }

    if (par == 0)//even
    {
        if (sum % 2 == 0)
            printf("0");
        else
            printf("1");
    }

    else if (par == 1)//odd
    {
        if (sum % 2 == 0)
            printf("1");
        else
            printf("0");
    }

    for (int a = n - 1; a >= 0; a--)
    {
        printf("%d", array[a]);
        if (a % 4 == 0)
            printf(" ");
    }
}