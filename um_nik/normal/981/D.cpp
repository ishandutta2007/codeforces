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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 55;
ll a[N];
ll sum[N][N];
int n, k;
bool dp[N][N];

bool solve(ll X) {
	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = 0;
	dp[0][0] = 1;
	for (int it = 0; it < k; it++)
		for (int i = 0; i < n; i++) {
			if (!dp[it][i]) continue;
			for (int j = i + 1; j <= n; j++)
				if ((sum[i][j] & X) == X)
					dp[it + 1][j] = 1;
		}
	return dp[k][n];
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int l = 0; l < n; l++)
		for (int r = l + 1; r <= n; r++) {
			sum[l][r] = 0;
			for (int i = l; i < r; i++)
				sum[l][r] += a[i];
		}
	ll ans = 0;
	for (int i = 60; i >= 0; i--) {
		ans ^= 1LL << i;
		if (!solve(ans)) ans ^= 1LL << i;
	}
	printf("%lld\n", ans);

	return 0;
}