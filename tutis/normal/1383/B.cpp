/*input
4
5
4 1 5 1 3
4
1 0 1 6
1
0
2
5 4
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp(int k1, int k0, int x, int y, int rx, int ry)
{
	if (k1 == 0)
	{
		if (x == rx)
			return true;
		else
			return false;
	}
	if (k0 == 0)
	{
		if (dp(k1 - 1, k0, y, x ^ 1, ry ^ 1, rx ^ 1))
			return false;
		else
			return true;
	}
	if (!dp(k1 - 1, k0, y, x ^ 1, ry ^ 1, rx ^ 1))
		return true;
	if (!dp(k1, k0 - 1, y, x, ry ^ 1, rx ^ 1))
		return true;
	return false;
}
bool get(int k0, int k1)
{
	if (k0 == 0)
		return false;
	if (k1 % 2 == 0)
	{
		if (k0 % 4 == 3 || k0 % 4 == 0)
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	// for (int i = 0; i < 10; i++)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		cout << get(i, j) << " ";
	// 	}
	// 	cout << endl;
	// }
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ll a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int ans = 0;
		for (int t = 30; t >= 0; t--)
		{
			int kiek = 0;
			for (int i = 0; i < n; i++)
				if ((a[i] & (1ll << t)) != 0)
					kiek++;
			if (kiek % 2 == 1)
			{
				if (get(kiek, n - kiek))
					ans = 1;
				else
					ans = -1;
				break;
			}
		}
		if (ans == 0)
			cout << "DRAW\n";
		else if (ans == 1)
			cout << "WIN\n";
		else
			cout << "LOSE\n";
	}
	return 0;
}