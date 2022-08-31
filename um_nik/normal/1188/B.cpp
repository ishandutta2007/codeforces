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

const int N = 300300;
ll a[N];
int n;
ll k, p;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld%lld", &n, &p, &k);
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		ll res = ((x * x) % p * x) % p;
		res -= k;
		if (res < 0) res += p;
		a[i] = (res * x) % p;
	}
	sort(a, a + n);
	ll ans = 0;
	int l = 0;
	while(l < n) {
		int r = l + 1;
		while(r < n && a[l] == a[r]) r++;
		ll x = (r - l);
		ans += x * (x - 1) / 2;
		l = r;
	}
	printf("%lld\n", ans);

	return 0;
}