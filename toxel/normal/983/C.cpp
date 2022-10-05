#include<bits/stdc++.h>

const int N = 2010;
const int M = 10010;
const int INF = 0x7f7f7f7f;

std::vector <int> solve(int state){
	std::vector <int> vec;
	for (int i = 0; i < 4; ++ i){
		vec.push_back(state % 10);
		state /= 10;
	}
	std::reverse(vec.begin(), vec.end());
	return vec;
}

int tostate(std::vector <int> vec){
	int ret = 0;
	for (auto u : vec){
		ret = ret * 10 + u;
	}
	return ret;
}

int dp[N][M];
int a[N], b[N];

int main(){
	int n;
	scanf("%d", &n);
	a[1] = 1;
	for (int i = 2; i <= n + 1; ++ i){
		scanf("%d%d", &a[i], &b[i]);
	}
	memset(dp, 0x7f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j < 10000; ++ j){
			if (dp[i - 1][j] == INF) continue;
			std::vector <int> vec = solve(j);
			bool flag = true;
			for (int k = 0; k < 3; ++ k){
				if (vec[k] > vec[k + 1]){
					flag = false;
					break;
				}
			}
			if (!flag){
				continue;
			}
			for (int k = 1; k <= 9; ++ k){
				std::vector <int> newvec;
				int min = std::min(k, std::min(a[i], a[i + 1]));
				int max = std::max(k, std::max(a[i], a[i + 1]));
				for (auto u : vec){
					if (u != 0 && (min > u || max < u)){
						newvec.push_back(u);
					}
				}
				if (newvec.size() == 4) continue;
				int ans = dp[i - 1][j] + std::abs(a[i] - k) + std::abs(a[i + 1] - k);
				newvec.push_back(b[i + 1]);
				while (newvec.size() < 4){
					newvec.push_back(0);
				}
				std::sort(newvec.begin(), newvec.end());
				int &u = dp[i][tostate(newvec)];
				u = std::min(u, ans);
			}
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i < M; ++ i){
		if (dp[n][i] == INF) continue;
		std::vector <int> vec = solve(i);
		bool flag = true;
		for (int k = 0; k < 3; ++ k){
			if (vec[k] > vec[k + 1]){
				flag = false;
				break;
			}
		}
		if (!flag){
			continue;
		}
		int max = 0, min = INT_MAX;
		for (auto u : vec){
			if (u){
				max = std::max(u, max);
				min = std::min(u, min);
			}
		}
		if (!max){
			ans = std::min(ans, dp[n][i]);
		}
		else{
			ans = std::min(ans, dp[n][i] + std::abs(max - min) + std::min(std::abs(a[n + 1] - max), std::abs(a[n + 1] - min)));
		}
	}
	ans += 2 * n;
	printf("%d\n", ans);
	return 0;
}