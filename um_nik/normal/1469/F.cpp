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

const int N = 400400;
int fenv[N];

void addFenv(int p, int x) {
	for(; p < N; p |= p + 1)
		fenv[p] += x;
}
int getFenv(int r) {
	int res = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		res += fenv[r];
	return res;
}

int n;
ll k;
int a[N];
int b[N];

bool solve(ll m) {
	ll sum = 1;
	for (int i = 0; i < n; i++) {
		ll p = b[i];
		if (p >= m) return false;
		sum--;
		sum += max(0LL, min(m, p + 2 + (a[i] - 1) / 2) - (p + 2));
		sum += max(0LL, min(m, p + 2 + a[i] / 2) - (p + 2));
		if (sum >= k) return true;
	}
	return false;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	reverse(a, a + n);
	addFenv(0, 1);
	addFenv(1, -1);
	int p = 0;
	for (int i = 0; i < n; i++) {
		while(getFenv(p) == 0) p++;
		b[i] = p;
		addFenv(p, -1);
		addFenv(p + 1, 1);
		addFenv(p + 2, 1);
		addFenv(p + 2 + (a[i] - 1) / 2, -1);
		addFenv(p + 2, 1);
		addFenv(p + 2 + a[i] / 2, -1);
	}
	for (int i = 0; i < n; i++)
		eprintf("%d %d\n", a[i], b[i]);
	ll l = 0, r = k + 2 * n + 5;
	while(r - l > 1) {
		ll x = (l + r) / 2;
		if (solve(x))
			r = x;
		else
			l = x;
	}
	if (r == k + 2 * n + 5) {
		printf("-1\n");
	} else {
		printf("%lld\n", l);
	}

	return 0;
}