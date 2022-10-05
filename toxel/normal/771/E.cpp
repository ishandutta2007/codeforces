#include<bits/stdc++.h>
#define ll long long

const int N = 300010;
const int M = 3;

int t[M][N], sit[M][N], dp[N];
int n;
ll pre[M][N];
std::map <ll, int> Hash;
std::map <std::pair <int, int>, int> ans;

int solve(int x, int y){
	if (ans.count({x, y})){
		return ans[{x, y}];
	}
	int ret = dp[std::min(x, y)];
	if (x == y){
		return dp[x];
	}
	if (x > y && ~sit[0][x]){
		ret = std::max(ret, solve(sit[0][x], y) + 1);
	}
	if (x < y && ~sit[1][y]){
		ret = std::max(ret, solve(x, sit[1][y]) + 1);
	}
	return ans[{x, y}] = ret;
}		

int main(){
	memset(sit, -1, sizeof(sit));
	scanf("%d", &n);
	for (int i = 0; i < M - 1; ++ i){
		for (int j = 1; j <= n; ++ j){
			scanf("%d", &t[i][j]);
			if (i){
				t[M - 1][j] = t[0][j] + t[1][j];
			}
		}
	}
	for (int i = 0; i < M; ++ i){
		Hash.clear();
		Hash[0] = 0;
		for (int j = 1; j <= n; ++ j){
			pre[i][j] = pre[i][j - 1] + t[i][j];
			if (Hash.count(pre[i][j])){
				sit[i][j] = Hash[pre[i][j]];
			}
			if (~sit[i][j - 1]){
				sit[i][j] = std::max(sit[i][j], sit[i][j - 1]);
			}
			Hash[pre[i][j]] = j;
		}
	}
	for (int i = 1; i <= n; ++ i){
		dp[i] = dp[i - 1];
		if (~sit[2][i]){
			dp[i] = std::max(dp[i], dp[sit[2][i]] + 1);
		}
		if (~sit[0][i]){
			dp[i] = std::max(dp[i], solve(sit[0][i], i) + 1);
		}
		if (~sit[1][i]){
			dp[i] = std::max(dp[i], solve(i, sit[1][i]) + 1);
		}
	}
	return printf("%d\n", dp[n]), 0;
}