#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    if (n < 4 || k >= 4 || k == 1)
    {
        printf("-1\n");
        return 0;
    }
    if (n == 4)
    {
        if (k == 2)
        {
            printf("-1\n");
            return 0;
        }
        printf("3\n");
        printf("1 2\n");
        printf("2 3\n");
        printf("3 4\n");
        return 0;
    }
    if (k == 2)
    {
        printf("%d\n", n - 1);
        for (int i = 1; i < n; i++)
            printf("%d %d\n", i, i + 1);
        return 0;
    }
    printf("%d\n", n - 1);
    printf("1 2\n");
    for (int i = 3; i <= n; i++)
        printf("%d %d\n", 2 - (i & 1), i);

    return 0;
}