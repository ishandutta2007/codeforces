#include<bits/stdc++.h>

const int N = 1010;
const int M = 26;
const int moder = 1e9 + 7;
int cnt[M][N], dp1[N][N], dp2[N][N], dp3[N][N], n, a[N];
char s[N];

int main(){
	s[0] = ' ';
	scanf("%d%s", &n, s + 1);
	int len = strlen(s) - 1;
	for (int i = 1; i <= len; ++ i){
		for (int j = 0; j < M; ++ j){
			cnt[j][i] = cnt[j][i - 1];
		}
		++ cnt[s[i] - 'a'][i];
	}
	for (int i = 0; i < M; ++ i){
		scanf("%d", &a[i]);
	}
	memset(dp3, 0x7f, sizeof(dp3));
	dp1[1][1] = dp2[1][1] = dp3[1][1] = 1;
	for (int i = 2; i <= n; ++ i){
		for (int j = 1; j < i; ++ j){
			dp1[i][i] = (dp1[i][i] + dp1[i - 1][j]) % moder;
			dp2[i][i] = std::max(dp2[i][i], dp2[i - 1][j]);
			dp3[i][i] = std::min(dp3[i][i], dp3[i - 1][j] + 1);
			bool flag = true;
			for (int k = 0; k < M; ++ k){
				if (cnt[k][i] - cnt[k][j - 1] && i - j + 1 > a[k]){
					flag = false;
					break;
				}
			}
			if (flag){
				dp1[i][j] = (dp1[i][j] + dp1[i - 1][j]) % moder;
				dp2[i][j] = std::max(dp2[i][j], std::max(dp2[i - 1][j], i - j + 1));
				dp3[i][j] = std::min(dp3[i][j], dp3[i - 1][j]);
			}
		}
	}
	int ans1 = 0, ans2 = 0, ans3 = INT_MAX;
	for (int i = 1; i <= n; ++ i){
		ans1 = (ans1 + dp1[n][i]) % moder;
		ans2 = std::max(ans2, dp2[n][i]);
		ans3 = std::min(ans3, dp3[n][i]);
	}
	return printf("%d\n%d\n%d\n", ans1, ans2, ans3), 0;
}