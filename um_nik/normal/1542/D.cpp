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


const ll MOD = 998244353;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}

const int N = 505;
int dp[N][N];
int a[N];
pii ord[N];
int n, m;
bool b[N];

void solve(int p) {
	for (int x = 0; x <= n; x++)
		for (int y = 0; y <= n; y++)
			dp[x][y] = 0;
	dp[0][0] = 1;
	for (int i = 0; i < p; i++) {
		for (int x = 0; x <= i; x++) {
			if (dp[i][x] == 0) continue;
			dp[i + 1][x] = add(dp[i + 1][x], dp[i][x]);
			if (a[i] == -1) {
				dp[i + 1][max(0, x - 1)] = add(dp[i + 1][max(0, x - 1)], dp[i][x]);
			} else {
				dp[i + 1][x + (int)b[i]] = add(dp[i + 1][x + (int)b[i]], dp[i][x]);
			}
		}
	}
	for (int x = 0; x <= n; x++)
		dp[p + 1][x] = dp[p][x];
	for (int i = p + 1; i < n; i++) {
		for (int x = 0; x <= i; x++) {
			dp[i + 1][x] = add(dp[i + 1][x], dp[i][x]);
			if (a[i] == -1) {
				if (x > 0)
					dp[i + 1][max(0, x - 1)] = add(dp[i + 1][max(0, x - 1)], dp[i][x]);
			} else {
				dp[i + 1][x + (int)b[i]] = add(dp[i + 1][x + (int)b[i]], dp[i][x]);
			}
		}
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char t;
		scanf(" %c", &t);
		if (t == '-') {
			a[i] = -1;
		} else {
			scanf("%d", &a[i]);
			ord[m++] = mp(a[i], i);
		}
	}
	sort(ord, ord + m);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			b[j] = 0;
		for (int j = 0; j < i; j++)
			b[ord[j].second] = 1;
		solve(ord[i].second);
		int cur = 0;
		for (int x = 0; x <= n; x++)
			cur = add(cur, dp[n][x]);
		ans = add(ans, mult(cur, ord[i].first));
	}
	printf("%d\n", ans);

	return 0;
}