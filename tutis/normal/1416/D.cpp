/*input
5 4 6
1 2 5 4 3
1 2
2 3
1 3
4 5
1 1
2 1
2 3
1 1
1 2
1 2
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	int p[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	int a[m], b[m];
	for (int i = 0; i < m; i++)
		cin >> a[i] >> b[i];
	pair<int, int>x[q];
	int kada[m];
	fill_n(kada, m, q);
	for (int i = 0; i < q; i++)
	{
		cin >> x[i].first >> x[i].second;
		if (x[i].first == 2)
		{
			kada[x[i].second - 1] = i;
		}
	}
	int pa[n + 1];
	iota(pa, pa + (n + 1), 0);
	vector<int>ch[n + 1];
	for (int i = 1; i <= n; i++)
		ch[i] = {i};
	vector<int>C[q + 1];
	for (int i = 0; i < m; i++)
		C[kada[i]].push_back(i);
	function<int(int)>root = [&](int x)
	{
		while (x != pa[x])
			x = pa[x];
		return x;
	};
	vector<pair<int, int>>G[q + 1];
	auto merge = [&](int a, int b, int w)
	{
		a = root(a);
		b = root(b);
		if (a != b)
		{
			if (ch[a].size() > ch[b].size())
				swap(a, b);//a<=b
			for (int i : ch[a])
			{
				pa[i] = b;
				ch[b].push_back(i);
				G[w].push_back({i, a});
			}
			ch[a].clear();
		}
	};
	for (int i = q; i >= 0; i--)
	{
		for (int id : C[i])
		{
			merge(a[id], b[id], i);
		}
	}
	set<pair<int, int>, greater<pair<int, int>>>A[n + 1];
	for (int i = 1; i <= n; i++)
		A[pa[i]].insert({p[i], i});
	for (int i = 0; i < q; i++)
	{
		if (i != 0)
		{
			for (pair<int, int>k : G[i - 1])
			{
				if (p[k.first] != 0)
					A[pa[k.first]].erase({p[k.first], k.first});
				pa[k.first] = k.second;
				if (p[k.first] != 0)
					A[pa[k.first]].insert({p[k.first], k.first});
			}
		}
		if (x[i].first == 1)
		{
			int k = pa[x[i].second];
			if (A[k].empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << A[k].begin()->first << "\n";
				int j = A[k].begin()->second;
				p[j] = 0;
				A[k].erase(A[k].begin());
			}
		}
	}
	return 0;
}