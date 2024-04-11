/***
5
1 5 4 3 2
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<ll N>
struct DSU
{
	ll sz[N];
	ll pa[N];
	ll rk[N];
	DSU()
	{
		for (ll i = 0; i < N; i++)
		{
			sz[i] = 1;
			pa[i] = i;
			rk[i] = 0;
		}
	}
	ll root(ll i)
	{
		if (i == pa[i])
			return i;
		pa[i] = root(pa[i]);
		return pa[i];
	}
	ll &size(ll i)
	{
		return sz[root(i)];
	}
	ll &rank(ll i)
	{
		return rk[root(i)];
	}
	bool merge(ll i, ll j)
	{
		if (root(i) == root(j))
			return false;
		if (rank(i) > rank(j))
			swap(i, j);
		// i < j
		bool x = (rank(i) == rank(j));
		size(j) += size(i);
		pa[root(i)] = root(j);
		rank(j) += x;
		return true;
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	DSU<110000>X;
	ll p[n + 1];
	for (ll i = 1; i <= n; i++)
	{
		cin >> p[i];
		X.merge(i, p[i]);
	}
	ll ans = 0;
	vector<ll>Y;
	for (ll i = 1; i <= n; i++)
		if (X.pa[i] == i)
			Y.push_back(X.size(i));
	sort(Y.begin(), Y.end());
	if (Y.size() >= 2)
	{
		ll a = Y.back();
		Y.pop_back();
		ll b = Y.back();
		Y.pop_back();
		Y.push_back(a + b);
	}
	for (ll i : Y)
		ans += (i) * (i);
	cout << ans;
}