/*input
0
0
0
1
-1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
pair<ll, ll>ask(vector<ll>x)
{
	while (x.back() > 10004205361450474)
		x.pop_back();
	if (x.empty())
		x.push_back(30);
	cout << x.size() << " ";
	for (ll i : x)
		cout << i << " ";
	cout << "\n" << flush;
	ll v;
	cin >> v;
	if (v < 0)
	{
		exit(0);
	}
	v--;
	if (v < 0)
		return {1, x.front() - 1};
	if (v >= x.size() - 1)
		return {x.back() + 1, 10004205361450474};
	return {x[v] + 1, x[v + 1] - 1};
}
map<pair<ll, ll>, ll>XXX;
ll r(ll l, ll k)
{
	if (k == 1)
		return XXX[ {l, k}] = l + min(l, 10000ll) - 1;
	if (l >= 10000)
	{
		ll sz[10];
		sz[1] = 10000ll;
		for (ll i = 2; i <= 5; i++)
			sz[i] = (sz[i - 1] + 1) * 10000ll + sz[i - 1];
		return l + sz[k] - 1;
	}
	if (XXX.count({l, k}))
		return XXX[ {l, k}];
	ll a = l;
	ll R = l - 1;
	while (a--)
	{
		R = r(R + 1, k - 1);
		R++;
	}
	R = r(R + 1, k - 1);
	return XXX[ {l, k}] = R;
}
pair<ll, ll>dalink(ll lo, ll k)
{
	vector<ll>x;
	if (k > 1)
	{
		ll c = min(lo, 10000ll);
		while (c--)
		{
			x.push_back(r(lo, k - 1) + 1);
			lo = x.back() + 1;
		}
	}
	else
	{
		ll c = min(lo, 10000ll);
		while (c--)
		{
			x.push_back(lo);
			lo++;
		}
	}
	return ask(x);
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	pair<ll, ll>x = {1, 10004205361450474};
	ll ej = 5;
	while (true)
	{
		pair<ll, ll>y = dalink(x.first, ej);
		x.first = max(y.first, x.first);
		x.second = min(y.second, x.second);
		ej--;
	}
}