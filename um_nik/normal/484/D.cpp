#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

const ll INF = (ll)1e17;
int n;
const int N = (int)1e6 + 100;
ll a[N];
bool u[N];
ll dp[N];
ll ans;

int sgn(ll x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    u[0] = 1;
    for (int i = 1; i < n - 1; i++)
    {
        if (sgn(a[i] - a[i - 1]) * sgn(a[i] - a[i + 1]) >= 0)
            u[i] = u[i + 1] = 1;
    }
    for (int i = 1; i <= n; i++)
        dp[i] = -INF;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        if (!u[i] || i == n - 1) continue;
        int x = sgn(a[i + 1] - a[i]);
        if (x == 0) continue;
        int idx = i;
        while( idx < n - 1 && x == sgn(a[idx + 1] - a[idx]) )
        {
            idx++;
            dp[idx + 1] = max(dp[idx + 1], dp[i] + x * (a[idx] - a[i]));
        }
    }
    printf("%I64d\n", dp[n]);

    return 0;
}