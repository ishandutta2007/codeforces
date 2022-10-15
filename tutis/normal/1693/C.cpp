/*input
5 7
1 2
2 3
3 5
1 4
4 3
4 5
3 1

*/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	if (abs(x) >= mod)
		x %= mod;
	if (x < 0)
		x += mod;
	if (abs(y) >= mod - 1)
		y %= mod - 1;
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y != 0)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int>adj[n + 1];
	vector<int>adj1[n + 1];
	for (int i = 0; i < m; i++)
	{
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj1[u].push_back(v);
	}
	int d[n + 1];
	int infi = n + m + 100;
	for (int i = 0; i <= n; i++)
		d[i] = infi;
	d[n] = 0;
	set<pair<int, int>>Q;
	Q.insert({0, n});
	vector<bool>vis(n, false);
	set<int>A[n + 1];
	int c[n + 1];
	for (int i = 1; i <= n; i++)
		c[i] = 0;
	while (!Q.empty())
	{
		int v = (*Q.begin()).second;
		Q.erase(Q.begin());
		vis[v] = true;
		for (int w : adj1[v])
		{
			if (vis[w] == true)
				continue;
			if (c[w] != 0)
				Q.erase({d[w], w});
			c[w]++;
			A[w].insert(d[v]);
			d[w] = min(d[w], ((int)adj[w].size()) - c[w] + (*(--A[w].end())) + 1);
			Q.insert({d[w], w});
		}
	}
	cout << d[1] << "\n";
}