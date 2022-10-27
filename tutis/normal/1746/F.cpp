/*input
10 8
1234 2 3 3 2 1 1 2 3 4
2 1 6 2
1 1 1
2 1 6 2
2 1 9 2
1 10 5
2 1 9 3
1 3 5
2 3 10 2

*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
typedef tree <
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update >
ordered_set;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	map<int, int>M;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (M.count(a[i]) == 0)
			M[a[i]] = (int)M.size();
		a[i] = M[a[i]];
	}
	pair<pair<int, int>, pair<int, int>>Q[q];
	vector<bool> ok(q);
	for (int c = 0; c < q; c++)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int i, x;
			cin >> i >> x;
			if (M.count(x) == 0)
				M[x] = (int)M.size();
			Q[c] = {{t, 0}, {i, M[x]}};
		}
		else
		{
			int l, r, k;
			cin >> l >> r >> k;
			Q[c] = {{t, k}, {l, r}};
			ok[c] = ((r - l + 1) % k) == 0;
		}
	}
	int cnt = (int)M.size();
	int r[cnt];
	ull f[n + 1];
	int x[n + 1];
	for (int t = 0; t < 30; t++)
	{
		for (int i = 0; i < cnt; i++)
			r[i] = rng() % (n + 1);
		for (int i = 1; i <= n; i++)
		{
			x[i] = a[i];
			f[i] = 0;
		}
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j += j & (-j))
				f[j] += r[x[i]];
		for (int c = 0; c < q; c++)
		{
			if (Q[c].first.first == 1)
			{
				int i = Q[c].second.first;
				int v = Q[c].second.second;
				int d = r[v] - r[x[i]];
				x[i] = v;
				for (int j = i; j <= n; j += j & (-j))
					f[j] += d;
			}
			else
			{
				int l = Q[c].second.first;
				int r = Q[c].second.second;
				int k = Q[c].first.second;
				if (ok[c])
				{
					ull s = 0;
					for (int j = r; j > 0; j -= j & (-j))
						s += f[j];
					for (int j = l - 1; j > 0; j -= j & (-j))
						s -= f[j];
					ok[c] = ok[c] & ((s % k) == 0);
				}
			}
		}
	}
	for (int c = 0; c < q; c++)
		if (Q[c].first.first == 2)
		{
			if (ok[c])
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	return 0;
}