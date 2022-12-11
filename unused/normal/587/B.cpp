#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a;
vector<int> dp;

constexpr int MOD = 1'000'000'007; 

int main()
{
    int n, k;long long l;
    scanf("%d%lld%d",&n,&l,&k);
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i].first);
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    long long maxd = l / n;
    int rem = l % n;
    int ans = 0;
    dp.resize(n, 1);
    for (int j = 0; j < n; j++)
    {
        ans = (ans + maxd % MOD + (a[j].second < rem)) % MOD;
    }

    for (int i = 2; i <= k; i++)
    {
        if (i > maxd + 1) break;
        int sum = 0;
        for (int j = 0, r; j < n;)
        {
            for (r = j; r < n && a[j].first == a[r].first; r++)
                sum = (sum + dp[j]) % MOD;
            while (j < r)
            {
                dp[j] = sum;
                ++j;
            }
        }

        for (int j = 0; j < n; j++)
        {
            ans = (ans + dp[j] * ((maxd - i + 1 + (a[j].second < rem)) % MOD)) % MOD;
        }
    }

    printf("%d\n", ans);
}