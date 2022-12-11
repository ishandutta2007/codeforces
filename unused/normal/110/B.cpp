#include <stdio.h>

int main()
{
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
                putchar('a' + i % 4);
        }
        putchar('\n');
        return 0;
}