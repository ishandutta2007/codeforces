/*input
4
1
15
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
bool ger[2][2][2];
int main()
{
	ger[0][1][0] = true;

	ger[0][0][1] = true;
	ger[0][1][1] = true;

	ger[1][0][1] = true;

	ger[1][0][0] = true;
	ger[1][1][0] = true;
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	ll a[n][n];
	for (int t = 0; t < 2 * n - 1; t++)
	{
		for (int i = 0; i < n; i++)
		{
			int j = t - i;
			if (j >= 0 && j < n)
			{
				if (i % 2 == 0)
					a[i][j] = 0;
				else
					a[i][j] = 1ll << t;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	int q;
	cin >> q;
	while (q--)
	{
		ll k;
		cin >> k;
		int x = 0;
		int y = 0;
		vector<pair<int, int>>ans;
		while (x != n - 1 || y != n - 1)
		{
			ans.push_back({x, y});
			if (x == n - 1)
			{
				y++;
			}
			else if (y == n - 1)
				x++;
			else
			{
				ll tx = a[x + 1][y] ^ k;
				ll ty = a[x][y + 1] ^ k;
				if (tx <= ty)
					x++;
				else
					y++;
			}
		}
		ans.push_back({x, y});
		for (auto i : ans)
			cout << i.first + 1 << " " << i.second + 1 << endl;
	}
	return 0;
}