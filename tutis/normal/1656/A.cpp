/*input
3
3
5 2 7
5
1 4 2 2 3
1
2
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
using namespace std;
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
ll mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll power(ll a, ll b)
{
	if (abs(a) >= mod)
		a %= mod;
	if (abs(b) >= mod - 1)
		b %= (mod - 1);
	if (a < 0)
		a += mod;
	if (b < 0)
		b += mod - 1;
	ll r = 1;
	if (b % 2 == 1)
		r = a;
	b /= 2;
	while (b)
	{
		a = (a * a) % mod;
		if (b % 2 == 1)
			r = (r * a) % mod;
		b /= 2;
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
		ll n;
		cin >> n;
		int a[n];
		for (int &i : a)
			cin >> i;
		int k0 = 0;
		int k1 = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] < a[k0])
				k0 = i;
			if (a[i] > a[k1])
				k1 = i;
		}
		cout << k0 + 1 << " " << k1 + 1 << "\n";
	}
}