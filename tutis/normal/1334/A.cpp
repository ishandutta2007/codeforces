/*input
6
3
0 0
1 1
1 2
2
1 0
1000 3
4
10 1
15 2
10 2
15 2
1
765 432
2
4 4
4 3
5
0 0
1 0
1 0
1 0
1 0
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
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int x = 0;
		int y = 0;
		bool ok = true;
		while (n--)
		{
			int a, b;
			cin >> a >> b;
			if (a < x)
				ok = false;
			if (b < y || b > y + (a - x))
				ok = false;
			x = a;
			y = b;
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}



	return 0;
}