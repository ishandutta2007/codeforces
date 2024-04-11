/*input
4
8
0 0 1 1 1 1 1 1
5
1 0 0 1 1
2
1 0
11
1 1 0 0 1 0 0 1 1 1 0

*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937 rng(0);
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	y %= mod - 1;
	x %= mod;
	if (x < 0)
		x += mod;
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y)
	{
		if (y % 2)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n + 1];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int c0t = 0;
		for (int i = 0; i < n; i++)
			if (a[i] == 0)
				c0t++;
		int c0 = 0;
		int k = n;
		for (int k0 = 0; k0 <= n; k0++)
		{
			int c1 = k0 - c0;
			int c2 = c0t - c0;
			k = min(k, c1 + max(0, c2 - c1));
			if (a[k0] == 0)
				c0++;
		}
		cout << k << "\n";
	}
	return 0;
}