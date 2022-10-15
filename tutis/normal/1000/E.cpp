/*input
4 3
1 2
4 3
3 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;
vector<int>adj[400009];
int mark[400009];
int R[400009];
int Num[400009];
int dabar = 1;
set<pair<int, int>>bridges;
int dfs(int i, int p)
{
	if (mark[i])
		return R[i];
	if (Num[i] == 0)
		Num[i] = dabar++;
	R[i] = Num[i];
	mark[i] = true;
	for (int j : adj[i])
	{
		if (j == p)
			continue;
		if (dfs(j, i) > Num[i])
		{
			bridges.insert(make_pair(i, j));
		}
		R[i] = min(R[i], dfs(j, i));
	}
	return R[i];
}
int C[400009];
int A_[400009];
int B_[400009];
int dfs(int i)
{
	if (C[i] == 0)
		C[i] = i;
	for (int j : adj[i])
	{
		if (bridges.count(make_pair(i, j)) || bridges.count(make_pair(j, i)))
			continue;
		if (C[j] == 0)
		{
			C[j] = C[i];
			dfs(j);
		}
	}
}
set<int>kaim[400009];
int D[400009];
int gylis[400009];
int ans = 0;
void dfss(int i, int p)
{
	gylis[i] = 0;
	for (int j : kaim[i])
	{
		if (j == p)
			continue;
		dfss(j, i);
		ans = max(ans, gylis[i] + gylis[j] + 1);
		gylis[i] = max(gylis[i], gylis[j] + 1);
	}
	ans = max(ans, gylis[i]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	for (int i = 1; i <= N; i++)
		if (C[i] == 0)
			dfs(i);
	if (bridges.size() == 0)
	{
		cout << "0\n";
		return 0;
	}
	int sakn = 0;
	for (pair<int, int>i : bridges)
	{
		kaim[C[i.first]].insert(C[i.second]);
		kaim[C[i.second]].insert(C[i.first]);
		sakn = C[i.first];
	}
	dfss(sakn, sakn);

	cout << ans << "\n";


}