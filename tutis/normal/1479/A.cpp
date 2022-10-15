/*input
5
3
2
1
4
5

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
	int n;
	cin >> n;
	int lo = 1;
	int hi = n;
	while (lo <= hi)
	{
		if (lo == hi)
		{
			cout << "! " << lo << endl;
			return 0;
		}
		int m = (lo + hi) / 2;
		int m1 = m + 1;
		assert(m1 <= hi);
		cout << "? " << m << endl;
		cout << "? " << m1 << endl;
		int vm, vm1;
		cin >> vm >> vm1;
		if (vm <= vm1)
			hi = m;
		else
			lo = m + 1;
	}
}