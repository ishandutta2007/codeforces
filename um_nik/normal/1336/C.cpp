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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
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


const int N = 3030;
char s[N], p[N];
int n, m;
ll dp[N][N];

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s %s", s, p);
	n = strlen(s);
	m = strlen(p);
	for (int i = 0; i <= m; i++)
		dp[i][i] = 1;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int l = 0; l <= m; l++) {
			int r = min(m, l + i);
			if (r < m) {
				if (s[i] == p[r])
					dp[l][r + 1] = add(dp[l][r + 1], dp[l][r]);
			}
			if (l > 0 && s[i] == p[l - 1])
				dp[l - 1][r] = add(dp[l - 1][r], dp[l][r]);
			if (l == m) dp[m][m] = add(dp[m][m], dp[m][m]);
		}
		ans = add(ans, dp[0][m]);
	}
	printf("%lld\n", ans);

	return 0;
}