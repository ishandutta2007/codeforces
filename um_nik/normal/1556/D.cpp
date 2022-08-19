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

const int N = 100100;
int n, k;
int aa[N];
int a[N];
int b[6];

int getFromAndOr(int x, int a, int o) {
	return a ^ (o & (~x));
}

int getAnd(int x, int y) {
#ifdef LOCAL
	return aa[x] & aa[y];
#endif
	printf("and %d %d\n", x + 1, y + 1);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
int getOr(int x, int y) {
#ifdef LOCAL
	return aa[x] | aa[y];
#endif
	printf("or %d %d\n", x + 1, y + 1);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}

void init() {
	int sz = 0;
	for (int i = 0; i < 3; i++)
		for (int j = i + 1; j < 3; j++) {
			b[sz++] = getAnd(i, j);
			b[sz++] = getOr(i, j);
		}
	a[0] = b[1] & b[3];
	assert((a[0] & b[4]) == b[4]);
	a[0] ^= b[4];
	a[0] ^= b[0] & b[2];
	for (int i = 0; i < 2; i++)
		a[i + 1] = getFromAndOr(a[0], b[2 * i], b[2 * i + 1]);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);

//	for (int i = 0; i < n; i++)
//		aa[i] = myRand(1000000);

	init();
	for (int i = 3; i < n; i++)
		a[i] = getFromAndOr(a[0], getAnd(0, i), getOr(0, i));
	
//	for (int i = 0; i < n; i++)
//		assert(a[i] == aa[i]);

	sort(a, a + n);

	printf("finish %d\n", a[k - 1]);

	return 0;
}