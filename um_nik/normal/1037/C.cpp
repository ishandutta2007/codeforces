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

const int INF = (int)1e7 + 6;
const int N = (int)1e6 + 7;
char s[N], p[N];
int n;
int dp[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s %s", s, p);
	for (int i = 0; i <= n; i++)
		dp[i] = INF;
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + (int)(s[i] != p[i]));
		if (i < n - 1 && s[i] == p[i + 1] && s[i + 1] == p[i])
			dp[i + 2] = min(dp[i + 2], dp[i] + 1);
	}
	printf("%d\n", dp[n]);

	return 0;
}