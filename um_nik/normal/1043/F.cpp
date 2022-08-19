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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 300300;
const int M = 64;
int p[N];
int a[N];
int n;
vector<int> d[N];
int dp[M];
int b[N];
int c[M];
int ans = M;

int solve(int X) {
	int k = (int)d[X].size();
	for (int mask = 0; mask < (1 << k); mask++) {
		int y = 1;
		for (int j = 0; j < k; j++) {
			if (((mask >> j) & 1) == 0) continue;
			y *= d[X][j];
		}
		c[mask] = b[y];
	}
	for (int i = 0; i < k; i++)
		for (int mask = 0; mask < (1 << k); mask++) {
			if ((mask >> i) & 1) continue;
			c[mask] -= c[mask ^ (1 << i)];
		}
	/*
	for (int mask = 0; mask < (1 << k); mask++)
		eprintf("%d ", c[mask]);
	eprintf("\n");
	*/
	for (int i = 0; i < k; i++)
		for (int mask = 0; mask < (1 << k); mask++) {
			if ((mask >> i) & 1) continue;
			c[mask ^ (1 << i)] += c[mask];
		}
	for (int mask = 1; mask < (1 << k); mask += 2)
		swap(c[mask], c[((1 << k) - 1) ^ mask]);
	for (int mask = 0; mask < (1 << k); mask++)
		dp[mask] = M;
	dp[(1 << k) - 1] = 0;
	for (int mask = (1 << k) - 1; mask > 0; mask--) {
		for (int smask = mask; smask > 0; smask = (smask - 1) & mask)
			if (c[smask] > 0)
				dp[mask ^ smask] = min(dp[mask ^ smask], dp[mask] + 1);
	}
	return dp[0];
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 1; i < N; i++)
		p[i] = -1;
	for (int x = 2; x < N; x++) {
		if (p[x] != -1) continue;
		for (int y = x; y < N; y += x)
			if (p[y] == -1)
				p[y] = x;
	}
	for (int x = 2; x < N; x++) {
		int y = x / p[x];
		d[x] = d[y];
		if (p[x] != p[y])
			d[x].push_back(p[x]);
	}
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		int k = (int)d[a[i]].size();
		for (int mask = 0; mask < (1 << k); mask++) {
			int y = 1;
			for (int j = 0; j < k; j++) {
				if (((mask >> j) & 1) == 0) continue;
				y *= d[a[i]][j];
			}
			b[y]++;
		}
	}
	for (int i = 0; i < n; i++)
		ans = min(ans, solve(a[i]) + 1);
	if (ans == M) ans = -1;
	printf("%d\n", ans);

	return 0;
}