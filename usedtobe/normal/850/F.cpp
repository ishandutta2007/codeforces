#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, N = 111111;
ll a[N], S;
ll pw(ll a, ll b) {
	ll an = 1;
	for (; b; b >>= 1) {
		if (b & 1) an = 1ll * an * a % mod;
		a = 1ll * a * a % mod;
	}
	return an;
}
ll fix(ll x) {return (x % mod + mod) % mod;}
ll inv(ll x) {return pw(x, mod - 2);}
ll f[N], n, ans;
int main() {
	scanf("%d", &n);
	for (ll i = 1; i <= n; ++i) scanf("%d", &a[i]), S += a[i];
	f[1] = 1ll * (S - 1) * (S - 1) % mod * inv(S) % mod;
	for (ll i = 1; i <= 100000; ++i) f[i + 1] = fix(2ll * f[i] - f[i - 1] - (S - 1) * inv(S - i) % mod);
	for (ll i = 1; i <= n; ++i) (ans += f[a[i]]) %= mod;
	cout << ans << endl;
	return 0;
}