#include<bits/stdc++.h>

const int N = 100010;
const int M = 26;

std::vector <int> dp[N];
int fail[N], next[N][M];
char s[N], t[N];

int main(){
	//freopen("data.txt", "r", stdin);
	scanf("%s%s", s, t);
	int lent = strlen(t), lens = strlen(s);
	if (lent > lens){
		return printf("0\n"), 0;
	}
	for (int i = 0; i < std::min(N, lens + 10); ++ i){
		dp[i].resize(lent + 10);
	}
	fail[0] = -1;
	for (int i = 1, j = -1; i <= lent; ++ i){
		while (j >= 0 && t[j] != t[i - 1]){
			j = fail[j];
		}
		fail[i] = ++ j;
	}
	for (int i = 0; i <= lent; ++ i){
		for (int j = 0; j < M; ++ j){
			int k = i;
			while (k >= 0 && 'a' + j != t[k]){
				k = fail[k];
			}
			next[i][j] = k + 1;
		}
	}
	for (int i = 0; i < N; ++ i){
		for (auto &u : dp[i]){
			u = -1;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < lens; ++ i){
		for (int j = 0; j <= lent; ++ j){
			if (dp[i][j] == -1){
				continue;
			}
			for (int k = 0; k < M; ++ k){
				if (s[i] == '?' || s[i] == 'a' + k){
					int x = next[j][k];
					if (x == lent){
						x = fail[x];
						dp[i + 1][x] = std::max(dp[i + 1][x], dp[i][j] + 1);
					}
					else{
						dp[i + 1][x] = std::max(dp[i + 1][x], dp[i][j]);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++ i){
		for (auto u : dp[i]){
			ans = std::max(ans, u);
		}
	}
	return printf("%d\n", ans), 0;
}