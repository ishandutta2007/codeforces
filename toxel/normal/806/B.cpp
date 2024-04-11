#include<bits/stdc++.h>

const int N = 200;
const int M = 5;

int mark[] = {500, 1000, 1500, 2000, 2500, 3000};
int frac[] = {1, 2, 4, 8, 16, 32};
int min = INT_MAX, n;
int a[N][M], cnt[M], nowmark[M];

int calc(int n){
	int ret = 0;
	for (int i = 0; i < M; ++ i){
		ret += a[n][i] == -1 ? 0 : mark[nowmark[i]] - mark[nowmark[i]] * a[n][i] / 250;
	}
	return ret;
}

void dfs(int now){
	if (now == M){
		if (calc(0) <= calc(1)){
			return;
		}
		int ans = 0;
		for (int i = 0; i < M; ++ i){
			int flag;
			if (cnt[i] * frac[nowmark[i]] > n){
				flag = 1;
			}
			else if (nowmark[i] != M && cnt[i] * frac[nowmark[i] + 1] <= n){
				flag = -1;
			}
			else{
				flag = 0;
			}
			if (flag == -1 && a[0][i] == -1){
				return;
			}
			if (flag == 1){
				ans = std::max(ans, frac[nowmark[i]] * cnt[i] - n);
			}
			else if (flag == -1){
				ans = std::max(ans, (n - frac[nowmark[i] + 1] * cnt[i] + frac[nowmark[i] + 1] - 2) / (frac[nowmark[i] + 1] - 1));
			}
		}
		for (int i = 0; i < M; ++ i){
			if (a[0][i] == -1 && (cnt[i] * frac[nowmark[i]] > n + ans || nowmark[i] != M && cnt[i] * frac[nowmark[i] + 1] <= n + ans)){
				return;
			}
		}
		min = std::min(min, ans);
		return;
	}
	for (int i = 0; i < M + 1; ++ i){
		nowmark[now] = i;
		dfs(now + 1);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < M; ++ j){
			scanf("%d", &a[i][j]);
			if (a[i][j] != -1){
				++ cnt[j];
			}
		}
	}
	dfs(0);
	return printf("%d\n", min == INT_MAX ? -1 : min), 0;
}