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
int n;
int g[N][N];
int ord[N];
ll ans[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &g[i][j]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ord[i]);
		ord[i]--;
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int v = 0; v < n; v++)
			for (int u = 0; u < n; u++) {
				g[v][u] = min(g[v][u], g[v][ord[i]] + g[ord[i]][u]);
			}
		ll res = 0;
		for (int j = i; j < n; j++)
			for (int k = i; k < n; k++)
				res += g[ord[j]][ord[k]];
		ans[i] = res;
	}
	for (int i = 0; i < n; i++)
		printf("%lld\n", ans[i]);

	return 0;
}