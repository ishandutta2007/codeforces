/*input
1
5 4

*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
ll ans = 0;
ll f(ll x, ll y, ll a, ll b)
{
	if (x == a && y == b)
		return 0;
	if (x != y && make_pair(max(x, y), max(x, y)) != make_pair(a, b))
		if (max(x, y) <= a && max(x, y) <= b)
			return f(x, y, max(x, y), max(x, y)) + f(max(x, y), max(x, y), a, b);
	if (a != b && make_pair(min(a, b), min(a, b)) != make_pair(x, y))
		if (x <= min(a, b) && y <= min(a, b))
			return f(x, y, min(a, b), min(a, b)) + f(min(a, b), min(a, b), a, b);
	if (x == y && a == b)
		return a - x;
	if (x <= y && a > b)
		return 1;
	if (x >= y && a < b)
		return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll x = 0, y = 0;
	while (n--)
	{
		ll a, b;
		cin >> a >> b;
		ans += f(x, y, a, b);
		x = a;
		y = b;
	}
	if (x == y)
		ans++;
	cout << ans << "\n";
}