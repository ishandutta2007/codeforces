#include<bits/stdc++.h>

const int N = 110;

int mat[N][N];
int n, m;
std::vector <std::pair <bool, int>> ans;

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			scanf("%d", &mat[i][j]);
		}
	}
	for (int i = 0; i < n; ++ i){
		int flag = INT_MIN;
		for (int j = 0; j < m; ++ j){
			if (flag == INT_MIN){
				flag = mat[i][j] - mat[0][j];
			}
			else{
				if (flag != mat[i][j] - mat[0][j]){
					return printf("-1\n"), 0;
				}
			}
		}
	}
	int min = INT_MAX;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			min = std::min(min, mat[i][j]);
		}
	}
	if (n <= m){
		for (int j = 0; j < min; ++ j){
			for (int i = 0; i < n; ++ i){
				ans.push_back({0, i + 1});
			}
		}
	}
	else{
		for (int j = 0; j < min; ++ j){
			for (int i = 0; i < m; ++ i){
				ans.push_back({1, i + 1});
			}
		}
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			mat[i][j] -= min;
		}
	}
	for (int i = 0; i < n; ++ i){
		int mini = INT_MAX;
		for (int j = 0; j < m; ++ j){
			mini = std::min(mini, mat[i][j]);
		}
		for (int j = 0; j < mini; ++ j){
			ans.push_back({0, i + 1});
		}
		for (int j = 0; j < m; ++ j){
			mat[i][j] -= mini;
		}
	}
	for (int i = 0; i < m; ++ i){
		for (int j = 0; j < mat[0][i]; ++ j){
			ans.push_back({1, i + 1});
		}
	}
	printf("%d\n", (int) ans.size());
	for (auto u : ans){
		printf("%s %d\n", u.first ? "col" : "row", u.second);
	}
	return 0;
}