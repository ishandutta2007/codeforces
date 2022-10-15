/*input
1
4 4 1 3
1 2
2 3
3 4
4 1
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct DSU
{
	vector<ll>pa;
	vector<ll>sz;
	DSU(ll n, ll a, ll b)
	{
		pa = vector<ll>(n);
		sz = vector<ll>(n, 1);
		sz[a] = sz[b] = 0;
		for (ll i = 0; i < n; i++)
			pa[i] = i;
	}
	ll root(ll i)
	{
		if (i == pa[i])
			return i;
		return pa[i] = root(pa[i]);
	}
	void merge(ll x, ll y)
	{
		x = root(x);
		y = root(y);
		if (x == y)
			return;
		if (sz[x] > sz[y])
			swap(x, y);
		pa[x] = y;
		sz[y] += sz[x];
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, m, a, b;
		cin >> n >> m >> a >> b;
		vector<int>adj[n + 1];
		while (m--)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		vector<bool>A(n + 1, false);
		vector<bool>B(n + 1, false);
		function<void(int)> dfs1 = [&](int i)
		{
			if (A[i])
				return;
			A[i] = true;
			for (int j : adj[i])
			{
				if (j != b)
					dfs1(j);
			}
		};
		function<void(int)> dfs2 = [&](int i)
		{
			if (B[i])
				return;
			B[i] = true;
			for (int j : adj[i])
			{
				if (j != a)
					dfs2(j);
			}
		};
		dfs1(a);
		dfs2(b);
		B[a] = true;
		A[b] = true;
		ll k1 = 0;
		ll k2 = 0;
		for (int i = 1; i <= n; i++)
			if (A[i] == false)
				k1++;
		for (int i = 1; i <= n; i++)
			if (B[i] == false)
				k2++;
		cout << k1*k2 << "\n";
	}
}