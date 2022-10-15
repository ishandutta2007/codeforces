#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int base = 499, MOD = 998244353;
int n, m, fac[200001], Hash[26][200001], p[26], q[26];
char s[200001];
int calc(int id, int x, int len)
{
    return ((Hash[id][x + len - 1] - 1LL * Hash[id][x - 1] * fac[len]) % MOD + MOD) % MOD;
}
int main(int argc, char const *argv[])
{
    scanf("%d%d%s", &n, &m, s + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = 1LL * fac[i - 1] * base % MOD;
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            Hash[i][j] = (1LL * Hash[i][j - 1] * base + (s[j] - 'a' == i) * 3) % MOD;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r, len;
        scanf("%d%d%d", &l, &r, &len);
        for (int i = 0; i < 26; i++)
        {
            p[i] = calc(i, l, len);
            q[i] = calc(i, r, len);
        }
        sort(p, p + 26);
        sort(q, q + 26);
        bool f = 1;
        for (int i = 0; i < 26; i++)
        {
            if (p[i] != q[i])
            {
                f = 0;
                break;
            }
        }
        if (f)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}