/*input
3
0 2
4 2
2 0
2 4
1 0
2 0
4 0
6 0
1 6
2 2
2 5
4 1
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
//using ull = __uint128_t;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int a[4], b[4];
		for (int i = 0; i < 4; i++)
			cin >> a[i] >> b[i];
		ll ret = 1e18;
		int p[4];
		iota(p, p + 4, 0);
		do
		{
			for (int x : a)
				for (int y : b)
					for (int dx : { -1, 1})
						for (int dy : { -1, 1})
						{
							auto f = [&](int d)
							{
								return 1ll * abs(a[p[0]] - x) + abs(b[p[0]] - y)
								       + abs(a[p[1]] * dx - x * dx - d) + abs(b[p[1]] - y)
								       + abs(a[p[2]] - x) + abs(b[p[2]] * dy - y * dy - d)
								       + abs(a[p[3]] * dx - x * dx - d) + abs(b[p[3]] * dy - y * dy - d);
							};
							// vector<int>D = {a[p[1]] * dx - x * dx, b[p[2]] * dy - y * dy, a[p[3]] * dx - x * dx, b[p[3]] * dy - y * dy };
							// sort(D.begin(), D.end());
							ret = min(ret, f(a[p[1]] * dx - x * dx));
							ret = min(ret, f(b[p[2]] * dy - y * dy));
						}

		} while (next_permutation(p, p + 4));
		cout << ret << "\n";
	}
}