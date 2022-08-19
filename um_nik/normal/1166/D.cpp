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

/*
s_i = x_1 + x_2 + ... + x_i
x_i = s_i - s_(i - 1)

1 <= x_i - s_(i-1) <= m
1 <= s_i - 2 * s_(i-1) <= m
s_1 = a
s_n - s_(n-1) = b

*/

/*
	x_1 = a
	x_2 = x_1 + r_2 = a + r_2
	x_3 = 2 * a + r_2 + r_3
	x_4 = 4 * a + 2 * r_2 + r_3 + r_4

	x_k = 2**(k-2) * a + 2**(k-3) * r_2 + ... + 2**1 * r_(k-2) + 2**0 * r_(k-1) + r_k

	b = x_n = 2**(n-2) * a + 2**(n-3) * r_2 + ... + 2**0 * r_(n-1) + r_n
*/

ll ans[55];

bool solve(ll a, ll b, ll m, int n) {
	ans[1] = a;
	for (int i = 0; i < n - 2; i++) {
		a <<= 1;
		if (a > b) return false;
	}
	b -= a;
	if (b <= 0) return false;
	ll L = 1LL << (n - 2);
	if (b < L) return false;
	if (b / m > L) return false;
	if (b > m * L) return false;
	b -= L;
	for (int i = 2; i < n; i++) {
		ll x = b >> (n - i - 1);
		x = min(x, m - 1);
		ans[i] = x + 1;
		b -= x << (n - i - 1);
	}
	if (b < 0 || b > m - 1) throw;
	ans[n] = b + 1;
	ll sum = ans[1];
	for (int i = 2; i <= n; i++) {
		ans[i] += sum;
		sum += ans[i];
	}
	printf("%d", n);
	for (int i = 1; i <= n; i++)
		printf(" %lld", ans[i]);
	printf("\n");
	return true;
}

void solve() {
	ll a, b, m;
	scanf("%lld%lld%lld", &a, &b, &m);
	if (a == b) {
		printf("1 %lld\n", a);
		return;
	}
	for (int n = 2; n < 50; n++)
		if (solve(a, b, m, n))
			return;
	printf("-1\n");
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}