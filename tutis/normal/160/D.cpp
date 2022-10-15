/*input
4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct DSU
{
	int* pa;
	int N;
	DSU(int n)
	{
		n += 1000;
		pa = new int[n];
		fill_n(pa, n, -1);
		N = n;
	}
	void reset()
	{
		fill_n(pa, N, -1);
	}
	int root(int i)
	{
		if (pa[i] < 0)
			return i;
		return pa[i] = root(pa[i]);
	}
	bool same(int a, int b)
	{
		return root(a) == root(b);
	}
	int size(int i)
	{
		return -pa[root(i)];
	}
	void merge(int a, int b)
	{
		a = root(a);
		b = root(b);
		if (a != b)
		{
			if (pa[a] >= pa[b])
			{
				pa[b] += pa[a];
				pa[a] = b;
			}
			else
			{
				pa[a] += pa[b];
				pa[b] = a;
			}
		}
	}
};
vector<pair<pair<int, int>, int>>A[1000001];
string ans[101010];
vector<pair<int, int>>adj[101010];
int timer = 2;
int pirmas[101010];
int maxi[101010];
void dfs(int i, int negalima)
{
	if (pirmas[i] != 0)
		return;
	pirmas[i] = maxi[i] = timer++;
	for (pair<int, int>j : adj[i])
	{
		if (j.second == negalima)
			continue;
		dfs(j.first, j.second);
		if (pirmas[j.first] > pirmas[i])
		{
			maxi[i] = min(maxi[i], maxi[j.first]);
			if (maxi[j.first] > pirmas[i])
			{
				ans[j.second] = "any";
			}
		}
		else
		{
			maxi[i] = min(maxi[i], pirmas[j.first]);
		}
	}
}
int main()
{
	clock_t pradzia = clock();
	srand(pradzia);
	int n, m;
	cin >> n >> m;
	int tim = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		A[w].push_back({{a, b}, tim++});
	}
	fill_n(ans, m, "at least one");
	DSU X(n + 1);
	for (int w = 1; w <= 1000000; w++)
	{
		for (pair<pair<int, int>, int>i : A[w])
		{
			if (X.same(i.first.first, i.first.second))
				ans[i.second] = "none";
			else
			{
				adj[X.root(i.first.first)].push_back({X.root(i.first.second), i.second});
				adj[X.root(i.first.second)].push_back({X.root(i.first.first), i.second});
			}
		}
		for (pair<pair<int, int>, int>i : A[w])
		{
			if (X.same(i.first.first, i.first.second))
				ans[i.second] = "none";
			else
			{
				if (pirmas[X.root(i.first.first)] == 0)
				{
					dfs(X.root(i.first.first), -1015);
				}
			}
		}
		for (pair<pair<int, int>, int>i : A[w])
			X.merge(i.first.first, i.first.second);
		for (pair<pair<int, int>, int>i : A[w])
		{
			adj[X.root(i.first.first)].clear();
			adj[X.root(i.first.second)].clear();
			for (int c : {i.first.first, i.first.second})
			{
				pirmas[X.root(c)] = 0;
				maxi[X.root(c)] = 0;
			}
		}
	}

	for (int t = 0; t < tim; t++)
		cout << ans[t] << "\n";
}