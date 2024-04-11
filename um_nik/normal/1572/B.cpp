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
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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

const int N = 200200;
int n;
int a[N];
int ans[N];
int ansSz;

void solve() {
	ansSz = 0;
	scanf("%d", &n);
	a[0] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i + 1]);
		a[i + 1] ^= a[i];
	}
	if (a[n] == 1) {
		printf("NO\n");
		return;
	}
	bool bad = true;
	for (int i = 1; i <= n; i += 2)
		bad &= a[i];
	if (bad) {
		printf("NO\n");
		return;
	}
	int p = 0;
	while(p < n) {
		assert(a[p] == 0);
		if (a[p + 1] == 0) {
			p++;
			continue;
		}
		if (p + 3 <= n && a[p + 3] == 0) {
			ans[ansSz++] = p + 1;
			a[p + 1] = a[p + 2] = 0;
			continue;
		}
		if (a[p + 2] == 0 && p > 0) {
			ans[ansSz++] = p;
			a[p + 1] = 0;
			continue;
		}
		if (p > 0) {
			assert(p + 3 <= n);
			ans[ansSz++] = p + 1;
			ans[ansSz++] = p;
			a[p + 1] = a[p + 2] = 0;
			continue;
		}
		int q = p + 3;
		while(a[q] != 0) {
			assert(q + 2 <= n);
			ans[ansSz++] = q - 2;
			a[q - 1] = 0;
			q += 2;
		}
		while(q >= p + 3) {
			ans[ansSz++] = q - 2;
			a[q - 2] = 0;
			q -= 2;
		}
	}
	assert(ansSz <= n);
	printf("YES\n%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d ", ans[i]);
	printf("\n");
}

/*
0 1 1 1 0 1 1 1 0
 1 0 0 1 1 0 0 1
*/

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