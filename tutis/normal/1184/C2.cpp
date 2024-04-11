/*input
5 2
1 1
1 -1
-1 1
-1 -1
2 0

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct ST
{
	int l, r;
	int maxi = 0;
	int lazy = 0;
	ST *left;
	ST *right;
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
		maxi += lazy;
		if (l < r)
		{
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy = 0;
	}
	void add(int x, int y, int w)
	{
		if (x <= l && r <= y)
		{
			lazy += w;
			return fix();
		}
		fix();
		if (r < x || y < l)
			return;
		left->add(x, y, w);
		right->add(x, y, w);
		maxi = max(left->maxi, right->maxi);
	}
	int get()
	{
		return maxi + lazy;
	}
} medis(0, 6e5 + 100);
int main()
{
	int n, r;
	cin >> n >> r;
	pair<int, int>a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
		a[i] = {a[i].first - a[i].second, a[i].first + a[i].second};
	}
	r *= 2;
	map<int, int>M;
	for (int i = 0; i < n; i++)
	{
		M[a[i].second] = 0;
		M[a[i].second + r] = 0;
	}
	int timer = 0;
	for (auto &it : M)
	{
		it.second = timer++;
	}
	int ans = 0;
	sort(a, a + n);
	int i = 0;
	for (int j = 0; j < n; j++)
	{
		while (a[i].first < a[j].first - r)
		{
			medis.add(M[a[i].second], M[a[i].second + r], -1);
			i++;
		}
		medis.add(M[a[j].second], M[a[j].second + r], 1);
		ans = max(ans, medis.get());
	}
	cout << ans << "\n";
}