#include<bits/stdc++.h>

const int N = 5010;

int cnt[N];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		++ cnt[x];
	}
	for (int i = 1; i < N; ++ i){
		cnt[i] += cnt[i - 1];
	}
	int ans = INT_MAX;
	for (int i = 1; i < N; ++ i){
		for (int j = i; j <= std::min(N - 1, i << 1); ++ j){
			ans = std::min(ans, n - (cnt[j] - cnt[i - 1]));
		}
	}
	printf("%d\n", ans);
	return 0;
}