#include <bits/stdc++.h>
using namespace std;

char str[200005];
int c1[200005], c2[200005];
int len;
int fact[400005];
int finv[400005];
constexpr int MOD = 1000000007;

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 400000; i++) fact[i] = fact[i-1] * 1ll * i % MOD;
    finv[400000] = 632470676;
    for (int i = 399999; i >= 0; i--) finv[i] = finv[i+1] * 1ll * (i+1) % MOD;

    scanf("%s",str + 1);
    len = strlen(str + 1);
    for (int i = 1; i <= len; i++)
    {
        c1[i] = c1[i-1]; c2[i] = c2[i-1];
        if (str[i] == '(') c1[i]++;
        else c2[i]++;
    }

    int ans = 0;

    for (int i = 1; i <= len; i++)
    {
        if (str[i] == ')') continue;
        int left = c1[i];
        int right = c2[len] - c2[i];

        ans = (ans + fact[left + right] * 1ll * finv[left] % MOD * finv[right] - 1) % MOD;
        ans = (ans + MOD - fact[left + right - 1] * 1ll * finv[left - 1] % MOD * finv[right] % MOD + 1) % MOD;
    }

    printf("%d\n", ans);
}