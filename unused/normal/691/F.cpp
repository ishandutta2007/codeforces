#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int cnt[3000005];
long long presum[3000005];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d",&t);
        cnt[t]++;
    }

    for (int i = 1; i <= 1800; i++)
    {
        for (int j = i + 1; i * j <= 3000000; j++)
        {
            presum[i * j] += cnt[i] * 1ll * cnt[j];
        }

        if (i * i <= 3000000) presum[i * i] += cnt[i] * 1ll * (cnt[i] - 1) / 2;
    }

    for (int i = 1; i <= 3000000; i++) presum[i] += presum[i - 1];
    int m;
    scanf("%d",&m);
    for (int i = 0; i < m; i++)
    {
        int p;
        scanf("%d",&p);

        printf("%lld\n", n * (long long)(n - 1) - presum[p - 1] * 2);
    }
}