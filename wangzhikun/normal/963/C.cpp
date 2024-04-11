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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair

int n;
map<ll, ll> A, B;
map<pll, ll> C;

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

bool checkProd(ll a, ll b, ll c, ll d) {
	ll g = gcd(a, c);
	a /= g;
	c /= g;
	g = gcd(b, c);
	b /= g;
	c /= g;
	g = gcd(a, d);
	a /= g;
	d /= g;
	g = gcd(b, d);
	b /= g;
	d /= g;
	return a == 1 && b == 1 && c == 1 && d == 1;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	ll S = 0;
	for (int i = 0; i < n; i++) {
		ll x, y, w;
		scanf("%lld%lld%lld", &x, &y, &w);
		C[mp(x, y)] += w;
		A[x] += w;
		B[y] += w;
		S += w;
	}
	if ((ll)A.size() * (ll)B.size() != (ll)C.size()) {
		printf("0\n");
		return 0;
	}

	for (auto t1 : A)
		for (auto t2 : B) {
			if (!checkProd(t1.second, t2.second, S, C[mp(t1.first, t2.first)])) {
				printf("0\n");
				return 0;
			}
		}

	ll P = 0, Q = 0;
	for (auto t : A)
		P = gcd(P, t.second);
	for (auto t : B)
		Q = gcd(Q, t.second);

	if (S % P != 0 || S % Q != 0) throw;

	S /= P;
	if (Q % S != 0) {
		printf("0\n");
		return 0;
	}
	S = Q / S;

	ll ans = 1;
	for (ll x = 2; x * x <= S; x++) {
		if (S % x != 0) continue;
		ll t = 1;
		while(S % x == 0) {
			S /= x;
			t++;
		}
		ans *= t;
	}
	if (S > 1) ans *= 2;
	printf("%lld\n", ans);

	return 0;
}