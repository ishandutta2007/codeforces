/*input
2
1 2

*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>adj[505050];
ll sz[505050];
ll dp[505050];
ll n;
ll best = 1e18;
ll mn1[505050];
void dfs(int i, int p)
{
	sz[i] = 1;
	dp[i] = 1e18;
	vector<pair<ll, ll>>v;
	vector<int>child;
	vector<int>tikr;
	for (int j : adj[i])
	{
		if (j == p)
			continue;
		dfs(j, i);
		best = min(best, (n - sz[j]) * (n - sz[j]) + dp[j]);
		sz[i] += sz[j];
		child.push_back(j);
	}
	if (child.empty())
		dp[i] = 1;
	else
	{
		for (int j : child)
		{
			dp[i] = min(dp[i], dp[j] + (sz[i] - sz[j]) * (sz[i] - sz[j]));
			if (mn1[sz[j]] != 0)
			{
				best = min(best, (n - 2 * sz[j]) * (n - 2 * sz[j]) +
				           mn1[sz[j]] + dp[j]);
				if (dp[j] < mn1[sz[j]])
				{
					mn1[sz[j]] = dp[j];
				}
			}
			else
			{
				tikr.push_back(sz[j]);
				mn1[sz[j]] = dp[j];
			}
		}
	}
	for (int t = 0; t < (int)tikr.size(); t++)
	{
		int j = tikr[t];
		for (int t1 = t + 1; t1 < (int)tikr.size(); t1++)
		{
			int k = tikr[t1];
			best = min(best, (n - j - k) * (n - j - k) +
			           mn1[j] + mn1[k]);
		}
		mn1[j] = 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll r = (165464616518352ll % n) + 1;
	dfs(r, r);
	best = (best - n) / 2;
	cout << n * (n - 1) - best << "\n";
}