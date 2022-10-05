#include<bits/stdc++.h>

const int N = 510;

char s[N][N];
int n, m;

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
	}
	int left = m - 1, up = n - 1;
	int right = 0, down = 0;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			if (s[i][j] == 'X'){
				left = std::min(left, j);
				right = std::max(right, j);
				down = std::max(down, i);
				up = std::min(up, i);
			}
		}
	}
	for (int i = up; i <= down; ++ i){
		for (int j = left; j <= right; ++ j){
			if (s[i][j] != 'X'){
				return printf("NO\n"), 0;
			}
		}
	}
	return printf("YES\n"), 0;
}