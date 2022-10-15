/*input
6
1 2
2 3
2 4
1 5
5 6

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>adj[100001];
void dfs(int i, int p)
{
	auto it = find(adj[i].begin(), adj[i].end(), p);
	if (it != adj[i].end())
		adj[i].erase(it);
	for (int j : adj[i])
	{
		dfs(j, i);
	}
}
int k;
pair<int, int> dp[101010];
void dfs1(int i)
{
	dp[i] = {0, 1};
	bool galim = false;
	for (int j : adj[i])
	{
		dfs1(j);
		dp[i].first += dp[j].first;
		galim |= dp[i].second + dp[j].second >= k;
		dp[i].second = max(dp[i].second, dp[j].second + 1);
	}
	if (galim || dp[i].second >= k)
	{
		dp[i].first++;
		dp[i].second = 0;
	}
}
map<int, int>M;
int eval(int x)
{
	auto it = M.upper_bound(x);
	if (it != M.end() && it != M.begin())
	{
		auto it1 = it;
		it1--;
		if (it1->second == it->second)
			return it->second;
	}
	k = x;
	dfs1(1);
	return M[x] = dp[1].first;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 1);
	int ans[n + 1];
	vector<int>p;
	for (int a = 1; a <= n; a++)
		p.push_back(a);
	shuffle(p.begin(), p.end(), mt19937_64(1564));
	for (int i : p)
	{
		ans[i] = eval(i);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << "\n";
	}
}