/*input
2 5 3

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
	ld l3, l4, l5;
	cin >> l3 >> l4 >> l5;
	ld c3 = 1 / sqrtl(3 * 4 * 6);
	ld c4 = sqrtl(2) / 6;
	ld c5 = 0.30150283239583;

	cout << fixed << setprecision(12) << pow(l3, 3)*c3 + pow(l4, 3)*c4 + pow(l5, 3)*c5 << "\n";
}