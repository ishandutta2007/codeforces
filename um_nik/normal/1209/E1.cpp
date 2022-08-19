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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 12;
const int M = (1 << 12) + 3;
int n, m;
int a[N][M];
pii b[N];
int c[M];
int d[M];
int dp[N + 1][M];

void fillC(int v) {
	d[0] = 0;
	for (int mask = 1; mask < (1 << n); mask++) {
		int k = 0;
		while(((mask >> k) & 1) == 0) k++;
		d[mask] = d[mask ^ (1 << k)] + a[k][v];
	}
	for (int mask = 0; mask < (1 << n); mask++) {
		c[mask] = d[mask];
		for (int i = 0; i < n; i++) {
			int x = mask << i;
			int y = x & ((1 << n) - 1);
			x ^= y;
			x >>= n;
			c[mask] = max(c[mask], d[x | y]);
		}
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		b[i] = mp(0, -1);
	for (int j = 0; j < m; j++) {
		pii t = mp(0, j);
		for (int i = 0; i < n; i++)
			t.first = max(t.first, a[i][j]);
		for (int i = 0; i < n; i++)
			if (t > b[i])
				swap(t, b[i]);
	}
	m = 0;
	while(m < n && b[m].second != -1) m++;
	for (int i = 0; i <= m; i++)
		for (int mask = 0; mask < (1 << n); mask++)
			dp[i][mask] = 0;
	for (int i = 0; i < m; i++) {
		fillC(b[i].second);
		for (int mask = 0; mask < (1 << n); mask++)
			for (int smask = mask; smask >= 0; smask = (smask - 1) & mask) {
				dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask ^ smask] + c[smask]);
				if (smask == 0) break;
			}
	}
	printf("%d\n", dp[m][(1 << n) - 1]);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}