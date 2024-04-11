/*input
4
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
bitset<15001>X[15001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>>ans;
	int x = n;
	while ((x & (-x)) != x)
		x--;
	for (int d = 2; d <= x; d *= 2)
	{
		for (int i = 0; i + d / 2 < x; i++)
		{
			if ((i / (d / 2)) % 2 == 0)
			{
				ans.push_back({1 + i, 1 + i + d / 2});
			}
		}
	}
	int del = n - x;
	for (int d = 2; d <= x; d *= 2)
	{
		for (int i = 0; i + d / 2 < x; i++)
		{
			if ((i / (d / 2)) % 2 == 0)
			{
				ans.push_back({del + 1 + i, del + 1 + i + d / 2});
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i.first << " " << i.second << "\n";


	return 0;
}