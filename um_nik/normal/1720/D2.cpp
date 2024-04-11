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

const int N = 300300;
const int M = (int)1e7 + 5;
const int LOG = 30;
int n, m;
int go[M][2];
int trieDp[M][2];
int a[N];
int dp[N];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	while(m > 0) {
		m--;
		go[m][0] = go[m][1] = 0;
		trieDp[m][0] = trieDp[m][1] = 0;
	}
	m = 1;
	for (int i = 0; i < n; i++) {
		int x = a[i] ^ i;
		dp[i] = 0;
		int v = 0;
		for (int k = LOG - 1; k >= 0; k--) {
			int c = (x >> k) & 1;
			int u = go[v][c ^ 1];
			if (u != 0) {
				dp[i] = max(dp[i], trieDp[u][(i >> k) & 1]);
			}
			if (go[v][c] == 0) break;
			v = go[v][c];
		}
		dp[i]++;
		v = 0;
		for (int k = LOG - 1; k >= 0; k--) {
			int c = (x >> k) & 1;
			if (go[v][c] == 0) go[v][c] = m++;
			v = go[v][c];
			trieDp[v][(a[i] >> k) & 1] = max(trieDp[v][(a[i] >> k) & 1], dp[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
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