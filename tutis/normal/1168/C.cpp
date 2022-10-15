/*input
5 3
1 3 0 2 1
1 3
2 4
1 4
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
bool ans[303030];
int a[303030];
vector<pair<int, int>>query[303030];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		query[x].push_back({y, i});
	}
	vector<int>keiciasi[20];
	for (int l = n; l >= 1; l--)
	{
		vector<int>ii;
		vector<int>kk;
		for (int i = 0; i < 20; i++)
		{
			if ((a[l] & (1 << i)) > 0)
			{
				for (int j : keiciasi[i])
				{
					kk.push_back(j);
				}
				ii.push_back(i);
			}
		}
		if (!ii.empty())
		{
			stable_sort(kk.begin(), kk.end());
			int x = a[l];
			vector<int>geras = {l};
			for (int i : kk)
			{
				int y = x | (a[i]);
				if (y != x)
					geras.push_back(i);
				x = y;
			}
			for (int i : ii)
				keiciasi[i] = geras;
			for (pair<int, int>y : query[l])
			{
				int x = a[l];
				for (int i : geras)
				{
					if (i > y.first)
						break;
					x |= a[i];
				}
				if ((x & a[y.first]) > 0)
					ans[y.second] = true;
			}
		}
	}
	for (int i = 0; i < q; i++)
		if (ans[i])
			cout << "Shi\n";
		else
			cout << "Fou\n";
}