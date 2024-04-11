/*input
5 5
10 20 30 40 50
2
3
4
5
3

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;
struct Z
{
	int a;
	Z() {
		a = 0;
	}
	Z(ll x) {
		if (-mod <= x && x <= mod)
			a = x;
		else
			a = x % mod;
		if (a < 0)
			a += mod;
	}
	Z operator+(Z o) {
		Z c;
		c.a = a + o.a;
		if (c.a >= mod)
			c.a -= mod;
		return c;
	}
	Z operator-(Z o) {
		Z c;
		c.a = a - o.a;
		if (c.a < 0)
			c.a += mod;
		return c;
	}
	Z operator*(Z o) {
		Z c;
		c.a = (ll(a) * ll(o.a)) % mod;
		return c;
	}
	static ll power(ll a, int k) {
		ll r = 1;
		while (k != 0) {
			if (k % 2 == 1)
				r = (r * a) % mod;
			k /= 2;
			a = (a * a) % mod;
		}
		return r;
	}
	Z operator/(Z o) {
		Z c; c.a = (ll(a) * power(o.a, mod - 2)) % mod;
		return c;
	}
	void operator+=(Z o) {
		a += o.a;
		if (a >= mod)a -= mod;
	}
	void operator-=(Z o) {
		a -= o.a;
		if (a < 0)a += mod;
	}
	void operator*=(Z o) {
		a = (ll(a) * ll(o.a)) % mod;
	}
	void operator/=(Z o) {
		a = (ll(a) * power(o.a, mod - 2)) % mod;
	}
	friend ostream& operator<< (ostream& stream, const Z& a) {
		stream << a.a;
		return stream;
	}
	friend istream& operator>> (istream& stream, Z& a) {
		stream >> a.a;
		return stream;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, q;
	cin >> n >> q;
	Z p[n + 1];
	Z pp[n + 1];
	p[0] = 1;
	pp[0] = 1;
	for (ll i = 1; i <= n; i++)
	{
		cin >> pp[i];
		pp[i] /= 100;
		p[i] = p[i - 1] * pp[i];
	}
	set<ll>ch;
	ch.insert(1);
	ch.insert(n + 1);
	Z sumaS[n + 1];
	Z suma1S[n + 1];
	Z suma2S[n + 1];
	sumaS[0] = 0;
	suma1S[0] = 0;
	for (int k = 1; k <= n; k++)
	{
		sumaS[k] = sumaS[k - 1] + p[k - 1] * Z(Z(1) - pp[k]);
		suma1S[k] = suma1S[k - 1] + p[k - 1] * Z(Z(1) - pp[k]) * Z(k);
	}
	auto calc = [&](ll i)->Z
	{
		ll j = (*ch.upper_bound(i)) - 1;
		Z suma = sumaS[j] - sumaS[i - 1];
		Z sum1 = (suma1S[j] - suma1S[i - 1]) + (Z(1) - i) * (suma);
		Z sand = p[j];
		Z ret = (sum1 + sand * Z(j - i + 1)) / (p[i - 1] - suma);
		return ret;
	};
	Z ans = calc(1);
	while (q--)
	{
		ll u;
		cin >> u;
		if (ch.count(u))
		{
			ll x = *(--ch.find(u));
			ans -= calc(x);
			ans -= calc(u);
			ch.erase(u);
			ans += calc(x);
		}
		else
		{
			ll x = *(--ch.lower_bound(u));
			ans -= calc(x);
			ch.insert(u);
			ans += calc(x);
			ans += calc(u);
		}
		cout << ans << "\n";
	}
}