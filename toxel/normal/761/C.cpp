#include<bits/stdc++.h>

const int N = 100;

char s[N][N];

int min[N][3], n, m, flag[3];

int main(){
	memset(min, 0xf, sizeof(min));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
		for (int j = 0; j < m; ++ j){
			int dis = std::min(j, m - j);
			if (s[i][j] >= '0' && s[i][j] <= '9'){
				min[i][0] = std::min(min[i][0], dis);
				continue;
			}
			if (s[i][j] >= 'a' && s[i][j] <= 'z'){
				min[i][1] = std::min(min[i][1], dis);
				continue;
			}
			if (s[i][j] == '#' || s[i][j] == '*' || s[i][j] == '&'){
				min[i][2] = std::min(min[i][2], dis);
				continue;
			}
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i < n; ++ i){
		for (int j = i + 1; j < n; ++ j){
			memset(flag, 0, sizeof(flag));
			for (int k = 0; k < n; ++ k){
				if (k == i || k == j){
					continue;
				}
				if (s[k][0] >= '0' && s[k][0] <= '9'){
					flag[0] = true;
				}
				if (s[k][0] >= 'a' && s[k][0] <= 'z'){
					flag[1] = true;
				}
				if (s[k][0] == '#' || s[k][0] == '*' || s[k][0] == '&'){
					flag[2] = true;
				}
			}
			int n_ex_1 = -1, n_ex_2 = -1;
			for (int k = 0; k < 3; ++ k){
				if (!flag[k]){
					if (n_ex_1 == -1){
						n_ex_1 = k;
					}
					else{
						n_ex_2 = k;
					}
				}
			}
			if (n_ex_1 == -1){
				return printf("0\n"), 0;
			}
			if (n_ex_2 == -1){
				ans = std::min(ans, std::min(min[i][n_ex_1], min[j][n_ex_1]));
				continue;
			}
			ans = std::min(ans, std::min(min[i][n_ex_1] + min[j][n_ex_2], min[i][n_ex_2] + min[j][n_ex_1]));
		}
	}
	return printf("%d\n", ans), 0;
}