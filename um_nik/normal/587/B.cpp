#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const ll MOD = (ll)1e9 + 7;
const int N = (int)1e6 + 100;
int n, k;
ll l;
ll m, q;
pii a[N];
ll dp[N];
ll ans;

ll add(ll x, ll y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
ll mult(ll x, ll y)
{
    return (x * y) % MOD;
}


int main()
{
    scanf("%d%lld%d", &n, &l, &k);
    m = l / n;
    q = l % n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i].X);
    for (int i = 0; i < n; i++)
        a[i].Y = i;
    sort(a, a + n);
    dp[0] = 1LL;
    ans = 0;
    for (int it = 1; it <= k; it++)
    {
        if (it > m + 1) break;
        ll val = 0;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            while(p < n && a[p].X <= a[i].X)
                val = add(val, dp[p++]);
            dp[i] = val;
        }
        for (int i = 0; i < n; i++)
            ans = add(ans, mult(dp[i], (m - it + 1) % MOD));
        for (int i = 0; i < n; i++)
            if (a[i].Y < q)
                ans = add(ans, dp[i]);
    }
    printf("%lld\n", ans);

    return 0;
}