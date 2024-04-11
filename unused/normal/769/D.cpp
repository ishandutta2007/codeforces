#include <bits/stdc++.h>
using namespace std;

int cnt[10005];

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d",&t);
        cnt[t]++;
    }

    long long ans = 0;

    if (k == 0)
    {
        for (int i = 0; i <= 10000; i++)
        {
            ans += cnt[i] * 1ll * (cnt[i] - 1) / 2;
        }
    }
    else
    {
        for (int i = 0; i <= 10000; i++)
        {
            for (int j = i + 1; j <= 10000; j++)
            {
                if (__builtin_popcount(i ^ j) == k) ans += 1ll * cnt[i] * cnt[j];
            }
        }
    }

    printf("%lld\n", ans);
}