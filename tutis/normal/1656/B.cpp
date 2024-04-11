/*input
4
4 5
4 2 2 7
5 4
1 9 1 3 4
2 17
17 0
2 17
18 18

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
		ll n, k;
		cin >> n >> k;
		int a[n];
		for (int &i : a)
			cin >> i;
		sort(a, a + n);
		bool ok = false;
		for (int &i : a)
			if (binary_search(a, a + n, i + k))
				ok = true;
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}