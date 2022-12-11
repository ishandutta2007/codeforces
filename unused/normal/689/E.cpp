#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;
int fact[400005], finv[400005];
int cnt[200005];

int C(int a, int b)
{
    if (b>a || b<0) return 0;
    return fact[a] * 1ll * finv[b] % MOD * finv[a-b] % MOD;
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 400000; i++) fact[i] = fact[i-1] * 1ll * i % MOD;
    finv[400000] = 632470676;
    for (int i = 399999; i >= 0; i--) finv[i] = finv[i+1] * 1ll * (i + 1) % MOD;

    int n, k;
    scanf("%d%d",&n,&k);

    vector<pair<int,int>> events;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        events.emplace_back(a, 1);
        events.emplace_back(b+1, -1);
    }

    sort(events.begin(),events.end());
    int last = -2e9, now = 0;
    int ans = 0;

    for (auto &e : events)
    {
        if (now)
        {
            ans = (ans + 1ll * (e.first - last) * C(now, k)) % MOD;
        }

        now += e.second;
        last = e.first;
    }

    printf("%d\n", ans);
}