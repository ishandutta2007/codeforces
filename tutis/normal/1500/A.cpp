/*input
5
1 3 1 9 20

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
using ld = double;
mt19937_64 rng(456456);
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
const ll mod = 1000000007;
pair<int, int>A[5000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int t = 0; t < 20000000; t++)
	{
		int x = (rng() % n) + 1;
		int y = (rng() % n) + 1;
		if (x == y)
			continue;
		pair<int, int>&zz = A[a[x] + a[y]];
		if (zz.first != 0)
		{
			int z = zz.first;
			int t = zz.second;
			if (x != z && x != t && y != z && y != t)
			{
				cout << "YES\n";
				cout << x << " " << y << " " << z << " " << t << "\n";
				return 0;
			}
		}
		zz = {x, y};
	}
	cout << "NO\n";
}