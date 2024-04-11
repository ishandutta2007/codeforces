/*input
7
3 2
0 1 0
5 3
1 0 1 1 0
2 2
1 1
4 4
0 0 0 0
6 3
0 0 1 0 0 1
7 5
1 1 1 1 1 1 1
5 3
0 0 1 0 0

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
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		bool ok = false;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 1)
			{
				ok = true;
			}
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}