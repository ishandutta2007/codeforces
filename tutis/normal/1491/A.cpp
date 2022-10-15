/*input
5 5
1 1 0 1 0
2 3
1 2
2 3
2 1
2 5

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
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i];
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int x;
			cin >> x;
			sum -= a[x];
			a[x] = 1 - a[x];
			sum += a[x];
		}
		else
		{
			int k;
			cin >> k;
			if (sum >= k)
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
}