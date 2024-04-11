#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll dp1[1000001];
ll dp2[1000001];
ll a[1000001];
ll x[1000001];
ll k1[1000001];
ll k2[1000001];

int main()
{
    ll n, k, ans = 0;
    const ll mod = 1000000007;
    ll l;
    scanf("%lld %lld %lld", &n, &l, &k);
    for(int i = 0; i < n; i++)
    {
	scanf("%lld", a + i);
	x[i] = a[i];
    }
    sort(x, x + n);
    for(int i = 0; i < n; i++)
    {
	a[i] = lower_bound(x, x + n, a[i]) - x + 1;
	k1[a[i]]++;
    }
    ll r = l % n;
    for(int j = 0; j < r; j++)
	k2[a[j]]++;
    for(int i = 0; i <= n; i++)
	dp1[i] = 1;
    for(int i = 1; i <= k && (l + n - 1) / n >= i; i++)
    {
	for(int j = 1; j <= n; j++)
	    dp2[j] = (dp2[j-1] + (ll)dp1[j] * k2[j]) % mod;
	
	ans = (ans + dp2[n]) % mod;
	for(int j = 1; j <= n; j++)
	    dp2[j] = (dp2[j-1] + (ll)dp1[j] * k1[j]) % mod;
	ans = (ans + (l / n - i + 1) % mod * (ll)dp2[n]) % mod;
	for(int j = 0; j <= n; j++)
	    dp1[j] = dp2[j];

    }
    printf("%lld\n", ans % mod);
}