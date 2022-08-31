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

int gcd(int x, int y) {
	return (y == 0 ? x : gcd(y, x % y));
}

const ll INF = (ll)1e17;
const int N = (int)1e6 + 7;
ll a[N];
int n, g;
ll dp[2][2];

ll solveDp(int r) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			dp[i][j] = -INF;
	dp[0][0] = 0;
	for (int i = r; i < n; i += g) {
		dp[1][0] = dp[1][1] = -INF;
		for (int x = 0; x < 2; x++)
			for (int y = 0; y < 2; y++) {
				ll w = a[i];
				if (x ^ y) w *= -1;
				w += dp[0][x];
				dp[1][y] = max(dp[1][y], w);
			}
		dp[0][0] = dp[1][0];
		dp[0][1] = dp[1][1];
	}
	return dp[0][0];
}
ll solve2() {
	ll ans = 0;
	for (int r = 0; r < g; r++)
		ans += solveDp(r);
	return ans;
}
void solve() {
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	g = 0;
	while(m--) {
		int x;
		scanf("%d", &x);
		g = gcd(g, x);
	}
	ll ans = solve2();
	for (int i = 0; i < g; i++)
		a[i] *= -1;
	ans = max(ans, solve2());
	printf("%lld\n", ans);
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