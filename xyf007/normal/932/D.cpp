#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
const long long inf = 5e18;
int q, cnt = 1;
long long a[400001], fa[400001][21], sum[400001][21];
int main(int argc, char const *argv[])
{
    scanf("%d", &q);
    a[0] = inf; 
    memset(sum[1], 0x7f, sizeof(sum[1]));
    long long last = 0;
    while (q--)
    {
        int op;
        long long r, x;
        scanf("%d%lld%lld", &op, &r, &x);
        r ^= last;
        x ^= last;
        if (op == 1)
        {
            int u = ++cnt;
            a[u] = x;
            if (a[r] >= x)
            {
                fa[u][0] = r;
            }
            else
            {
                for (int i = 20; i >= 0; i--)
                {
                    if (a[fa[r][i]] < x)
                    {
                        r = fa[r][i];
                    }
                }
                fa[u][0] = fa[r][0];
            }
            if (!fa[u][0])
            {
                sum[u][0] = inf;
            }
            else
            {
                sum[u][0] = a[fa[u][0]];
            }
            for (int i = 1; i <= 20; i++)
            {
                fa[u][i] = fa[fa[u][i - 1]][i - 1];
                if (!fa[u][i])
                {
                    sum[u][i] = inf;
                }
                else
                {
                    sum[u][i] = sum[u][i - 1] + sum[fa[u][i - 1]][i - 1];
                }
            }
        }
        else
        {
            if (a[r] > x)
            {
                last = 0;
                printf("0\n");
            }
            else
            {
                last = 1;
                x -= a[r];
                for (int i = 20; i >= 0; i--)
                {
                    if (x >= sum[r][i])
                    {
                        x -= sum[r][i];
                        last += (1 << i);
                        r = fa[r][i];
                    }
                }
                printf("%lld\n", last);
            }
        }
    }
    return 0;
}