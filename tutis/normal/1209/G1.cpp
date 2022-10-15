/*input
7 0
3 3 1 3 2 1 2
*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll pa[202020];
ll root(ll x)
{
	if (x == pa[x])
		return x;
	return pa[x] = root(pa[x]);
}
ll x[202020];
ll y[202020];
void merge(ll a, ll b)
{
	a = root(a);
	b = root(b);
	if (a == b)
		return;
	x[a] = x[b] = min(x[a], x[b]);
	y[a] = y[b] = max(y[a], y[b]);
	pa[a] = b;
}
ll l[202020];
ll r[202020];
int main()
{
	iota(pa, pa + 202020, 0);
	iota(x, x + 202020, 0);
	iota(y, y + 202020, 0);
	fill_n(l, 202020, -1);
	ios_base::sync_with_stdio(false);
	ll n, q;
	cin >> n >> q;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < n; i++)
	{
		r[a[i]] = i;
		if (l[a[i]] == -1)
			l[a[i]] = i;
	}
	for (ll i = 0; i < n; i++)
	{
		while (y[root(i)] < r[a[i]])
		{
			merge(y[root(i)], y[root(i)] + 1);
		}
		while (x[root(i)] > l[a[i]])
		{
			merge(x[root(i)], x[root(i)] - 1);
		}
	}
	vector<ll>gr[n];
	for (ll i = 0; i < n; i++)
		gr[root(i)].push_back(i);
	ll ans = n;
	map<ll, ll>M;
	for (ll i = 0; i < n; i++)
	{
		ll k = 0;
		for (ll j : gr[i])
		{
			M[a[j]]++;
			k = max(k, M[a[j]]);
		}
		ans -= k;
	}
	cout << ans << "\n";
}