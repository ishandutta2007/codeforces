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

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	if (n == 4 && k == 3) {
		printf("-1\n");
		return;
	}
	if (k == 0) {
		for (int x = 0; x < n / 2; x++) {
			printf("%d %d\n", x, n - 1 - x);
		}
	} else if (k == n - 1) {
		printf("0 %d\n", n / 2 - 2);
		printf("%d %d\n", n / 2 - 1, n - 1);
		printf("%d %d\n", n / 2, n / 2 + 1);
		for (int x = 1; x < n / 2 - 2; x++) {
			printf("%d %d\n", x, n - 1 - x);
		}
	} else {
		printf("0 %d\n", n - 1 - k);
		printf("%d %d\n", k, n - 1);
		for (int x = 1; x < n / 2; x++) {
			if (x == k || x == n - 1 - k) continue;
			printf("%d %d\n", x, n - 1 - x);
		}
	}
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