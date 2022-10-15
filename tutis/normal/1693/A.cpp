/*input
7
2
1 0
4
2 -1 -1 0
4
1 -4 3 0
4
1 -1 1 -1
5
1 2 3 4 -10
7
2 -1 1 -2 0 0 0
1
0

*/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	if (abs(x) >= mod)
		x %= mod;
	if (x < 0)
		x += mod;
	if (abs(y) >= mod - 1)
		y %= mod - 1;
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y != 0)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ll a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ll sum = 0;
		for (ll i : a)
			sum += i;
		if (sum != 0)
		{
			cout << "no\n";
		}
		else
		{
			bool ok = true;
			ll sum = 0;
			for (int i = 0; i < n; i++)
			{
				if (sum == 0 && a[i] > 0 && i != 0)
					ok = false;
				sum += a[i];
				if (sum < 0)
				{
					ok = false;
				}
			}
			if (ok)
				cout << "yes\n";
			else
				cout << "no\n";
		}
	}
}