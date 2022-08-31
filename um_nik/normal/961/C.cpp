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

const int INF = (int)1e8 + 3;

const int N = 111;
int a[N][N];
int b[4];
int n;
int dp[10][10];
char s[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int k = 0; k < 4; k++)
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			for (int j = 0; j < n; j++)
				if ((int)(s[j] - '0') ^ (i & 1) ^ (j & 1))
					b[k]++;
		}
//	for (int i = 0; i < 4; i++)
//		printf("%d ", b[i]);
	for (int i = 0; i <= 4; i++)
		for (int j = 0; j <= 4; j++)
			dp[i][j] = INF;
	dp[0][0] = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j <= i; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + b[i]);
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (n * n - b[i]));
		}
	printf("%d\n", dp[4][2]);

	return 0;
}