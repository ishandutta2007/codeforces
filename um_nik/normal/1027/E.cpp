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

const int MOD = 998244353;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}

const int N = 505;
int n, k;
int a[N];
int b[N];
int dp[N];
int sum[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int m = 1; m <= n; m++) {
		for (int i = 0; i <= n + 2; i++) {
			dp[i] = sum[i] = 0;
		}
		dp[0] = 1;
		sum[1] = 1;
		for (int i = 1; i <= n; i++) {
			dp[i] = sub(sum[i], sum[max(0, i - m)]);
			sum[i + 1] = add(sum[i], dp[i]);
		}
		a[m] = dp[n];
	}

	for (int i = 1; i <= n; i++)
		b[i] = sub(a[i], a[i - 1]);

	/*
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
*/

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = add(ans, mult(b[i], a[min(n, (k - 1) / i)]));
	}
	printf("%d\n", mult(ans, 2));

	return 0;
}