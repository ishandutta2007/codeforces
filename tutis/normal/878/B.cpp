/*input
5 3 2
1 1 2 1 1 1 1 2 1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll answer(ll l, ll r, ll a[], ll k, ll m, bool x = true)
{
	if (l > r)
		return 0;
	if (x)
	{
		stack<pair<ll, ll>>X;
		for (ll i = l; i <= r; i++)
		{
			while (!X.empty() && X.top().second >= k)
			{
				X.top().second -= k;
				if (X.top().second == 0)
					X.pop();
			}
			if (X.empty() || X.top().first != a[i])
				X.push({a[i], 1});
			else
				X.top().second++;
			while (!X.empty() && X.top().second >= k)
			{
				X.top().second -= k;
				if (X.top().second == 0)
					X.pop();
			}
		}
		ll i = l;
		while (!X.empty())
		{
			pair<ll, ll>c = X.top();
			X.pop();
			while (c.second--)
			{
				a[i++] = c.first;
			}
		}
		if (m == 1)
			return (i - l);
		return answer(l, i - 1, a, k, m, false);
	}
	ll c = l;
	while (c + 1 <= r && a[c + 1] == a[l])
		c++;
	ll d = r;
	while (d - 1 >= l && a[d - 1] == a[r])
		d--;
	if (d == l)
		return ((r - l + 1) * m) % k;
	if (a[l] != a[r])
	{
		return m * (r - l + 1) - (r - d + 1) / k - (c - l + 1) / k;
	}
	if (((r - d + 1) + (c - l + 1)) % k != 0)
	{
		return (r - l + 1) * m - k * ((m - 1) * (((r - d + 1) + (c - l + 1)) / k) - (r - d + 1) / k - (c - l + 1) / k);
	}
	ll C = answer(c + 1, d - 1, a, k, m, false);
	if (C == 0)
		return C + ((r - d + 1) + (c - l + 1)) % k;
	return C + ((r - d + 1) + (c - l + 1));
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, k, m;
	cin >> n >> k >> m;
	ll a[n];
	for (ll &i : a)
		cin >> i;
	cout << answer(0, n - 1, a, k, m) << "\n";
}