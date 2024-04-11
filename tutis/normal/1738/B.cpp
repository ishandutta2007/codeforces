/*input
4
5 5
1 2 3 4 5
7 4
-6 -5 -3 0
3 3
2 3 4
3 2
3 4

*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(0);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int x[k + 1];
		for (int i = 1; i <= k; i++)
			cin >> x[i];
		bool ok = true;
		for (int i = 3; i <= k; i++)
			ok &= x[i] - x[i - 1] >= x[i - 1] - x[i - 2];
		if (k >= 2)
		{
			int x1 = n - k + 1;
			int x2 = n - k + 2;
			int y1 = x[1];
			int y2 = x[2];
			ld val = ld(y1) + ld(-x1) / ld(x2 - x1) * ld(y2 - y1);
			ok &= val <= ld(1e-12);
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}