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

const int N = 1001000;
ll ans[N];
int m;

ll solve(ll n, ll d) {
	ll res = d * (d - 1) / 2;
	return res * (n / d) + d;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll n;
	scanf("%lld", &n);
	for (ll x = 1; x * x <= n; x++) {
		if (n % x) continue;
		ans[m++] = x;
		if (x * x != n)
			ans[m++] = n / x;
	}
	sort(ans, ans + m);
	for (int i = 0; i < m; i++)
		printf("%lld ", solve(n, ans[i]));
	printf("\n");

	return 0;
}