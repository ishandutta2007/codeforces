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

const int N = 200200;
int n, k;
int a[N];
int b[N];
int c[N];

bool check() {
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (p < k && c[p] >= b[i]) p++;
	}
	return p == k;
}

bool solve() {
	for (int t = 0; t < 2; t++) {
		for (int i = 0; i < k; i++)
			c[i] = ((i & 1) == t ? 0 : 1);
		if (check()) return true;
	}
	return false;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int l = 0, r = (int)1e9 + 7;
	while(r - l > 1) {
		int x = (l + r) / 2;
		for (int i = 0; i < n; i++)
			b[i] = a[i] > x;
		if (solve())
			r = x;
		else
			l = x;
	}
	printf("%d\n", r);

	return 0;
}