/***
10 0
1 2 3 4 5 6 7 8 9 10
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[100009];
struct dsu
{
	static const ll N = 100009;
	ll pa[N];
	ll sz[N];
	ll co[N];
	dsu()
	{
		for (ll i = 0; i < N; i++)
		{
			co[i] = c[i];
			sz[i] = 1;
			pa[i] = i;
		}
	}
	ll root(ll i)
	{
		if (i == pa[i])
			return pa[i];
		return pa[i] = root(pa[i]);
	}
	ll &size(ll i)
	{
		return sz[root(i)];
	}
	ll &cost(ll i)
	{
		return co[root(i)];
	}
	void merge(ll a, ll b)
	{
		if (root(a) == root(b))
			return;
		if (size(a) > size(b))
			swap(a, b);
		cost(b) = min(cost(a), cost(b));
		size(b) += size(a);
		pa[root(a)] = root(b);
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
		cin >> c[i];
	dsu X;
	while (m--)
	{
		ll x, y;
		cin >> x >> y;
		X.merge(x, y);
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
		if (i == X.root(i))
			ans += X.cost(i);
	cout << ans;
}