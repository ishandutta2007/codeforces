/*input
1
154873296
386592714
729641835
863725149
975314628
412968357
631457982
598236471
247189563

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
		string a[9];
		for (int i = 0; i < 9; i++)
		{
			cin >> a[i];
			for (char&c : a[i])
				if (c == '2')
					c = '1';
		}
		for (int i = 0; i < 9; i++)
			cout << a[i] << "\n";
	}



	return 0;
}