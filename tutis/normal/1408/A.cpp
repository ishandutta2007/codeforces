/*input
5
3
1 1 1
2 2 2
3 3 3
4
1 2 1 2
2 1 2 1
3 4 3 4
7
1 3 3 1 1 1 1
2 4 4 3 2 2 4
4 2 2 2 4 4 2
3
1 2 1
2 3 3
3 1 2
10
1 1 1 2 2 2 3 3 3 1
2 2 2 3 3 3 1 1 1 2
3 3 3 1 1 1 2 2 2 3
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
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
		int n;
		cin >> n;
		vector<int>x[3];
		for (int i = 0; i < 3; i++)
		{
			x[i] = vector<int>(n);
			for (int j = 0; j < n; j++)
				cin >> x[i][j];
		}
		vector<int>p = x[0];
		for (int i = 0; i < n; i++)
		{
			for (int t : {0, 1, 2})
			{
				p[i] = x[t][i];
				if (p[i] != p[(i + 1) % n] && p[i] != p[(i - 1 + n) % n])
					break;
			}
		}
		for (int i : p)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}