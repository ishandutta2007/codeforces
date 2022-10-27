/*input
4
4
1 2 3 4
5
1 3 2 4 5
3
2 3 1
1
1

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
		int x[n + 1];
		for (int i = 1; i <= n; i++)
			x[i] = n;
		for (int i = 0; i + 1 < n; i++)
		{
			x[a[i]] = i + 2;
		}
		for (int i = 1; i <= n; i++)
			cout << x[i] << " ";
		cout << "\n";
	}
	return 0;
}