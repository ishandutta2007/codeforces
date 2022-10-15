#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const long long MOD = 1e9 + 7;
int h, w, r[1001], c[1001], f[1005][1005];
int main(int argc, char const *argv[])
{
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++)
    {
        scanf("%d", &r[i]);
        if (!r[i])
        {
            f[i][1] = 2;
        }
        else
        {
            for (int j = 1; j <= r[i]; j++)
            {
                f[i][j] = 1;
            }
            f[i][r[i] + 1] = 2;
        }
    }
    for (int i = 1; i <= w; i++)
    {
        scanf("%d", &c[i]);
        if (!c[i])
        {
            if (f[1][i] == 1)
            {
                printf("0");
                return 0;
            }
            f[1][i] = 2;
        }
        else
        {
            for (int j = 1; j <= c[i]; j++)
            {
                if (f[j][i] == 2)
                {
                    printf("0");
                    return 0;
                }
                f[j][i] = 1;
            }
            if (f[c[i] + 1][i] == 1)
            {
                printf("0");
                return 0;
            }
            f[c[i] + 1][i] = 2;
        }
    }
    long long ans = 1;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (!f[i][j])
            {
                ans = ans * 2 % MOD;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}