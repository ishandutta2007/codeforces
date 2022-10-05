#include<bits/stdc++.h>

const int N = 5010;
const int M = 1010;

std::map <std::string, int> Hash;
int n, m, a[N][M], b[N], cnt[2][M];
int calc[3][4][4] = {{{0, 0, 0, 0}, {0, 1, 2, 3}, {0, 2, 2, 0}, {0, 3, 0, 3}},
					 {{0, 1, 2, 3}, {1, 1, 1, 1}, {2, 1, 2, 1}, {3, 1, 1, 3}},
					 {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}}};
char s[M], str[M];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s);
		Hash[s] = i;
		scanf("%s", s);
		scanf("%s", s);
		if (s[0] == '0' || s[0] == '1'){
			for (int j = 0; j < m; ++ j){
				a[i][j] = s[j] - '0';
			}
		}
		else if (s[0] == '?'){
			for (int j = 0; j < m; ++ j){
				a[i][j] = 2;
			}
		}
		else{
			int x = Hash[s];
			for (int j = 0; j < m; ++ j){
				a[i][j] = a[x][j];
				}
		}
		if (getchar() != ' '){
			continue;
		}
		int type;
		scanf("%s", str);
		switch (str[0]){
			case 'A' : type = 0; break;
			case 'O' : type = 1; break;
			case 'X' : type = 2; break;
		}
		scanf("%s", str);
		if (str[0] == '0' || str[0] == '1'){
			for (int j = 0; j < m; ++ j){
				b[j] = str[j] - '0';
			}
		}
		else if (str[0] == '?'){
			for (int j = 0; j < m; ++ j){
				b[j] = 2;
			}
		}
		else{
			int x = Hash[str];
			for (int j = 0; j < m; ++ j){
				b[j] = a[x][j];
			}
		}
		for (int j = 0; j < m; ++ j){
			a[i][j] = calc[type][a[i][j]][b[j]];
		}
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			if (a[i][j] >= 2){
				++ cnt[a[i][j] % 2][j];
			}
		}
	}
	for (int i = 0; i < m; ++ i){
		if (cnt[0][i] == cnt[1][i]){
			putchar('0');
		}
		else{
			putchar(cnt[0][i] > cnt[1][i] ? '0' : '1');
		}
	}
	printf("\n");
	for (int i = 0; i < m; ++ i){
		if (cnt[0][i] == cnt[1][i]){
			putchar('0');
		}
		else{
			putchar(cnt[0][i] < cnt[1][i] ? '0' : '1');
		}
	}
}