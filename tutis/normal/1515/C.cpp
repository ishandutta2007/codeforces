/*input
2
5 2 3
1 2 3 1 2
4 3 3
1 1 2 3

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
		int n, m, x;
		cin >> n >> m >> x;
		int h[n];
		for (int i = 0; i < n; i++)
			cin >> h[i];
		set<pair<int, int>>S;
		for (int i = 1; i <= m; i++)
			S.insert({0, i});
		cout << "YES\n";
		for (int i : h)
		{
			pair<int, int>a = *S.begin();
			S.erase(S.begin());
			a.first += i;
			S.insert(a);
			cout << a.second << " ";
		}
		cout << "\n";
	}
}