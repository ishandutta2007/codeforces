/*input
6
3
2 3 4
2
3 3
3
-1 -1 -1
3
3 4 -1
1
2
4
4 -1 4 5
*/
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st
{
	int l, r;
	st *left;
	st *right;
	pair<int, int>mn;
	int lazy = 0;
	st(int l, int r): l(l), r(r)
	{
		if (l < r)
		{
			left = new st(l, (l + r) / 2);
			right = new st((l + r) / 2 + 1, r);
		}
		mn = {0, l};
	}
	void fix()
	{
		mn.first += lazy;
		if (l < r)
		{
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy = 0;
	}
	void add(int x, int y, int w)
	{
		fix();
		if (x <= l && r <= y)
		{
			lazy += w;
			return fix();
		}
		if (r < x || y < l)
			return;
		left->add(x, y, w);
		right->add(x, y, w);
		mn = min(left->mn, right->mn);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int nxt[n + 1];
		for (int i = 1; i <= n; i++)
		{
			cin >> nxt[i];
		}
		int a[n + 1];
		vector<pair<int, int>>k[n + 1];
		for (int i = 1; i <= n; i++)
		{
			if (nxt[i] != -1)
			{
				if (nxt[i] != n + 1)
				{
					k[nxt[i]].push_back({i, i});
				}
				if (nxt[i] != i + 1)
				{
					k[i].push_back({i + 1, nxt[i] - 1});
				}
			}
		}
		st medis(1, n);
		int mx = n;
		for (int i = 1; i <= n; i++)
		{
			for (pair<int, int>a : k[i])
			{
				medis.add(a.first, a.second, 1);
			}
		}
		while (medis.mn.first == 0)
		{
			int i = medis.mn.second;
			medis.add(i, i, n + 100);
			for (pair<int, int>a : k[i])
			{
				medis.add(a.first, a.second, -1);
			}
			a[i] = mx;
			mx--;
		}
		if (mx != 0)
		{
			cout << "-1\n";
		}
		else
		{
			for (int i = 1; i <= n; i++)
				cout << a[i] << " ";
			cout << "\n";
		}
	}
}