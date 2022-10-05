#include<bits/stdc++.h>

const int N = 110;

int mat[N][N];
std::pair <std::pair <int, int>, std::pair <int, int>> q[N * N];
int n, m, test;

int main(){
	scanf("%d%d%d", &n, &m, &test);
	for (int i = 0, op, r, c, x; i < test; ++ i){
		scanf("%d", &op);
		if (op == 1 || op == 2){
			scanf("%d", &r);
			q[i].first = {op, r};
		}
		else{
			scanf("%d%d%d", &r, &c, &x);
			q[i] = {{op, r}, {c, x}};
		}
	}
	for (int i = test - 1; i >= 0; -- i){
		if (q[i].first.first == 1){
			int sit = q[i].first.second, p = mat[sit][m];
			for (int j = m - 1; j; -- j){
				mat[sit][j + 1] = mat[sit][j];
			}
			mat[sit][1] = p;
		}
		else if (q[i].first.first == 2){
			int sit = q[i].first.second, p = mat[n][sit];
			for (int j = n - 1; j; -- j){
				mat[j + 1][sit] = mat[j][sit];
			}
			mat[1][sit] = p;
		}
		else{
			mat[q[i].first.second][q[i].second.first] = q[i].second.second;
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			printf("%d%c", mat[i][j], " \n"[j == m]);
		}
	}
	return 0;
}