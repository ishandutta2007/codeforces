#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, d;

int main()
{
    scanf("%d%d", &n, &d);
    if (d == 10)
    {
        if (n == 1)
            printf("-1\n");
        else
        {
            printf("1");
            for (int i = 1; i < n; i++)
                printf("0");
            printf("\n");
        }
        return 0;
    }
    if (n == 1)
    {
        printf("%d\n", d);
        return 0;
    }
    printf("1");
    for (int i = 2; i < n; i++)
        printf("0");
    int x = 1;
    for (int i = 1; i < n; i++)
        x = (x * 10) % d;
    printf("%d\n", d - x);

    return 0;
}