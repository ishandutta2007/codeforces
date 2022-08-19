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

const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}

const int N = 1010;
char s[N];
int k;
int a[N];
int dp[N][N][2];

int myppc(int x) {
	int res = 0;
	for (int i = 0; i < 20; i++)
		if ((x >> i) & 1)
			res++;
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	int n = strlen(s);
	scanf("%d", &k);
	if (k == 0) {
		printf("1\n");
		return 0;
	}
	k--;
	a[1] = 0;
	for (int x = 2; x < N; x++) {
		a[x] = a[myppc(x)] + 1;
	}

	dp[0][0][1] = 1;
	for (int i = 0; i < n; i++)
		for (int x = 0; x <= i; x++) {
			dp[i + 1][x][0] = add(dp[i + 1][x][0], dp[i][x][0]);
			dp[i + 1][x + 1][0] = add(dp[i + 1][x + 1][0], dp[i][x][0]);
			if (s[i] == '0') {
				dp[i + 1][x][1] = add(dp[i + 1][x][1], dp[i][x][1]);
			} else {
				dp[i + 1][x][0] = add(dp[i + 1][x][0], dp[i][x][1]);
				dp[i + 1][x + 1][1] = add(dp[i + 1][x + 1][1], dp[i][x][1]);
			}
		}

	int ans = 0;
	for (int x = 1; x <= n; x++) {
		if (a[x] != k) continue;
		ans = add(ans, add(dp[n][x][0], dp[n][x][1]));
	}
	if (k == 0) ans--;
	if (ans < 0) ans += MOD;
	printf("%d\n", ans);

	return 0;
}