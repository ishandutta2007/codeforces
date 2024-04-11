/*input
5
2 10
1 9
1 10
1
5 7
1 2 3 4 6
2 1000000000
413470354 982876160
9 478
1 10 25 33 239 445 453 468 477

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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, l;
		cin >> n >> l;
		int a[n + 2];
		a[0] = 0;
		a[n + 1] = l;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		ld lo = 0;
		ld hi = l;
		for (int tt = 0; tt < 40; tt++)
		{
			ld t = (lo + hi) / 2;
			ld x = 0;
			ld y = l;
			ld tx = 0;
			ld ty = 0;
			for (int i = 1; i <= n + 1; i++)
			{
				if (tx + (a[i] - x) / i <= t)
				{
					tx += (a[i] - x) / i;
					x = a[i];
				}
				else
				{
					x = (t - tx) * i + x;
					break;
				}
			}
			for (int i = n; i >= 0; i--)
			{
				if (ty + (y - a[i]) / (n - i + 1) <= t)
				{
					ty += (y - a[i]) / (n - i + 1);
					y = a[i];
				}
				else//(-y + y') = -(t-ty)*(n - i + 1)
				{
					y = -(t - ty) * (n - i + 1) + y;
					break;
				}
			}
			if (x >= y)
				hi = t;
			else
				lo = t;
		}
		ld t = (lo + hi) / 2;
		cout << fixed << setprecision(20) << t << "\n";
	}
	return 0;
}