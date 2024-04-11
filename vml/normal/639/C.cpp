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
#include <numeric>
#include <memory.h>
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 

using namespace std;

const int maxn = (int)2e5 + 10;
ll p = (int)1e9 + 7, q = (int)1e9 + 9;

pll operator *(pll a, ll x) {
	a.first *= x;
	a.second *= x;
	a.first %= p;
	a.second %= q;

	return a;
}

pll operator +(pll a, ll x) {
	a.first += x;
	a.second += x;
	a.first %= p;
	a.second %= q;

	return a;
}

pll operator +(pll a, pll b) {
	a.first += b.first;
	a.second += b.second;
	a.first %= p;
	a.second %= q;

	return a;
}

pll operator -(pll a, ll x) {
	a.first -= x;
	a.second -= x;

	a.first %= p;
	a.second %= q;

	if (a.first < 0) {
		a.first += p;
	}

	if (a.second < 0) {
		a.second += q;
	}

	return a;
}

pll operator -(pll a, pll b) {
	a.first -= b.first;
	a.second -= b.second;

	a.first %= p;
	a.second %= q;

	if (a.first < 0) {
		a.first += p;
	}

	if (a.second < 0) {
		a.second += q;
	}

	return a;
}

ll my_pow(ll x, ll y, ll p) {
	if (y == 0) {
		return 1;
	}

	if (y % 2 == 0) {
		ll t = my_pow(x, y / 2, p);

		return (t * t) % p;
	}

	return (x * my_pow(x, y - 1, p)) % p;
}

ll v[maxn];

int main() {
	int n, k;

	cin >> n >> k;

	n++;

	for (int i = 0; i < n; i++) {
		scanf("%I64d", &v[i]);
	}

	pll z = mp(0, 0);

	for (int i = n - 1; i >= 0; i--) {
		z = z * 2;
		z = z + v[i];
	}

	pll st = mp(1, 1);

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		z = z - st * v[i];

		ll a = my_pow(st.first, p - 2, p);

		a *= -z.first;
		a %= p;
		if (a < 0) {
			a += p;
		}

		ll b = my_pow(st.second, q - 2, q);

		b *= -z.second;
		b %= q;
		if (b < 0) {
			b += q;
		}

		if ((a == b && a <= k) || (a - p == b - q && a - p >= -k)) {// || a - p == b - q) {
			if (i == n - 1 && a == 0) {
				break;
			}
			ans++;
		}

		z = z + st * v[i];
		st = st * 2;
	}

	cout << ans << endl;

	return 0;
}