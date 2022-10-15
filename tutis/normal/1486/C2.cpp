/*input
5
3
3
2
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
	int mn = ask(1, n);
	int l, r;
	if (mn != 1 && ask(1, mn) == mn)
	{
		l = 1;
		r = mn - 1;
	}
	else
	{
		l = mn + 1;
		r = n;
	}
	while (l < r)
	{
		if (mn < l)
		{
			int m = (l + r) / 2;
			if (ask(mn, m) == mn)
				r = m;
			else
				l = m + 1;
		}
		else
		{
			int m = (l + r + 1) / 2;
			if (ask(m, mn) == mn)
				l = m;
			else
				r = m - 1;
		}
	}
	cout << "! " << l << endl;
}