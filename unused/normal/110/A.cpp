#include <stdio.h>

int main()
{
        char input[100];
        gets(input);

        int count = 0;

        for (char *p = input; *p; p++)
        {
                if (*p == '4' || *p == '7')
                {
                        count++;
                }
        }

        sprintf(input, "%d", count);

        for (char *p = input; *p; p++)
        {
                if (*p != '4' && *p != '7')
                {
                        printf("NO\n");
                        return 0;
                }
        }

        printf("YES\n");
        return 0;
}