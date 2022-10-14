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
#include <iomanip>
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

const int N = 105;
int n;
int a[N][N];

int main()
{
	startTime = clock();

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || n - i + 1 == j || (i == (n + 1) / 2) || (j == (n + 1) / 2)) {
				ans += a[i][j];
			}
		}
	}
	printf("%d", ans);
	return 0;
}