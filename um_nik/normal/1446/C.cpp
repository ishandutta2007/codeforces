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

const int S = (int)7e6;
const int K = 30;
int g[S][2];
int n, m = 1;
int ans = 1;

void dfs(int v, int x) {
	if (g[v][0] == 0 && g[v][1] == 0) {
		ans = max(ans, x);
		return;
	}
	if (g[v][0] != 0 && g[v][1] != 0) x++;
	for (int c = 0; c < 2; c++) {
		if (g[v][c] != 0)
			dfs(g[v][c], x);
	}
} 

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		int v = 0;
		for (int k = K - 1; k >= 0; k--) {
			int c = (x >> k) & 1;
			if (g[v][c] == 0) g[v][c] = m++;
			v = g[v][c];
		}
	}
	dfs(0, 1);
	printf("%d\n", n - ans);

	return 0;
}