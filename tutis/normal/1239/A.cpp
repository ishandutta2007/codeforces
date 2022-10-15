/*input
1 3
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll ans = 0;
ll mod = 1000000000 + 7;
ll p(ll a, ll b)
{
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return (a * p((a * a) % mod, b / 2)) % mod;
	else
		return p((a * a) % mod, b / 2);
}
map<pair<ll, ll>, ll>M;
ll dp(ll n, ll w)
{
	if (n == 2)
		return 1;
	if (M.count({n, w}))
		return M[ {n, w}];
	if (w == 0)
	{
		return M[ {n, w}] = dp(n - 1, 1);
	}
	else
	{
		return M[ {n, w}] = (dp(n - 1, 0) + dp(n - 1, 1)) % mod;
	}
}
ll f(ll n)
{
	if (n == 1)
		return 2;
	return (dp(n, 1) * 2 + dp(n, 0) * 2) % mod;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	ll ans = -2;
	ans += f(n);
	ans += f(m);
	ans %= mod;
	if (ans < 0)
		ans += mod;
	cout << ans << "\n";
}