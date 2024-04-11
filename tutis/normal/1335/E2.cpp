/*input
6
8
1 1 2 2 3 2 1 1
3
1 3 3
4
1 10 10 1
1
26
2
2 1
3
1 1 1


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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>x[201];
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			x[a].push_back(i);
		}
		int ans = 0;
		for (int i = 1; i <= 200; i++)
		{
			int idl[201];
			int idr[201];
			for (int j = 1; j <= 200; j++)
			{
				idl[j] = 0;
				idr[j] = (int)x[j].size() - 1;
			}
			ans = max(ans, (int)x[i].size());
			for (int l = 1; 2 * l <= (int)x[i].size(); l++)
			{
				int a = x[i][l - 1] + 1;
				int b = x[i][(int)x[i].size() - l] - 1;
				if (a <= b)
				{
					int mx = 0;
					for (int j = 1; j <= 200; j++)
					{
						if (j == i)
							continue;
						while (idr[j] >= idl[j])
						{
							if (x[j][idl[j]] < a)
								idl[j]++;
							else if (x[j][idr[j]] > b)
								idr[j]--;
							else
								break;
						}
						mx = max(mx, idr[j] - idl[j] + 1);
					}
					ans = max(ans, 2 * l + mx);
				}
			}
		}
		cout << ans << "\n";
	}



	return 0;
}