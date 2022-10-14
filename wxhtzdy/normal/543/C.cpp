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

const int N = 20;
int n, m;
int a[N][N];
char s[N][N];
int dp[1 << N];
int nmask[N][N];
int nsum[N][N];

int main()
{
	startTime = clock();

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int mx = 0;
			for (int k = 0; k < n; k++) {
				if (s[i][j] != s[k][j])
					continue;
				nmask[i][j] |= (1 << k);
				nsum[i][j] += a[k][j];
				mx = max(mx, a[k][j]);
			}
			nsum[i][j] -= mx;
		}
	}
	for (int mask = 1; mask < (1 << n); mask++)
		dp[mask] = 1e9;
	for (int mask = 1; mask < (1 << n); mask++) {
		int idx = -1;
		for (int j = 0; j < n; j++)
			if (mask >> j & 1) {
				idx = j;
				break;
			}
		for (int j = 0; j < m; j++) {			
			dp[mask] = min(dp[mask], dp[mask & (mask ^ nmask[idx][j])] + nsum[idx][j]);
			dp[mask] = min(dp[mask], dp[mask ^ (1 << idx)] + a[idx][j]);
		}
	}
	printf("%d", dp[(1 << n) - 1]);

	return 0;
}