/*input
2
1 2
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
ll power(ll x, ll y)
{
	assert(x >= 0 && x < mod);
	if (y == 0)
		return 1;
	if (y % 2 == 1)
		return (power((x * x) % mod, y / 2) * x) % mod;
	else
		return power((x * x) % mod, y / 2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	ll c[n];
	for (ll &i : c)
		cin >> i;
	sort(c, c + n, greater<ll>());
	ll s[n];
	s[0] = c[0];
	for (ll i = 1; i < n; i++)
	{
		s[i] = s[i - 1] + c[i];
		if (s[i] >= mod)
			s[i] -= mod;
	}
	ll x = power(n, mod - 2);
	for (ll k = 1; k <= n; k++)
	{
		ll ans = 0;
		for (ll i = 1; i * k < n; i++)
		{
			ll i1 = i * k;
			ll i2 = min(n - 1, (i + 1) * k - 1);
			ans += s[i2] * i;
			if (i1 > 0)
				ans -= s[i1 - 1] * i;
			ans %= mod;
			if (ans < 0)
				ans += mod;
		}
		ans *= x;
		ans %= mod;
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}