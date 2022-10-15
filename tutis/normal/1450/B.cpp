/*input
3
3 2
0 0
3 3
1 1
3 3
6 7
8 8
6 9
4 1
0 0
0 1
0 2
0 3

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, less<T>, null_type, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int x[n], y[n];
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		int ans = -1;
		for (int i = 0; i < n; i++)
		{
			bool ok = true;
			for (int j = 0; j < n; j++)
				if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k)
					ok = false;
			if (ok)
				ans = 1;
		}
		cout << ans << "\n";
	}

}