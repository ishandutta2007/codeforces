/*input
6 5
5 0 3 1 2
1 8 9 1 3
1 2 3 4 5
9 1 0 3 7
2 3 0 6 3
6 4 1 7 0
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
pair<int, int> mx[255];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	pair<int, int> p[m];
	fill_n(mx, 255, make_pair(-1, -1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> p[j].first;
			p[j].second = j;
		}
		sort(p, p + m, greater<pair<int, int>>());
		int msk = 0;
		for (pair<int, int> vj : p)
		{
			msk ^= 1 << vj.second;
			mx[msk] = max(mx[msk], {vj.first, i});
		}
	}
	for (int i = 255; i >= 0; i--)
	{
		int x = i;
		while (x > 0)
		{
			int a = x & (-x);
			mx[i ^ a] = max(mx[i], mx[i ^ a]);
			x ^= a;
		}
	}
	pair<int, pair<int, int>>ans = { -1, {0, 0}};
	for (int i = 0; i < (1 << m); i++)
	{
		int j = ((1 << m) - 1)^i;
		ans = max(ans, {min(mx[i].first, mx[j].first), {mx[i].second, mx[j].second}});
	}
	cout << ans.second.first + 1 << " " << ans.second.second + 1 << "\n";
}