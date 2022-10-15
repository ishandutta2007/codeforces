/*input
4
6 3 3
1 2 3 2 2 2
6 2 4
1 1 2 2 2 2
6 5 1
6 5 4 3 2 1
4 0 4
4 4 4 3

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
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, l, r;
		cin >> n >> l >> r;
		int c[n];
		for (int &i : c)
			cin >> i;
		int ans = 0;
		map<int, int>L, R;
		for (int i = 0; i < l; i++)
		{
			L[c[i]]++;
		}
		for (int i = l; i < n; i++)
		{
			R[c[i]]++;
		}
		for (int v = 1; v <= n; v++)
		{
			int c = min(L[v], R[v]);
			L[v] -= c;
			R[v] -= c;
			l -= c;
			r -= c;
		}
		for (int v = 1; v <= n; v++)
		{
			while (L[v] >= 2 && l > r)
			{
				l -= 2;
				ans++;
				L[v] -= 2;
			}
			while (R[v] >= 2 && l < r)
			{
				r -= 2;
				ans++;
				R[v] -= 2;
			}
		}
		ans += abs(l - r) / 2;
		ans += (l + r) / 2;
		cout << ans << "\n";
	}
}