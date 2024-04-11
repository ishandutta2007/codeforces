/*input
5
3 4
0 0 0 0
0 1 0 0
0 0 0 0
2 2
3 0
0 0
2 2
0 0
0 0
2 3
0 0 0
0 4 0
4 4
0 0 0 0
0 2 0 1
0 0 0 0
0 0 0 0
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
		int n, m;
		cin >> n >> m;
		int a[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		bool ok = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				int k = 4;
				if (i == 0)
					k--;
				if (i == n - 1)
					k--;
				if (j == 0)
					k--;
				if (j == m - 1)
					k--;
				if (a[i][j] > k)
					ok = false;
				else
					a[i][j] = k;
			}
		if (ok)
		{
			cout << "YES\n";
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << a[i][j] << " ";
				}
				cout << "\n";
			}
		}
		else
			cout << "NO\n";
	}



	return 0;
}