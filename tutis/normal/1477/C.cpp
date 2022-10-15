/*input
5
0 0
5 0
4 2
2 1
3 0

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
const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	ll x[n], y[n];
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	int p[n];
	iota(p, p + n, 0);
	while (true)
	{
		shuffle(p, p + n, rng);
		for (int i = 2; i <= n; i++)
		{
			if (i == n)
			{
				for (int i = 0; i < n; i++)
					cout << p[i] + 1 << " ";
				return 0;
			}
			bool ok = false;
			for (int j = i; j < n; j++)
				if ((x[p[j]] - x[p[i - 1]]) * (x[p[i - 1]] - x[p[i - 2]])
				        + (y[p[j]] - y[p[i - 1]]) * (y[p[i - 1]] - y[p[i - 2]]) < 0)
				{
					ok = true;
					swap(p[i], p[j]);
					break;
				}
			if (!ok)
				break;
		}
	}
}