/*input
3 3 2
1 2
2 1
3 3
3 2

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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	string S = "";
	for (int i = 0; i < n - 1; i++)
		S.push_back('U');
	for (int i = 0; i < m - 1; i++)
		S.push_back('L');
	int x = 0;
	int y = 0;
	while (y < m)
	{
		if (y % 2 == 0)
		{
			if (x + 1 < n)
			{
				x++;
				S.push_back('D');
			}
			else
			{
				y++;
				S.push_back('R');
			}
		}
		else
		{
			if (x - 1 >= 0)
			{
				x--;
				S.push_back('U');
			}
			else
			{
				y++;
				S.push_back('R');
			}
		}
	}
	cout << S.size() << "\n";
	cout << S << "\n";
}