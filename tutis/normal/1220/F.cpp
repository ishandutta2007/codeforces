/*input
10
7 5 1 6 10 3 4 8 9 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct ST
{
	int l, r;
	int lazy = 0;
	int mx = 0;
	ST *left, *right;
	ST(int l, int r): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
		}
	}
	void fix()
	{
		mx += lazy;
		if (l < r)
		{
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy = 0;
	}
	void set(int i, int w)
	{
		fix();
		if (l < r)
		{
			if (i <= (l + r) / 2)
				left->set(i, w);
			else
				right->set(i, w);
			mx = max(left->mx, right->mx);
		}
		else
		{
			mx = w;
		}
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
		mx = max(left->mx, right->mx);
	}
	int get(int i)
	{
		fix();
		if (l < r)
		{
			if (i <= (l + r) / 2)
				return left->get(i);
			else
				return right->get(i);
		}
		else
		{
			return mx;
		}
	}
} medis(0, 201010);
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	int p[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
		p[a[i]] = i;
	}
	int ne[n];
	int pr[n];
	pr[0] = p[0];
	ne[0] = p[0];
	set<int>V;
	int g[n];
	g[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int id = p[i];
		if (i != 0)
		{
			auto it = V.lower_bound(id);
			if (it == V.end())
				it = V.begin();
			ne[i] = *it;
			if (it != V.begin())
			{
				it--;
			}
			else
				it = --V.end();
			pr[i] = *it;
			g[i] = g[a[pr[i]]] + 1;
		}
		V.insert(id);
	}
	pair<int, int>ans = {1e6, 1e6};
	for (int i = 0; i < n; i++)
	{
		int l = (pr[a[i]] + 1) % n;
		int r = (ne[a[i]] + n - 1) % n;
		if (a[i] == 0)
		{
			l = 0;
			r = n - 1;
		}
		if (l > i)
			l = 0;
		if (r < i)
			r = n - 1;
		medis.add(l, r, 1);
		medis.add(i, i, -1);
	}
	medis.fix();
	ans = min(ans, {medis.mx, 0});
	deque<int>b;
	for (int i = 0; i < n; i++)
		b.push_back(a[i]);
	for (int k = 1; k < n; k++)
	{
		b.push_back(b.front());
		b.pop_front();
		int v = a[k - 1];
		if (v != 0)
		{
			int j = ne[v];
			int i = p[v];
			assert(i == k - 1);
			if (i <= j)
			{
				medis.add(i + 1, j - 1, -1);
			}
			else
			{
				medis.add(i + 1, n - 1, -1);
				medis.add(0, j - 1, -1);
			}
			j = pr[v];
			if (j <= i)
			{
				medis.add(j + 1, i - 1, 1);
			}
			else
			{
				medis.add(j + 1, n - 1, 1);
				medis.add(0, i - 1, 1);
			}
			medis.set(i, g[v]);
		}
		ans = min(ans, {medis.mx + medis.lazy, k});
	}
	cout << ans.first + 1 << " " << ans.second << "\n";
}