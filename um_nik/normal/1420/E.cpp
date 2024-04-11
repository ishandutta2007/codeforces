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

const int INF = (int)1e7;
const int N = 82;
const int M = N * N / 4;
int dp[2][N][M];
int n, m, k;
int a[N];
int ans[N * N];

int sqr(int x) {
	return x * x;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	int len = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			len++;
		} else {
			a[m++] = len;
		}
	}
	k = len;

	eprintf("m = %d, k = %d\n", m, k);
	for (int i = 0; i < m; i++)
		eprintf("%d ", a[i]);
	eprintf("\n");

	for (int i = 0; i <= k; i++)
		for (int x = 0; x <= k * m; x++)
			dp[0][i][x] = INF;
	dp[0][0][0] = 0;
	//eprintf("new\n");
	for (int it = 0; it < m; it++) {
		//eprintf("it = %d\n", it);
		for (int i = 0; i <= k; i++)
			for (int x = 0; x <= k * m; x++)
				dp[1][i][x] = INF;
		for (int lst = 0; lst <= k; lst++)
			for (int op = 0; op <= k * m; op++) {
				//eprintf("%d %d\n", lst, op);
				if (dp[0][lst][op] == INF) continue;
				for (int nxt = lst; nxt <= k; nxt++) {
					int nop = op + abs(nxt - a[it]);
					dp[1][nxt][nop] = min(dp[1][nxt][nop], dp[0][lst][op] + sqr(nxt - lst));
				}
			}
		for (int i = 0; i <= k; i++)
			for (int x = 0; x <= k * m; x++)
				dp[0][i][x] = dp[1][i][x];
	}

	for (int lst = 0; lst <= k; lst++)
		for (int op = 0; op <= k * m; op++) {
			int nop = dp[0][lst][op] + sqr(k - lst);
			ans[op] = max(ans[op], (sqr(k) - nop) / 2);
		}
	for (int i = 1; i <= n * (n - 1) / 2; i++)
		ans[i] = max(ans[i], ans[i - 1]);
	for (int i = 0; i <= n * (n - 1) / 2; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}