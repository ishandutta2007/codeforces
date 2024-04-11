#include <bits/stdc++.h>
using namespace std;

int dat[100005];
pair<int, long long> L[100005];
pair<int, long long> R[100005];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d", &dat[i]);

    L[0].first = INT_MIN;
    L[0].second = 0;

    for (int i = 1; i <= n; i++)
    {
        int res = dat[i] - i;
        L[i].first = max(L[i - 1].first, res);
        L[i].second = L[i - 1].second + L[i].first - res;
    }

    R[n + 1].first = INT_MIN;
    R[n + 1].second = 0;

    for (int i = n; i >= 1; i--)
    {
        int res = dat[i] + i;
        R[i].first = max(R[i + 1].first, res);
        R[i].second = R[i + 1].second + R[i].first - res;
    }

    long long ans = LLONG_MAX;

    for (int i = 1; i <= n; i++)
    {
        int adde1 = L[i].first - (dat[i] - i);
        int adde2 = R[i].first - (dat[i] + i);
        ans = min(ans, L[i].second + R[i + 1].second + abs(adde1 - adde2));
    }

    printf("%lld\n", ans);
}