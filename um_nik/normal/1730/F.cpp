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

const int INF = (int)1e8;
const int N = 5050;
const int K = 10;
const int M = (1 << 8) + 3;
int n, k;
int a[N];
int b[N];
int dp[2][K][M];
int ppc[(1 << 17) + 3];
int I = 0;

void eprintMask(int mask, int len) {
	for (int i = 0; i < len; i++)
		eprintf("%d", (mask >> i) & 1);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int mask = 1; mask < (1 << 17); mask++)
		ppc[mask] = ppc[mask >> 1] + (mask & 1);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			if (abs(a[i] - a[j]) <= k) {
				b[a[j]] ^= 1 << (k + a[i] - a[j]);
			} else if (a[i] > a[j]) {
				I++;
			}
		}
	for (int i = 0; i < n && i < k; i++)
		for (int j = i + 1; j <= k; j++)
			b[i] ^= 1 << (k - j);
	for (int i = 0; i <= k; i++)
		for (int mask = 0; mask < (1 << k); mask++)
			dp[0][i][mask] = INF;
	dp[0][0][(1 << k) - 1] = 2 * I;
	for (int p = 0; p < n; p++) {
		//eprintf("pos = %d\n", p);
		for (int i = 0; i <= k; i++)
			for (int mask = 0; mask < (1 << k); mask++)
				dp[1][i][mask] = INF;
		for (int x = 0; x <= k; x++)
			for (int mask = 0; mask < (1 << k); mask++) {
				if (dp[0][x][mask] == INF) continue;
				//eprintf("x = %d, mask = ", x);
				//eprintMask(mask, k);
				//eprintf(" -- %d\n", dp[0][x][mask]);
				for (int y = -k; y <= k; y++) {
					if (p + y < 0 || p + y >= n) continue;
					int w = dp[0][x][mask];
					int nx = x - 1;
					int nmask = 0;
					if (p - 1 + x < p + y) {
						nx = y;
						nmask = mask | (1 << k);
						int d = (p + y) - (p - 1 + x);
						//if (d > k) continue;
						nmask++;
						if (((nmask >> d) << d) != nmask) continue;
						nmask >>= d;
						nmask--;
						w += ppc[nmask ^ b[p + y]];
						dp[1][nx][nmask] = min(dp[1][nx][nmask], w);
					} else if (p - 1 + x > p + y) {
						int d = (p - 1 + x) - (p + y);
						if (d > k) continue;
						d = k - d;
						if ((mask >> d) & 1) continue;
						nmask = mask | (1 << d);
						nx = x - 1;
						int z = mask | (1 << k);
						z++;
						z <<= k - d;
						z--;
						w += ppc[z ^ b[p + y]];
						dp[1][nx][nmask] = min(dp[1][nx][nmask], w);
					}
				}
			}
		for (int i = 0; i <= k; i++)
			for (int mask = 0; mask < (1 << k); mask++)
				dp[0][i][mask] = dp[1][i][mask];
	}
	int ans = INF;
	for (int i = 0; i <= k; i++)
		for (int mask = 0; mask < (1 << k); mask++)
			ans = min(ans, dp[0][i][mask]);
	printf("%d\n", ans / 2);

	return 0;
}