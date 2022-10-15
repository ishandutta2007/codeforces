/*input
1 3
2 8 6
1 3 6 7 9
1 3 6 4 3
1 5 7 4 1 3 8
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int kk[1 << 9];
vector<int>p[1 << 9];
int kkk[1 << 9];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		int k;
		cin >> k;
		while (k--)
		{
			int j;
			cin >> j;
			x |= (1 << (j - 1));
		}
		kkk[x]++;
	}
	for (int x = 0; x < (1 << 9); x++)
		for (int y = 0; y < (1 << 9); y++)
			if ((y & x) == x)
				kk[y] += kkk[x];
	int c[m];
	int x[m];
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> c[i] >> k;
		x[i] = 0;
		while (k--)
		{
			int j;
			cin >> j;
			x[i] |= (1 << (j - 1));
		}
		p[x[i]].push_back(i);
	}
	pair<pair<int, int>, pair<int, int>>ans = {{ 1e9, 0}, {0, 0}};
	vector<int>gal;
	for (int m1 = 0; m1 < (1 << 9); m1++)
	{
		sort(p[m1].begin(), p[m1].end(), [&](int a, int b) {return c[a] < c[b];});
		while (p[m1].size() > 2)
			p[m1].pop_back();
		if (p[m1].size() >= 1)
			gal.push_back(p[m1][0]);
		if (p[m1].size() == 2)
		{
			int i = p[m1][0];
			int j = p[m1][1];
			int kiek = kk[x[i] | x[j]];
			int cost = c[i] + c[j];
			ans = min(ans, {{ -kiek, cost}, {i, j}});
		}
	}
	for (int a = 0; a < (int)gal.size(); a++)
	{
		int i = gal[a];
		for (int b = 0; b < a; b++)
		{
			int j = gal[b];
			int kiek = kk[x[i] | x[j]];
			int cost = c[i] + c[j];
			ans = min(ans, {{ -kiek, cost}, {i, j}});
		}
	}
	cout << ans.second.first + 1 << " " << ans.second.second + 1 << "\n";
}