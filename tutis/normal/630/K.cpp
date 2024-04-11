/*input
2519
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll C(ll n, ll k)
{
	if (k > n || k < 0)
		return 0;
	ll s = 1;
	ll f = 1;
	for (int i = 0; i < k; i++)
		f *= i + 1;
	for (int i = 0; i < k; i++)
	{
		ll x = n - i;
		ll g = __gcd(x, f);
		f /= g;
		x /= g;
		s *= x;
	}
	s /= f;
	return s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ull n;
	cin >> n;
	cout << n
	     - n / 2 - n / 3 - n / 5 - n / 7
	     + n / 6 + n / 15 + n / 35 + n / 14 + n / 10 + n / 21
	     - n / 2 / 3 / 5 - n / 2 / 3 / 7 - n / 2 / 5 / 7 - n / 3 / 5 / 7
	     + n / 2 / 3 / 5 / 7 << "\n";
}