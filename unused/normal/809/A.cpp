#include <bits/stdc++.h>
using namespace std;

int x[300005];
constexpr int MOD = 1000000007;

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&x[i]);
    sort(x + 1, x + n + 1);

    int ans = 0;
    int sum = 0, mul = 0;

    for (int i = 1; i <= n; i++)
    {
        ans = (ans + mul * 1ll * x[i] - sum + MOD) % MOD;
        sum = (sum * 2LL + x[i]) % MOD;
        mul = (mul * 2 + 1) % MOD;
    }

    printf("%d\n", ans);
}