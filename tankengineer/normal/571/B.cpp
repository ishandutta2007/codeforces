#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5005, L = 300005;

int n, k, l, m;

int dp[N], a[L];

const int INF = 2000000009;

int cost(int i, int l) {
	if (i >= n) {
		return 0;
	}
	if (i + l > n) {
		return a[n - 1] - a[i];
	} else {
		return a[i + l - 1] - a[i];
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	l = n / k;
	m = n % k;
	for (int i = 0; i <= k; ++i) {
		dp[i] = INF;
	}
	dp[0] = 0;
	for (int i = 0; i < k; ++i) {
		for (int j = i; j >= 0; --j) {
			dp[j + 1] = min(dp[j + 1], dp[j] + cost(i * l + j, l + 1));
			dp[j] = dp[j] + cost(i * l + j, l);
		}
	}
	printf("%d\n", dp[m]);
	return 0;
}