/*input
6
1 3
2 3
3 4
4 5
4 6

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 gen(12938712983ll);
vector<int>adj[101010];
int n;
int sz[101010];
pair<int, int>mini = {1e9, 1};
void dfs(int i, int p)
{
	int maxi = 0;
	sz[i] = 1;
	for (int j : adj[i])
	{
		if (j == p)
			continue;
		dfs(j, i);
		sz[i] += sz[j];
		maxi = max(maxi, sz[j]);
	}
	maxi = max(maxi, n - sz[i]);
	mini = min(mini, {maxi, i});
}
deque<int>gal;
void dfs1(int i, int p)
{
	if (adj[i].size() == 1)
		gal.push_back(i);
	for (int j : adj[i])
	{
		if (j == p)
			continue;
		dfs1(j, i);
	}
}
int DD[101010];
void check(int r)
{
	int D[n + 3];
	fill_n(D, n + 3, n + 3);
	D[r] = 0;
	queue<int>Q;
	Q.push(r);
	while (!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		DD[a] = D[a];
		for (int b : adj[a])
		{
			if (D[b] > D[a] + 1)
			{
				D[b] = D[a] + 1;
				Q.push(b);
			}
		}
	}
	int deg[n + 3];
	fill_n(deg, n + 3, -1);
	for (int i = 1; i <= n; i++)
	{
		if (deg[D[i]] == -1)
			deg[D[i]] = (int)adj[i].size();
		if (deg[D[i]] != (int)adj[i].size())
			return;
	}
	cout << r << "\n";
	exit(0);
}
int main()
{
	clock_t pradzia = clock();
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	int r = mini.second;
	check(r);
	dfs1(r, r);
	int kiek = 25;
	sort(gal.begin(), gal.end(), [&](int a, int b) {return DD[a] < DD[b];});
	while (gal.size() > 0)
	{
		for (int i : {gal.front(), gal.back()})
		{
			if (kiek > 0)
			{
				kiek--;
				check(i);
			}
		}
		gal.pop_front();
		if (gal.size() > 0)
			gal.pop_back();
	}
	gen = mt19937_64(clock());
	while ((clock() - pradzia) * 10 < 9 * CLOCKS_PER_SEC)
	{
		int x = gen() % 123123;
		x %= n;
		if (x < 0)x += n;
		check(x + 1);
	}
	cout << "-1\n";
}