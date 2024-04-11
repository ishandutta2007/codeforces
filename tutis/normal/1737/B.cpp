/*input
5
8 19
8 20
119 121
1 100000000000000000
1234567891011 1000000000000000000

*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll ans(ll x)
{
	if (x <= 4)
		return x;
	ll c = sqrt(x);
	while (c * c <= x)
		c++;
	while (c * c > x)
		c--;
	ll ans = c;

	while (c * (c + 1) <= x)
		c++;
	while (c * (c + 1) > x)
		c--;
	ans += c;

	while (c * (c + 2) <= x)
		c++;
	while (c * (c + 2) > x)
		c--;

	ans += c;

	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll l, r;
		cin >> l >> r;
		cout << ans(r) - ans(l - 1) << "\n";
	}

}