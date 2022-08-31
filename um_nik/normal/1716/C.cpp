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
int a[2][N];
int b[2][N];
int c[2][N];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			if (i + j > 0) a[i][j]++;
		}
	b[0][n] = b[1][n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int k = 0; k < 2; k++) {
			b[k][i] = max(max(a[k ^ 1][i], a[k][i] + 2 * (n - i) - 1), b[k][i + 1] + 1);
		}
	}
	int ans = (int)1e9 + (int)1e8;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		int k = i & 1;
		ans = min(ans, max(cur, b[k][i]));
		cur = max(cur, a[k][i] + 2 * (n - i) - 1);
		cur = max(cur, a[k ^ 1][i] + 2 * (n - i) - 2);
	}
	printf("%d\n", ans);
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