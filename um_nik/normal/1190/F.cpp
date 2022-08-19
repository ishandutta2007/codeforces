#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = (ll)2e18;
const int B = 6;
ll mult(ll x, ll y, ll md) {
	if (y == 0) return 0;
	return (mult((x * B) % md, y / B, md) + (x * (y % B))) % md;
}
ll bin_pow(ll x, ll p, ll md) {
	if (p == 0) return 1 % md;
	if (p & 1) return mult(x, bin_pow(x, p - 1, md), md);
	return bin_pow(mult(x, x, md), p / 2, md);
}

const int CC = (int)5e6;
//const int CC = 0;
bool used[CC + 1];

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

ll F(ll x, ll m) {
	x = mult(x, x, m);
	x++;
	if (x == m) x -= m;
	return x;
}
vector<ll> findDivs(ll m) {
	vector<ll> ans;
	for (ll x = 2; x < CC; x++) {
		if (m % x) continue;
		ans.push_back(x);
		while(m % x == 0) m /= x;
	}
	if (m == 1) return ans;
	
	// pollard
	if (m < (ll)(CC - 2) * (CC - 2)) {
		ans.push_back(m);
		return ans;
	}
	for (int it = 0; it < 5; it++) {
		ll x = rng() % 100 + 1;
		ll y = x;
		for (int it2 = 0; it2 < 100000; it2++) {
			x = F(x, m);
			y = F(y, m);
			y = F(y, m);
			ll d = gcd(abs(x - y), m);
			if (d != 1 && d != m) {
				ans.push_back(d);
				ans.push_back(m / d);
				return ans;
			}
		}
	}
	ans.push_back(m);
	return ans;
}

ll getOrder(ll g, ll m, ll phi, vector<ll> divs) {
//	cerr << g << " " << m << " " << phi << endl;
	for (ll x : divs) {
		//cerr << x << endl;
		ll z = bin_pow(g, phi / x, m);
//		cerr << z << endl;
		if (z == 1)
			return x;
	}
	return 1;
}

ll myPow(ll x, ll p) {
	ll res = 1;
	while(p--) {
		if ((double)res * x > INF) return INF;
		res *= x;
	}
	return min(res, INF);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	ll m, w;
	scanf("%d%lld%lld", &n, &m, &w);
	ll p = m;
	int t = 1;
	for (int k = 2; k < 60; k++) {
		ll z = (ll)(powl(m, 1. / k));
		if (z > 1) z--;
		z = max(z, 1LL);
		while(myPow(z, k) > m) z--;
		while(myPow(z, k) < m) z++;
		if (myPow(z, k) == m) {
			p = z;
			t = k;
		}
	}
//	eprintf("%lld %d\n", p, t);
	if (m < CC) {
		for (int i = 0; i < m; i++) {
			used[i] = 0;
		}
		ll x = 1;
		while(true) {
			if (used[x]) break;
			used[x] = 1;
			x = (x * w) % m;
		}
		int res = 0;
		for (int i = 0; i < m; i++) {
			if (!used[i] && (i % p != 0)) {
				res++;
			}
		}
		if (res < n) {
			printf("-1\n");
			return 0;
		}
		for (int i = 0; n > 0 && i < m; i++) {
			if (!used[i] && (i % p != 0)) {
				printf("%d ", i);
				n--;
			}
		}
		printf("\n");
		return 0;
	}
	if (w % p == 0) {
		ll res = (m / p) * (p - 1) - 1;
		if (res < n) {
			printf("-1\n");
			return 0;
		}
		for (ll x = 2; n > 0; x++) {
			if (x % p == 0) continue;
			printf("%lld ", x);
			n--;
		}
		printf("\n");
		return 0;
	}
	if (p == 2) {
		int x = 3;
		while(w % 8 == x) x += 2;
		for (int i = 0; i < n; i++)
			printf("%d ", 8 * i + x);
		printf("\n");
		return 0;
	}
	ll phi = (m / p) * (p - 1);
	vector<ll> divs = findDivs(p - 1);
	if (t > 1) divs.push_back(p);
	ll ord = getOrder(w, m, phi, divs);
	if (ord == 1) {
		printf("-1\n");
		return 0;
	}
	ll g = 0;
	while(true) {
		if (g % p == 0 || getOrder(g, m, phi, divs) != 1) {
			g = rng() % m;
		} else break;
	}
	ll x = 1;
	for (int i = 1; n > 0; i++) {
		x = mult(x, g, m);
		if (i % ord != 0) {
			printf("%lld ", x);
			n--;
		}
	}
	printf("\n");
	return 0;
}