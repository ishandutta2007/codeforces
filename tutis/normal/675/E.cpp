/*input
5
2 3 5 5

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ST
{
	ll l, r;
	ST *left;
	ST *right;
	pair<ll, ll>mx;
	ST(ll l, ll r, ll a[]): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2, a);
			right = new ST((l + r) / 2 + 1, r, a);
			mx = max(left->mx, right->mx);
		}
		else
		{
			mx = {a[l], l};
		}
	}
	pair<ll, ll>MX(ll x, ll y)
	{
		if (x <= l && r <= y)
		{
			return mx;
		}
		if (r < x || y < l)
			return { -1, -1};
		return max(left->MX(x, y), right->MX(x, y));
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll a[n + 1];
	for (ll i = 1; i < n; i++)
		cin >> a[i];
	a[n] = n + 1;
	ST medis(1, n, a);
	ll ret = 0;
	ll ans[n + 1];
	for (ll i = n; i >= 1; i--)
	{
		if (i == n)
			ans[i] = 0;
		else
		{
			ll j = medis.MX(i + 1, a[i]).second;
			ans[i] = ans[j] + (n - i) - (a[i] - j);
		}
		ret += ans[i];
	}
	cout << ret << "\n";
}/**/