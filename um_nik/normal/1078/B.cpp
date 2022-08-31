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

const int N = 103;
const int S = (int)2e4 + 59;
const int Z = S / 2;
int a[N];
int cnt[N];
int dp[S];
int ndp[S];
int n;
int ans = 0;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int diff = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (cnt[a[i]] == 0) diff++;
		cnt[a[i]]++;
	}
	if (diff <= 2) {
		printf("%d\n", n);
		return 0;
	}
	for (int x = 1; x < N; x++) {
		if (cnt[x] <= ans) continue;
		for (int i = 0; i < S; i++)
			dp[i] = N;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < S; j++)
				ndp[j] = N;
			int y = a[i] - x;
			if (y == 0) continue;
			for (int z = 0; z < S; z++) {
				int w = dp[z];
				if (z == Z) w = 0;
				if (w == N) continue;
				ndp[z + y] = w + 1;
			}
			for (int j = 0; j < S; j++)
				dp[j] = min(dp[j], ndp[j]);
		}
		ans = max(ans, min(cnt[x], dp[Z] - 1));
	}
	printf("%d\n", ans);

	return 0;
}