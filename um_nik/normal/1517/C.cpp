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

const int N = 505;
int a[N][N];
int n;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i][i]);
	for (int it = 0; it < n; it++) {
		bool fnd = false;
		for (int x = 0; x + it < n; x++) {
			int y = x + it;
			int p = a[x][y] - it;
			assert(p > 0);
			if (p == 1) {
				assert(!fnd);
				fnd = true;
				continue;
			}
			if (!fnd) {
				assert(y + 1 < n);
				a[x][y + 1] = a[x][y];
			} else {
				assert(x > 0);
				a[x - 1][y] = a[x][y];
			}
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y <= x; y++)
			printf("%d ", a[y][x]);
		printf("\n");
	}

	return 0;
}