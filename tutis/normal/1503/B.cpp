/*input
3
1
1
1
1
2
1
2
1
3
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>>A[2];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			A[(i + j) % 2].push_back({i, j});
	for (int k = 0; k < n * n; k++)
	{
		int a;
		cin >> a;
		if (A[0].empty())
		{
			int b = 2;
			if (a == 2)
				b = 3;
			cout << b << " " << A[1].back().first << " " << A[1].back().second << endl;
			A[1].pop_back();
		}
		else if (A[1].empty())
		{
			int b = 1;
			if (a == 1)
				b = 3;
			cout << b << " " << A[0].back().first << " " << A[0].back().second << endl;
			A[0].pop_back();
		}
		else if (a != 1)
		{
			cout << 1 << " " << A[0].back().first << " " << A[0].back().second << endl;
			A[0].pop_back();
		}
		else
		{
			cout << 2 << " " << A[1].back().first << " " << A[1].back().second << endl;
			A[1].pop_back();
		}
	}
}