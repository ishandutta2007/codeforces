#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, q;
long long a[101][101], k;
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int T = 2; T <= 2 * n; T++)
    {
        for (int i = 1; i <= 2 * n - 1; i++)
        {
            int si = min(i, n), sj = T - si;
            while (si > 0 && sj <= n)
            {
                if (sj & 1)
                {
                    a[si--][sj++] = 0;
                }
                else
                {
                    a[si--][sj++] = 1LL << (T - 2);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%lld ", a[i][j]);
        }
        printf("\n");
    }
    fflush(stdout);
    scanf("%d", &q);
    while (q--)
    {
        scanf("%lld", &k);
        printf("1 1\n");
        int pre = 0, x = 1, y = 1;
        for (int i = 1; i <= 2 * n - 2; i++)
        {
            int now = (k >> i) & 1;
            if (now == pre)
            {
                printf("%d %d\n", ++x, y);
            }
            else
            {
                printf("%d %d\n", x, ++y);
            }
            pre = now;
        }
        fflush(stdout);
    }
    return 0;
}