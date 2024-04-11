/*input
7
5 2 4
3 1 1 2 5
5 3 4
1 1 2 1 2
4 0 4
5 5 3 3
4 1 4
2 3 2 3
6 1 2
3 2 1 1 1 1
6 2 4
3 3 2 1 1 1
6 2 6
1 1 3 2 1 1

*/
#pragma GCC optimize ("O3")
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
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, y;
		cin >> n >> x >> y;
		int b[n], a[n];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		y -= x;
		map<int, vector<int>>M;
		for (int i = 0; i < n; i++)
		{
			M[b[i]].push_back(i);
		}
		set<pair<int, int>, greater<pair<int, int>>>X;
		for (auto i : M)
			X.insert({(int)i.second.size(), i.first});
		int nera = 1;
		while (M.count(nera))
			nera++;
		fill_n(a, n, 0);
		while (x > 0)
		{
			int i = X.begin()->second;
			X.erase(X.begin());
			a[M[i].back()] = b[M[i].back()];
			M[i].pop_back();
			if (!M[i].empty())
				X.insert({M[i].size(), i});
			x--;
		}
		vector<int>xx;
		for (int i = 0; i < n; i++)
			if (a[i] == 0)
				xx.push_back(b[i]);
		sort(xx.begin(), xx.end());
		int kk = 1;
		int last = -1;
		int mx = 1;
		for (int i : xx)
		{
			if (i == last)
			{
				kk++;
				mx = max(mx, kk);
			}
			else
			{
				kk = 1;
				last = i;
			}
		}
		auto yy = xx;
		{
			rotate(yy.begin(), yy.begin() + (yy.size()) / 2, yy.end());
			map<int, vector<int>>AAA;
			for (int i = 0; i < xx.size(); i++)
			{
				if (xx[i] == yy[i] || y == 0)
					yy[i] = nera;
				else
					y--;
				AAA[xx[i]].push_back(yy[i]);
			}
			for (int i = 0; i < n; i++)
			{
				if (a[i] == 0)
				{
					a[i] = AAA[b[i]].back();
					AAA[b[i]].pop_back();
				}
			}
		}
		if (y == 0)
		{
			cout << "YES\n";
			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
			cout << "\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}