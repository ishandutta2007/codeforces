/*input
5

3

4


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
mt19937_64 rng(1234);
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
int ask(int l, int r)
{
	cout << "? " << l << " " << r << endl;
	int x;
	cin >> x;
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int l = 1;
	int r = n;
	int m2 = ask(l, r);
	while (r - l + 1 > 2)
	{
		int v = (l + r) / 2;
		if (m2 <= v)
		{
			int mm = ask(l, v);
			if (mm == m2)
			{
				r = v;
			}
			else
			{
				l = v;
				m2 = ask(l, r);
			}
		}
		else
		{
			int mm = ask(v, r);
			if (mm == m2)
			{
				l = v;
			}
			else
			{
				r = v;
				m2 = ask(l, r);
			}
		}
	}
	assert(l < r);
	cout << "! " << (l^r^m2) << endl;
}