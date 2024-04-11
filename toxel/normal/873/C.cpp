#include<bits/stdc++.h>

const int N = 110;
typedef std::pair <int, int> pii;

int mat[N][N];
int n, m, k;
int pre[N];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			scanf("%d", &mat[i][j]);
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int j = 1; j <= m; ++ j){
		for (int i = 1; i <= n; ++ i){
			pre[i] = pre[i - 1] + mat[i][j];
		}
		pii max = {-1, 0};
		for (int i = 1; i <= n - k + 1; ++ i){
			max = std::max(max, {pre[i + k - 1] - pre[i - 1], -pre[i - 1]});
		}
		ans1 += max.first, ans2 -= max.second;
	}
	return printf("%d %d\n", ans1, ans2), 0;
}