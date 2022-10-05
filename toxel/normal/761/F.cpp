#include<bits/stdc++.h>
#define ll long long

const int N = 1010;
const int M = 300010;
const int MAXN = 26;

char s[N][N], ch[M];
int cnt[N][N][MAXN], pre_cnt[N][N][MAXN];
ll a[M], b[M], c[M], d[M], n, m, kk, pre_temp[N][N], pre[N][N][MAXN];

int main(){
//	freopen("data.txt", "r", stdin);
//	freopen("orz.txt", "w", stdout);
	scanf("%I64d%I64d%I64d", &n, &m, &kk);
	for (int i = 1; i <= n; ++ i){
		scanf("%s", s[i] + 1);
	}
	for (int i = 0; i < kk; ++ i){
		scanf("%I64d%I64d%I64d%I64d", &a[i], &b[i], &c[i], &d[i]);
		getchar();
		ch[i] = getchar();
		int x = ch[i] - 'a';
		++ cnt[a[i]][b[i]][x];
		-- cnt[a[i]][d[i] + 1][x];
		-- cnt[c[i] + 1][b[i]][x];
		++ cnt[c[i] + 1][d[i] + 1][x];
	}
	for (int k = 0; k < MAXN; ++ k){
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= m; ++ j){
				cnt[i][j][k] += cnt[i][j - 1][k];
			}
		}
		for (int j = 1; j <= m; ++ j){
			for (int i = 1; i <= n; ++ i){
				cnt[i][j][k] += cnt[i - 1][j][k];
			}
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			int x = kk;
			for (int k = 0; k < MAXN; ++ k){
				x -= cnt[i][j][k];
			}
			cnt[i][j][s[i][j] - 'a'] += x;
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			pre_cnt[i][j][0] = cnt[i][j][0];
			for (int k = 1; k < MAXN; ++ k){
				pre_cnt[i][j][k] = pre_cnt[i][j][k - 1] + cnt[i][j][k];
			}
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			for (int k = 0; k < MAXN; ++ k){
				pre_temp[i][j] += 1ll * std::abs(s[i][j] - 'a' - k) * cnt[i][j][k];
			}
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			pre_temp[i][j] += pre_temp[i][j - 1];
		}
	}
	for (int j = 1; j <= m; ++ j){
		for (int i = 1; i <= n; ++ i){
			pre_temp[i][j] += pre_temp[i - 1][j];
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			for (int k = 0; k < MAXN; ++ k){
				pre[i][j][0] += 1ll * k * cnt[i][j][k];
			}
			for (int k = 1; k < MAXN; ++ k){
				pre[i][j][k] = pre[i][j][k - 1] - pre_cnt[i][j][MAXN - 1] + 2ll * pre_cnt[i][j][k - 1];
			}
		}
	}
	for (int k = 0; k < MAXN; ++ k){
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= m; ++ j){
				pre[i][j][k] += pre[i][j - 1][k];
			}
		}
		for (int j = 1; j <= m; ++ j){
			for (int i = 1; i <= n; ++ i){
				pre[i][j][k] += pre[i - 1][j][k];
			}
		}
	}
	ll min = LLONG_MAX;
	for (int i = 0; i < kk; ++ i){
		ll ans = pre_temp[n][m] - (pre_temp[c[i]][d[i]] + pre_temp[a[i] - 1][b[i] - 1] - pre_temp[c[i]][b[i] - 1] - pre_temp[a[i] - 1][d[i]]);
		ans += pre[c[i]][d[i]][ch[i] - 'a'] + pre[a[i] - 1][b[i] - 1][ch[i] - 'a'] - pre[c[i]][b[i] - 1][ch[i] - 'a'] - pre[a[i] - 1][d[i]][ch[i] - 'a'];
		min = std::min(min, ans);
	}
	return printf("%I64d\n", min), 0;
}