/*input
7 5
1 2 1
3 2 3
2 4 1
4 5 2
5 7 4
3 6 2
5 2 3 4 1

*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int pa[202020];
ll sz[202020];
int root(int i)
{
	if (i == pa[i])
		return i;
	return pa[i] = root(pa[i]);
}
ll ret = 0;
void merge(int a, int b)
{
	a = root(a);
	b = root(b);
	ret -= sz[a] * (sz[a] - 1) / 2;
	ret -= sz[b] * (sz[b] - 1) / 2;
	sz[a] += sz[b];
	pa[b] = a;
	ret += sz[a] * (sz[a] - 1) / 2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		pa[i] = i;
		sz[i] = 1;
	}
	vector<pair<int, pair<int, int>>>E;
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		E.push_back({w, {u, v}});
	}
	pair<int, int>Q[m];
	for (int i = 0; i < m; i++)
	{
		cin >> Q[i].first;
		Q[i].second = i;
	}
	sort(E.begin(), E.end(), greater<pair<int, pair<int, int>>>());
	sort(Q, Q + m);
	ll ans[m];
	for (pair<int, int>q : Q)
	{
		while (!E.empty() && E.back().first <= q.first)
		{
			merge(E.back().second.first, E.back().second.second);
			E.pop_back();
		}
		ans[q.second] = ret;
	}
	for (int i = 0; i < m; i++)
		cout << ans[i] << " ";
}