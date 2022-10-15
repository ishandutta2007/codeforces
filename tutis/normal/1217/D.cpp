/*input
3 3
1 2
2 3
3 1

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool ciklas = false;
vector<int>adj[5500];
bool zinau[5500];
bool esu[5500];
void dfs(int i)
{
	if (ciklas || zinau[i])
		return;
	if (esu[i])
	{
		ciklas = true;
	}
	esu[i] = true;
	for (int j : adj[i])
	{
		dfs(j);
	}
	zinau[i] = true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int>ans(m);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		ans[i] = 1 + (u < v);
	}
	for (int i = 1; i <= n; i++)
		dfs(i);
	if (!ciklas)
		fill(ans.begin(), ans.end(), 1);
	cout << *max_element(ans.begin(), ans.end()) << "\n";
	for (int i : ans)
		cout << i << " ";
}