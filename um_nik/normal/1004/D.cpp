#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const int N = (int)1e6 + 77;
int a[N];
int b[N];
int S;
int d;
ll sum;

ll getSum(ll t) {
	return t * (t + 1) / 2;
}

bool check(int w, int h, int x, int y) {
	for (int i = 0; i < S; i++)
		b[i] = 0;
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
			b[abs(i - x) + abs(j - y)]++;
	for (int i = 0; i < S; i++)
		if (a[i] != b[i])
			return false;
	return true;
}

void trySolve(int w, int h) {
	eprintf("trySolve %d %d\n", w, h);
	int p = w - d;
	if (p < d - 1) return;
	ll R = getSum(d - 1) + getSum(p);
	R *= h;
	if (R > sum) return;
	ll l = -1, r = (h - 1) / 2;
	while(r - l > 1) {
		ll s = (l + r) / 2;
		ll t = h - 1 - s;
		assert(s <= t);
		if (R + (getSum(s) + getSum(t)) * w > sum)
			l = s;
		else
			r = s;
	}
	ll s = r;
	ll t = h - 1 - s;
	if (R + (getSum(s) + getSum(t)) * w != sum) return;
	if (check(w, h, d - 1, s)) {
		printf("%d %d\n%d %lld\n", w, h, d, s + 1);
		exit(0);
	}
}

int main()
{
	startTime = clock();
//	freopen("grass.in", "r", stdin);
//	freopen("grass.out", "w", stdout);

	scanf("%d", &S);
	for (int i = 0; i < S; i++) {
		int x;
		scanf("%d", &x);
		a[x]++;
		sum += x;
	}
	if (a[0] != 1) {
		printf("-1\n");
		return 0;
	}
	d = 1;
	while(a[d] == 4 * d) d++;
	eprintf("d = %d\n", d);
	for (int w = 1; w * w <= S; w++) {
		if (S % w) continue;
		int h = S / w;
		trySolve(w, h);
		trySolve(h, w);
	}
	printf("-1\n");

	return 0;
}