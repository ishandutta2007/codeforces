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
#define pll pair <ll, ll>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

const int maxn = (int)1e5 + 10;
ll v[maxn];
const ll mod = (ll)1e9 + 7;

ll my_pow(ll x, ll y) {
	if (y == 0) {
		return 1;
	}

	if (y % 2 == 0) {
		ll t = my_pow(x, y / 2);

		return (t * t) % mod;
	}

	return (x * my_pow(x, y - 1)) % mod;
}

ll go(ll cnt) {
	if (cnt == 0) {
		return 0;
	}

	if (cnt % 2 == 1) {
		return (go(cnt - 1) + my_pow(2, 2 * cnt - 2)) % mod;
	}

	return (go(cnt / 2) * (1 + my_pow(2, cnt))) % mod;
}

int main() {
	int n;

	cin >> n;

	bool st = false;

	for (int i = 0; i < n; i++) {
		scanf("%I64d", &v[i]);
		if (v[i] % 2 == 0) {
			st = true;
		}
	}

	if (!st) {
		ll o = 1;
		for (int i = 0; i < n; i++) {
			v[i] %= (mod - 1);
			o *= v[i];

			o %= (mod - 1);
		}

		o--;

		if (o < 0) {
			o += mod - 1;
		}

		ll z = my_pow(2, o);

		ll ans = go(o / 2);
		/*
		ll f = my_pow(mod - 1, mod - 2);

		for (int i = 0; i < n; i++) {
			f *= v[i];

			f %= mod;
		}

		f -= mod - 1;

		f %= mod;

		if (f < 0) {
			f += mod;
		}

		ll z = go((mod - 1) / 2);

		ans += z * f;

		ans %= mod;
		*/
		cout << ans << '/';
		cout << z << endl;
	} else {
		ll o = 1;
		for (int i = 0; i < n; i++) {
			v[i] %= (mod - 1);
			o *= v[i];

			o %= (mod - 1);
		}

		o--;

		if (o < 0) {
			o += mod - 1;
		}

		ll z = my_pow(2, o);

		ll ans = go(o / 2);

		o--;

		if (o < 0) {
			o += mod - 1;
		}

		ans = my_pow(2, o) - ans;

		ans %= mod;

		if (ans < 0) {
			ans += mod;
		}

		cout << ans << '/';
		cout << z << endl;
	}

	return 0;
}