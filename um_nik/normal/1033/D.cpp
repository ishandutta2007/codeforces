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

const ll MOD = 998244353;
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

map<ll, int> pow_for_prime;

ll is_kth_pow(ll x, int k) {
	ll y = (ll)pow(x, 1. / k);
	for (ll z = y - 2; z <= y + 2; z++) {
		if (z <= 1) continue;
		ll cur = 1;
		for (int i = 0; i < k; i++)
			cur *= z;
		if (x == cur)
			return z;
	}
	return -1;
}

bool is_prime(ll x) {
	if (x < 2) return false;
	for (ll y = 2; y * y <= x; y++) {
		if (x % y == 0)
			return false;
	}
	return true;
}

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

vector<pair<ll, int>> a;

void add_prime(ll p, int k) {
	if (pow_for_prime.count(p) == 0) {
		for (int i = (int)a.size() - 1; i >= 0; i--) {
			if (i >= (int)a.size()) continue;
			ll x = a[i].first;
			if (x % p != 0) continue;
			ll q = x / p;
			int m = a[i].second;
			swap(a[i], a.back());
			a.pop_back();
			add_prime(p, m);
			add_prime(q, m);
		}
	}
	pow_for_prime[p] += k;
}

void readNext() {
	ll x;
	scanf("%lld", &x);
	for (int k = 2; k <= 4; k++) {
		ll y = is_kth_pow(x, k);
		if (y == -1 || !is_prime(y)) continue;
		add_prime(y, k);
		return;
	}
	for (auto t : pow_for_prime) {
		ll p = t.first;
		if (x % p == 0) {
			ll q = x / p;
			add_prime(p, 1);
			add_prime(q, 1);
			return;
		}
	}
	for (int i = 0; i < (int)a.size(); i++) {
		if (x == a[i].first) {
			a[i].second++;
			return;
		}
		ll p = gcd(x, a[i].first);
		if (p == 1) continue;
		ll q = x / p;
		add_prime(p, 1);
		add_prime(q, 1);
		return;
	}
	a.push_back(mp(x, 1));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

//	x = p1^a1 * p2^a2 * ... * pk^ak;
//	d(x) = (1 + a1) * (1 + a2) * ... * (1 + ak);

	int n;
	scanf("%d", &n);
	while(n--) readNext();

	ll ans = 1;
	for (auto t : pow_for_prime)
		ans = mult(ans, t.second + 1);
	for (int i = 0; i < (int)a.size(); i++)
		for (int j = 0; j < 2; j++)
			ans = mult(ans, a[i].second + 1);
	printf("%lld\n", ans);

	return 0;
}