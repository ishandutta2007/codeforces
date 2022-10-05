#include<bits/stdc++.h>

const int N = 10010;
typedef std::pair <int, int> pii;

int a[N], x[N], dp[N];
pii p[N];

int main(){
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	int sum = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &x[i]);
		p[i] = {x[i] ^ 1, a[i]};
	}
	std::sort(p, p + n, std::greater <pii>());
	std::swap(l, r);
	l = sum - l;
	r = sum - r;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; ++ i){
		for (int j = N - 1; j >= 0; -- j){
			if (j + p[i].second >= N || dp[j] == -1) continue;
			int &u = dp[j + p[i].second];
			u = std::max(u, dp[j] + (!p[i].first && l <= j + p[i].second && j + p[i].second <= r));
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++ i){
		ans = std::max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}