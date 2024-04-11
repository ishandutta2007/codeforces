/*input
3
7 11
2 9 1 3 18 1 4
4 35
11 9 10 7
1 8
5

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		ll n, s;
		cin >> n >> s;
		ll a[n + 1];
		ll sum = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		if (sum <= s)
		{
			cout << "0\n";
			continue;
		}
		ll suma[n + 1];
		suma[0] = 0;
		for (int i = 1; i <= n; i++)
			suma[i] = suma[i - 1] + a[i];
		pair<int, int>mx = { -1, 0};
		for (int i = 1; i <= n; i++)
		{
			int lo = 0;
			int hi = n;
			while (lo < hi)
			{
				int k = (lo + hi + 1) / 2;
				ll x = suma[k];
				if (k >= i)
					x -= a[i];
				if (x <= s)
					lo = k;
				else
					hi = k - 1;
			}
			int k = lo;
			if (k >= i)
				k--;
			mx = max(mx, {k, i});
		}
		cout << mx.second << "\n";
	}
}