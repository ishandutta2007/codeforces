#include <bits/stdc++.h>
using namespace std;

int dp[5000005];
bool notprime[5000005];
int div_[5000005];
constexpr int MOD = 1000000007;

void getprime()
{
    for (int i = 2; i <= 5000000; i++)
    {
        if (notprime[i]) continue;
        div_[i] = i;
        for (int j = i * 2; j <= 5000000; j += i)
        {
            notprime[j] = true;
            if (div_[j] == 0) div_[j] = i;
        }
    }
}

int D(int t)
{
    if (t == 1) return 0;

    if (dp[t] == 0)
    {
        dp[t] = (D(t / div_[t]) + (t / div_[t]) * 1ll * ((div_[t] * 1ll * (div_[t] - 1) / 2) % MOD)) % MOD;
    }

    return dp[t];
}

int main()
{
    getprime();

    int t, l, r;
    scanf("%d%d%d",&t,&l,&r);

    int T = 1;
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        ans = (ans + T * 1ll * D(i)) % MOD;
        T = T * 1ll * t % MOD;
    }

    printf("%d\n", ans);
}