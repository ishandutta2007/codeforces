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


ll MOD = 998244353;
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

struct Item {
	ll cnt, sum;

	Item() : cnt(0), sum(0) {}
	Item(ll _cnt, ll _sum) : cnt(_cnt), sum(_sum) {}

	Item operator + (const Item &I) const {
		return Item(add(cnt, I.cnt), add(sum, I.sum));
	}
	Item operator * (const Item &I) const {
		return Item(mult(cnt, I.cnt), add(mult(sum, I.cnt), mult(I.sum, cnt)));
	}
	Item operator * (const ll &k) const {
		return Item(mult(cnt, k), mult(sum, k));
	}
};

const int N = 505;
ll C[N][N];
Item dp[N];
Item dp2[N][N];

void precalc() {
	for (int i = 0; i < N; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);

	dp[0] = Item(1, 0);
	for (int n = 1; n < N; n++) {
		for (int x = 0; x < n; x++) {
			Item I = Item(n + 1, x * (x + 1) / 2 + (n - 1 - x) * (n - 1 - x + 1) / 2);
			dp[n] = dp[n] + I * dp[x] * dp[n - 1 - x] * C[n - 1][x];
		}
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d%lld", &n, &m, &MOD);

	precalc();
	dp2[0][0] = Item(1, 0);
	n++;
	for (int i = 0; i < n; i++)
		for (int x = 0; x <= m; x++) {
			if (x + n - i < m) continue;
			dp2[i + 1][x] = dp2[i + 1][x] + dp2[i][x];
			for (int y = 1; x + y <= m && i + y + 1 <= n; y++)
				dp2[i + y + 1][x + y] = dp2[i + y + 1][x + y] + dp2[i][x] * dp[y] * C[x + y][y];
		}
	printf("%lld\n", dp2[n][m].sum);

	return 0;
}