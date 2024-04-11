/***
1
10000
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[5009];
ll pr[5009];
ll s(ll a, ll b)
{
	return pr[b] - pr[a];
}
#define INF ll(-6e13)
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	pr[0] = 0;
	for (ll i = 1; i <= n; i++)
	{
		pr[i] = pr[i - 1] + a[i - 1];
	}
	pair<ll, ll> D1[n + 1];
	pair<ll, ll> D2[n + 1];
	fill_n(D1, n + 1, make_pair(INF, -3));
	fill_n(D2, n + 1, make_pair(INF, -3));
	for (ll d0 = 0; d0 <= n; d0++)
	{
		for (ll i = d0; i <= n; i++)
		{
			if (D1[i].first <= s(0, d0) - s(d0, i))
			{
				D1[i].first = s(0, d0) - s(d0, i);
				D1[i].second = d0;
			}
		}
	}
	for (ll i = 0; i <= n; i++)
	{
		for (ll d2 = i; d2 <= n; d2++)
		{
			if (D2[i].first <= s(i, d2) - s(d2, n))
			{
				D2[i].first = s(i, d2) - s(d2, n);
				D2[i].second = d2;
			}
		}
	}
	ll ans = INF;
	ll a = 0, b = 0, c = 0;
	for (ll d1 = 0; d1 <= n; d1++)
	{
		if (ans <= D1[d1].first + D2[d1].first)
		{
			ans = D1[d1].first + D2[d1].first;
			a = D1[d1].second;
			b = d1;
			c = D2[d1].second;
		}
	}
	cout << a << " " << b << " " << c;
}