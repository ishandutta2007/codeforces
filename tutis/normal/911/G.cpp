/*input
5
1 2 3 4 5
3
3 5 3 5
1 5 5 1
1 5 1 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct ST
{
	int l, r;
	vector<int>X;
	ST *left;
	ST *right;
	ST(int l, int r): l(l), r(r)
	{
		X = vector<int>(101);
		iota(X.begin(), X.end(), 0);
		if (l < r)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
		}
	}
	void set(int i, int x, int y)
	{
		if (!(l <= i && i <= r))
			return;
		if (l == r)
		{
			X[x] = y;
			return;
		}
		left->set(i, x, y);
		right->set(i, x, y);
		X = left->X;
		for (int &i : X)
			i = right->X[i];
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int q;
	cin >> q;
	ST SegTree(1, q);
	vector<pair<int, pair<int, int>>>idek[n + 2];
	for (int i = 1; i <= q; i++)
	{
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		idek[l].push_back({i, {x, y}});
		idek[r + 1].push_back({i, {x, x}});
	}
	for (int i = 1; i <= n; i++)
	{
		for (pair<int, pair<int, int>> c : idek[i])
		{
			SegTree.set(c.first, c.second.first, c.second.second);
		}
		cout << SegTree.X[a[i]] << " ";
	}
}