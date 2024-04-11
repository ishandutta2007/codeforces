#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

const int mod = (int)1e9 + 7;
int k;

const int maxn = (int)1e6 + 2;
ll f[maxn];
ll rf[maxn];

ll my_pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}

	if ((b & 1) == 0) {
		ll t = my_pow(a, b >> 1);

		return (t * t) % mod;
	}

	return (a * my_pow(a, b - 1)) % mod;
}

void gcd(ll a, ll b, ll &x1, ll &x2) {
	if (b == 0) {
		x1 = 1;
		x2 = 0;
		return;
	}

	gcd(b, a % b, x2, x1);

	x2 -= a / b * x1;

	x2 %= mod;

	if (x2 < 0) {
		x2 += mod;
	}
}

ll y[maxn];

ll rev(ll x) {
	ll x1, x2;

	gcd(x, mod, x1, x2);

	return x1;
}

int main() {
	f[0] = 1;
	rf[0] = 1;

	for (int i = 1; i < maxn; i++) {
		f[i] = (f[i - 1] * i) % mod;
		rf[i] = rev(f[i]);
	}

	int n;

	cin >> n >> k;

	y[0] = 0;

	ll p = n;

	for (int i = 1; i <= k + 1; i++) {
		p *= (n - i);
		p %= mod;
		y[i] = y[i - 1] + my_pow(i, k);
		if (y[i] >= mod) {
			y[i] -= mod;
		}
	}

	ll ans = 0;

	if (n <= k + 1) {
		cout << y[n] << endl;
		return 0;
	}

	for (int i = 1; i <= k + 1; i++) {
		ll now = p;

		now *= rev(n - i);
		now %= mod;

		now *= rf[i];
		now %= mod;
		now *= rf[k + 1 - i];
		now %= mod;
		if (((k + 1 - i) & 1) == 1) {
			now = mod - now;
		}

		now *= y[i];
		now %= mod;

		ans += now;
		if (ans >= mod) {
			ans -= mod;
		}
	}

	cout << ans << endl;

	return 0;
}