#include<bits/stdc++.h>

const int N = 210;
const int MAX = 14;

bool vis[N][MAX][1 << MAX];
int n, m;
int len[N];
char s[N][N], begin[N][MAX], end[N][MAX], aux[N];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
		len[i] = strlen(s[i]);
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 1; j < MAX; ++ j){
			for (int k = 0; k <= len[i] - j; ++ k){
				int x = 0;
				for (int u = 0; u < j; ++ u){
					(x <<= 1) |= s[i][u + k] - '0';
				}
				vis[i][j][x] = true;
			}
		}
		if (len[i] < 13){
			strcpy(begin[i], s[i]);
			strcpy(end[i], s[i]);
		}
		else{
			for (int j = 0; j < 13; ++ j){
				begin[i][j] = s[i][j];
			}
			for (int j = len[i] - 13; j < len[i]; ++ j){
				end[i][j - len[i] + 13] = s[i][j];
			}
		}
	}
	scanf("%d", &m);
	while (m --){
		int a, b;
		scanf("%d%d", &a, &b);
		-- a, -- b;
		for (int i = 1; i < MAX; ++ i){
			for (int j = 0; j < 1 << MAX; ++ j){
				vis[n][i][j] = vis[a][i][j] || vis[b][i][j];
			}
		}
		strcpy(aux, end[a]);
		strcat(aux, begin[b]);
		for (int j = 1, len = strlen(aux); j < MAX; ++ j){
			for (int k = 0; k <= len - j; ++ k){
				int x = 0;
				for (int u = 0; u < j; ++ u){
					(x <<= 1) |= aux[u + k] - '0';
				}
				vis[n][j][x] = true;
			}
		}
		int ans = 0;
		for (int i = 1; i < MAX; ++ i){
			bool flag = true;
			for (int j = 0; j < 1 << i; ++ j){
				if (!vis[n][i][j]){
					flag = false;
					break;
				}
			}
			if (flag){
				ans = i;
			}
		}
		printf("%d\n", ans);
		if (strlen(end[a]) < 13 && strlen(end[b]) < 13){
			if (strlen(aux) < 13){
				strcpy(end[n], aux);
				strcpy(begin[n], aux);
			}
			else{
				for (int i = 0; i < 13; ++ i){
					begin[n][i] = aux[i];
				}
				int len = strlen(aux);
				for (int i = len - 13; i < len; ++ i){
					end[n][i - len + 13] = aux[i];
				}
			}
		}
		else if (strlen(end[a]) < 13){
			strcpy(end[n], end[b]);
			strcpy(aux, begin[a]);
			strcat(aux, begin[b]);
			for (int i = 0; i < 13; ++ i){
				begin[n][i] = aux[i];
			}
		}
		else if (strlen(end[b]) < 13){
			strcpy(begin[n], begin[a]);
			strcpy(aux, end[a]);
			strcat(aux, end[b]);
			int len = strlen(aux);
			for (int i = len - 13; i < len; ++ i){
				end[n][i - len + 13] = aux[i];
			}
		}
		else{
			strcpy(begin[n], begin[a]);
			strcpy(end[n], end[b]);
		}
		++ n;
	}
	return 0;
}