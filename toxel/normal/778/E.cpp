#include<bits/stdc++.h>

const int N = 1010;
const int M = 10;

char s[N][N];
int n, a[N], pre[N], dp[N][N], len[N], c[M];
std::vector <int> vec[M + 1];

void sort(int i){
	for (int j = 0; j <= M; ++ j){
		vec[j].clear();
	}
	for (int j = 1; j <= n; ++ j){
		s[a[j]][i] != '\0' ? vec[s[a[j]][i] - '0'].push_back(a[j]) : vec[M].push_back(a[j]);
		pre[j] = a[j];
	}
	int cnt = 0;
	for (int j = M - 1; j >= 0; -- j){
		for (auto u : vec[j]){
			a[++ cnt] = u;
		}
	}
	for (auto u : vec[M]){
		a[++ cnt] = u;
	}
}

int main(){
	memset(dp, -1, sizeof(dp));
	memset(s, 0, sizeof(s));
	scanf("%s%d", s[0], &n);
	for (int i = 1; i <= n; ++ i){
		a[i] = i;
	}
	len[0] = strlen(s[0]);
	std::reverse(s[0], s[0] + len[0]);
	for (int i = len[0]; i < N; ++ i){
		s[0][i] = '0';
	}
	for (int i = 1; i <= n; ++ i){
		scanf("%s", s[i]);
		len[i] = strlen(s[i]);
		std::reverse(s[i], s[i] + len[i]);
		for (int j = len[i]; j < N; ++ j){
			s[i][j] = '0';
		}
	}
	for (int i = 0; i < M; ++ i){
		scanf("%d", &c[i]);
	}
	dp[0][0] = 0;
	for (int i = 1; i < N; ++ i){
		sort(i - 1);
		int left, right;
		if (s[0][i - 1] != '?'){
			left = right = s[0][i - 1] - '0';
		}
		else{
			left = (i == len[0]);
			right = 9;
		}
		for (int j = left; j <= right; ++ j){
			int sum = 0, cnt = 0;
			for (int k = 1; k <= n; ++ k){
				int x = s[a[k]][i - 1] - '0';
				if (i <= len[0] || i <= len[a[k]]){
					sum += c[(x + j) % 10];
					cnt += ((x + j) >= 10);
				}
			}
			for (int k = 0; k <= n; ++ k){
				if (k){
					int x = s[pre[k]][i - 1] - '0';
					if (i > len[0] && i > len[pre[k]]){
						sum += c[1];
					}
					else{
						x += j;
						if (x == 9){
							sum += c[0] - c[9];
							++ cnt;
						}
						else{
							sum += c[x % 10 + 1] - c[x % 10];
						}
					}
				}
				if (dp[i - 1][k] == -1){
					continue;
				}
				dp[i][cnt] = std::max(dp[i][cnt], dp[i - 1][k] + sum);
			}
		}
	}
	return printf("%d\n", dp[N - 1][0]), 0;
}