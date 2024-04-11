/*input
5
1 2
3 2
2 4
5 2
4
2
3 1
3
3 4 5
3
2 3 5
1
1

*/

#pragma GCC optimize ("O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(0);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int>adj[n + 1];
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int pa[n + 1][20];
	int d[n + 1];
	function<void(int, int)>dfs = [&](int i, int p)
	{
		pa[i][0] = p;
		for (int t = 1; t < 20; t++)
			pa[i][t] = pa[pa[i][t - 1]][t - 1];
		for (int j : adj[i])
		{
			if (j != p)
			{
				d[j] = d[i] + 1;
				dfs(j, i);
			}
		}
	};
	d[1] = 0;
	dfs(1, 1);
	auto lca = [&](int a, int b)->int
	{
		if (d[a] < d[b])
			swap(a, b);
		if (d[a] != d[b])
			for (int t = 19; t >= 0; t--)
				if (d[pa[a][t]] >= d[b])
					a = pa[a][t];
		if (a == b)
			return a;
		for (int t = 19; t >= 0; t--)
			if (pa[a][t] != pa[b][t])
			{
				a = pa[a][t];
				b = pa[b][t];
			}
		return pa[a][0];
	};
	int q;
	cin >> q;
	while (q--)
	{
		int k;
		cin >> k;
		vector<int> v(k);
		for (int &a : v)
			cin >> a;
		int l = *v.begin();
		for (int i : v)
			l = lca(l, i);
		auto it = find(v.begin(), v.end(), l);
		if (it != v.end())
			v.erase(it);
		if (v.empty())
		{
			cout << "YES\n";
			continue;
		}
		int i = *v.begin();
		for (int j : v)
			if (d[j] > d[i])
				i = j;
		vector<int>w = v;
		{
			vector<int>ww;
			for (int t : w)
			{
				if (lca(i, t) != t)
					ww.push_back(t);
			}
			w = ww;
		}
		if (w.empty())
			cout << "YES\n";
		else
		{
			set<int>S;
			for (int i : v)
			{
				for (int t = 19; t >= 0; t--)
					if (pa[i][t] != l && d[pa[i][t]] >= d[l])
						i = pa[i][t];
				S.insert(i);
				if (S.size() > 2)
					break;
			}
			int i = *w.begin();
			for (int j : w)
				if (d[j] > d[i])
					i = j;
			{
				vector<int>ww;
				for (int t : w)
				{
					if (lca(i, t) != t)
						ww.push_back(t);
				}
				w = ww;
			}
			if (S.size() == 2 && w.empty())
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}