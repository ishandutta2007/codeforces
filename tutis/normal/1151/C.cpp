/*input
88005553535 99999999999

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000000007;
ll f1(ll x)
{
	x %= modulo;
	return (x * x) % modulo;
}
ll f(ll n)
{
	if (n <= 0)
		return 0;
	ll k[2] = {0, 0};
	ll a = 1;
	ll b = 0;
	while (k[0] + k[1] < n)
	{
		ll c = min(a, (n - k[0] - k[1]));
		k[b] += c;
		a *= 2;
		b = 1 - b;
	}
	k[1] %= modulo;
	k[0] %= modulo;
	return (f1(k[0]) + f1(k[1]) + k[1]) % modulo;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll l, r;
	cin >> l >> r;
	cout << (f(r) - f(l - 1) + modulo) % modulo << "\n";
}