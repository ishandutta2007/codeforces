#include<bits/stdc++.h>

const int N = 200;

int pre[N][N], a[N], n, m, t;
bool dp[N][N];
char s[N], text[N][N];
std::map <std::string, int> Hash;
std::set <int> set[N];
std::string string[N];

int main(){
	scanf("%d", &t);
	while (t --){
		for (int i = 0; i < N; ++ i){
			set[i].clear();
		}
		Hash.clear();
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		memset(pre, -1, sizeof(pre));
		memset(a, -1, sizeof(a));
		for (int i = 0; i < n; ++ i){
			scanf("%s", s);
			string[i] = s;
			Hash[string[i]] = i;
		}
		scanf("%d", &m);
		getchar();
		for (int i = 0; i < m; ++ i){
			gets(s);
			int len = strlen(s), __pre = 0;
			memcpy(text[i], s, sizeof(int) * len);
			bool flag = text[i][0] != '?';
			for (int j = 0; j <= len; ++ j){
				if (text[i][j] >= 'a' && text[i][j] <= 'z' || text[i][j] >= 'A' && text[i][j] <= 'Z' || text[i][j] >= '0' && text[i][j] <= '9'){
					continue;
				}
				text[i][j] = 0;
				std::string str = text[i] + __pre;
				if (flag){
					a[i] = Hash[str];
					flag = false;
					continue;
				}
				if (Hash.count(str)){
					set[i].insert(Hash[str]);
				}
				__pre = j + 1;
			}
			memcpy(text[i], s, sizeof(int) * len);
			if (a[i] != -1){
				dp[i][a[i]] = 1;
				for (int j = 0; j < n; ++ j){
					if (j != a[i] && dp[i - 1][j]){
						pre[i][a[i]] = j;
						break;
					}
				}
				continue;
			}
			if (!i){
				for (int j = 0; j < n; ++ j){
					if (!set[0].count(j)){
						dp[0][j] = 1;
					}
				}
				continue;
			}
			for (int j = 0; j < n; ++ j){
				if (!dp[i - 1][j]){
					continue;
				}
				for (int k = 0; k < n; ++ k){
					if (j != k && !set[i].count(k)){
						dp[i][k] = 1;
						pre[i][k] = j;
					}
				}
			}
		}
		int now = -1;
		for (int i = 0; i < n; ++ i){
			if (dp[m - 1][i]){
				now = i;
				break;
			}
		}
		int i = m - 1;
		do{
			if (now == -1){
				printf("Impossible\n");
				break;
			}
			a[i] = now;
			now = pre[i --][now];
		}
		while (i >= 0);
		if (i >= 0){
			continue;
		}
		for (int i = 0; i < m; ++ i){
			if (text[i][0] != '?'){
				puts(text[i]);
			}
			else{
				std::cout << string[a[i]];
				puts(text[i] + 1);
			}
		}
	}
	return 0;
}