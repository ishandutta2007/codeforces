/*input
3
3 2
3 2 1
5 3
1 2 3 4 8
1 5
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
		int n, x;
		cin >> n >> x;
		int w[n];
		for (int i = 0; i < n; i++)
			cin >> w[i];
		sort(w, w + n);
		int suma = 0;
		for (int i = 0; i < n; i++)
		{
			suma += w[i];
			if (suma == x && i != n - 1)
				swap(w[i], w[i + 1]);
		}
		bool ok = true;
		suma = 0;
		for (int i = 0; i < n; i++)
		{
			suma += w[i];
			if (suma == x)
				ok = false;
		}
		if (suma != x)
		{
			cout << "YES\n";
			for (int i : w)
				cout << i << " ";
			cout << "\n";
		}
		else
			cout << "NO\n";
	}
}