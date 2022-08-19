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

const int N = 500500;
int a[N], b[N];
int n, d;

bool solve(int c) {
	int x = d;
	for (int i = 0; i < n; i++) {
		b[i] = 0;
		if (x <= 0) continue;
		if (x >= a[i]) {
			b[i] = 1;
			c--;
			continue;
		}
		if (i == n - c) {
			b[i] = 1;
			x--;
			c--;
		}
	}
	return c <= 0;
}

void solve() {
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int l = 0, r = n + 1;
	while(r - l > 1) {
		int x = (l + r) / 2;
		if (solve(x))
			l = x;
		else
			r = x;
	}
	solve(l);
	for (int i = 0; i < n; i++)
		printf("%d", b[i]);
	printf("\n");
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