#include<bits/stdc++.h>

const int N = 60;

std::vector <std::pair <int, int>> ans1, ans2;
int n, m;
char s[N][N];
bool flag;

void change(){
	for (int i = 0; i < std::max(n, m); ++ i){
		for (int j = 0; j < i; ++ j){
			std::swap(s[i][j], s[j][i]);
		}
	}
	std::swap(n, m);
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			switch (s[i][j]){
				case 'U' : s[i][j] = 'L'; break;
				case 'D' : s[i][j] = 'R'; break;
				case 'L' : s[i][j] = 'U'; break;
				case 'R' : s[i][j] = 'D'; break;
			}
		}
	}
}

void solve(std::vector <std::pair <int, int>> &vec){
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
	}
	if (flag){
		change();
	}
	while (true){
		bool flag1 = false;
		for (int i = 0; i < n - 1; ++ i){
			for (int j = 0; j < m; ++ j){
				if (s[i][j] != 'L'){
					continue;
				}
				if (s[i + 1][j] == 'L'){
					flag1 = true;
					vec.push_back({i + 1, j + 1});
					s[i][j] = s[i][j + 1] = 'U';
					s[i + 1][j] = s[i + 1][j + 1] = 'D';
				}
				else if (s[i + 1][j] == 'U' && s[i + 1][j + 1] == 'U'){
					flag1 = true;
					vec.push_back({i + 2, j + 1});
					vec.push_back({i + 1, j + 1});
					s[i][j] = s[i][j + 1] = 'U';
					s[i + 1][j] = s[i + 1][j + 1] = 'D';
					s[i + 2][j] = 'L';
					s[i + 2][j + 1] = 'R';
				}
			}
		}
		if (!flag1){
			break;
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	flag = n & 1;
	solve(ans1);
	if (flag){
		std::swap(n, m);
	}
	solve(ans2);
	printf("%d\n", ans1.size() + ans2.size());
	for (int i = 0; i < ans1.size(); ++ i){
		if (flag){
			std::swap(ans1[i].first, ans1[i].second);
		}
		printf("%d %d\n", ans1[i].first, ans1[i].second);
	}
	for (int i = ans2.size() - 1; i >= 0; -- i){
		if (flag){
			std::swap(ans2[i].first, ans2[i].second);
		}
		printf("%d %d\n", ans2[i].first, ans2[i].second);
	}
	return 0;
}