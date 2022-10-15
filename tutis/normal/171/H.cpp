/*input
1 0
2 15
4 160
3 14
*/
#pragma GCC optimize ("O3")
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
pair<int, int>f(int a, int b)
{
	pair<int, int>g = {0, 0};
	for (int i = 1; i <= a; i++)
	{
		int k = 1 << (2 * i - 2);
		int s = 1 << (i - 1);
		int c = (b / (k)) % 4;
		if (c == 0)
		{
			g = {g.second, g.first};
		}
		else if (c == 1)
		{
			g = {g.first, g.second + s};
		}
		else if (c == 2)
		{
			g = {g.first + s, g.second + s};
		}
		else if (c == 3)
		{
			g = {2 * s - 1 - g.second, s - 1 - g.first};
		}
	}
	return g;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int a, b;
	while (cin >> a >> b)
	{
		pair<int, int>ans = f(a, b);
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}