#include<bits/stdc++.h>

const int N = 30;

int n, m;
int a[N][N];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			a[i][j] += a[i][j - 1];
		}
	}
	for (int j = 1; j <= m; ++ j){
		for (int i = 1; i <= n; ++ i){
			a[i][j] += a[i - 1][j];
		}
	}
	int max = 0;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			for (int ii = i + 1; ii <= n; ++ ii){
				for (int jj = j + 1; jj <= m; ++ jj){
					if (!(a[ii][jj] - a[i][jj] - a[ii][j] + a[i][j])){
						max = std::max(max, ii - i + jj - j << 1);
					}
				}
			}
		}
	}
	return printf("%d\n", max), 0;
}