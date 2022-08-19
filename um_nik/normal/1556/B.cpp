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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const ll INF = (ll)1e18;
const int N = 100100;
int n;
int a[N];
int b[N];

ll solve2() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] - b[i];
	}
	ll ans = 0;
	if (sum != 0) return INF;
	for (int k = 0; k < 2; k++) {
		int p = 0, q = 0;
		while(true) {
			while(p < n && a[p] != k) p++;
			while(q < n && b[q] != k) q++;
			if (p == n) {
				assert(q == n);
				break;
			}
			ans += abs(p - q);
			p++;
			q++;
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		eprintf("%d ", a[i]);
	}
	eprintf("\n");
	for (int i = 0; i < n; i++) {
		eprintf("%d ", b[i]);
	}
	eprintf("\n");
	eprintf("%lld\n", ans);
	*/
	return ans / 2;
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] &= 1;
	}
	ll ans = INF;
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < n; i++)
			b[i] = k ^ (i & 1);
		ans = min(ans, solve2());
	}
	if (ans == INF) ans = -1;
	printf("%lld\n", ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}