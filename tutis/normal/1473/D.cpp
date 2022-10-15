/*input
2
8 4
-+--+--+
1 8
2 8
2 5
1 1
4 10
+-++
1 1
1 2
2 2
1 3
2 3
3 3
1 4
2 4
3 4
4 4

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
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		int mx[n + 1], mn[n + 1];
		int v[n + 1];
		v[0] = 0;
		mx[0] = 0;
		mn[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			v[i] = v[i - 1];
			mx[i] = mx[i - 1];
			mn[i] = mn[i - 1];
			if (s[i - 1] == '+')
				v[i]++;
			else
				v[i]--;
			mx[i] = max(mx[i], v[i]);
			mn[i] = min(mn[i], v[i]);
		}
		int mn_[n + 2];
		int mx_[n + 1];
		mn_[n + 1] = 0;
		mx_[n + 1] = 0;
		for (int i = n; i > 0; i--)
		{
			if (s[i - 1] == '+')
			{
				mx_[i] = mx_[i + 1] + 1;
				mn_[i] = min(0, mn_[i + 1] + 1);
			}
			else
			{
				mx_[i] = max(0, mx_[i + 1] - 1);
				mn_[i] = mn_[i + 1] - 1;
			}
		}
		while (m--)
		{
			int l, r;
			cin >> l >> r;
			int lo = mn[l - 1];
			int hi = mx[l - 1];
			lo = min(lo, v[l - 1] + mn_[r + 1]);
			hi = max(hi, v[l - 1] + mx_[r + 1]);
			cout << hi - lo + 1 << "\n";
		}
	}
}