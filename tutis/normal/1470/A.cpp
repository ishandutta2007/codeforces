/*input
2
5 4
2 3 4 3 2
3 5 12 20
5 5
5 4 3 2 1
10 40 90 160 250

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
		int k[n];
		for (int i = 0; i < n; i++)
			cin >> k[i];
		int c[m + 1];
		for (int i = 1; i <= m; i++)
			cin >> c[i];
		sort(k, k + n);
		int i = 1;
		ll ans = 0;
		ll suma = 0;
		vector<int>A;
		for (int i = 0; i < n; i++)
		{
			suma += c[k[i]];
			A.push_back(k[i]);
		}
		ans = suma;
		for (int i = 1; i <= m && i <= n; i++)
		{
			suma += c[i];
			suma -= c[A.back()];
			if (A.back() < i)
				break;
			A.pop_back();
			ans = min(ans, suma);
		}

		cout << ans << "\n";
	}

}