#include<bits/stdc++.h>

const int N = 5010;
const int M = 100010;
typedef std::pair <int, int> pii;

int a[N];
int dp[N][N];
int max[N];
std::vector <pii> vec[N];
int ans[M];
int pre[N][N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++ i){
		dp[i][i] = a[i];
	}
	for (int i = 1; i < n; ++ i){
		for (int j = 0; j + i < n; ++ j){
			dp[j][i + j] = dp[j][i + j - 1] ^ dp[j + 1][i + j];
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 0, l, r; i < q; ++ i){
		scanf("%d%d", &l, &r);
		-- l, -- r;
		vec[l].push_back({r, i});
	}
	for (int i = 0; i < n; ++ i){
		for (int j = i; j < n; ++ j){
			pre[i][j] = j ? std::max(pre[i][j - 1], dp[i][j]) : dp[i][j];
		}
	}
	for (int i = n - 1; i >= 0; -- i){
		for (int j = i; j < n; ++ j){
			max[j] = std::max(max[j], pre[i][j]);
		}
		for (auto u : vec[i]){
			ans[u.second] = max[u.first];
		}
	}
	for (int i = 0; i < q; ++ i){
		printf("%d\n", ans[i]);
	}
	return 0;
}