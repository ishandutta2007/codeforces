#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, k;
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        if (((n & 1) && !(k & 1)) || n < k)
        {
            printf("NO\n");
            continue;
        }
        if ((n - k + 1) & 1)
        {
            printf("YES\n");
            for (int i = 1; i < k; i++)
            {
                printf("1 ");
            }
            printf("%d\n", n - k + 1);
        }
        else
        {
            if (n < 2 * k)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
                for (int i = 1; i < k; i++)
                {
                    printf("2 ");
                }
                printf("%d\n", n - 2 * k + 2);
            }
        }
    }
    return 0;
}