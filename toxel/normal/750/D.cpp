#include<bits/stdc++.h>

const int N = 310;

bool vis[N][N], dir[N][N][8];

std::pair <int, int> forward(std::pair <int, int> coor, int dire){
	switch (dire){
		case 0: return {coor.first, coor.second + 1};
		case 1: return {coor.first - 1, coor.second + 1};
		case 2: return {coor.first - 1, coor.second};
		case 3: return {coor.first - 1, coor.second - 1};
		case 4: return {coor.first, coor.second - 1};
		case 5: return {coor.first + 1, coor.second - 1};
		case 6: return {coor.first + 1, coor.second};
		case 7: return {coor.first + 1, coor.second + 1};
	}
}

int n;
std::vector <std::vector <int>> vec;

int main(){
	scanf("%d", &n);
	dir[N >> 1][N >> 1][0] = true;
	while (n --){
		int t;
		scanf("%d", &t);
		vec.clear();
		for (int i = 0; i < N; ++ i){
			for (int j = 0; j < N; ++ j){
				for (int k = 0; k < 8; ++ k){
					if (dir[i][j][k]){
						vec.push_back({i, j, k});
					}
				}
			}
		}
		memset(dir, 0, sizeof(dir));
		for (int i = 0; i < vec.size(); ++ i){
			std::pair <int, int> coor = {vec[i][0], vec[i][1]};
			int dire = vec[i][2];
			for (int j = 0; j < t; ++ j){
				coor = forward(coor, dire);
				vis[coor.first][coor.second] = true;
				if (j == t - 1){
					dir[coor.first][coor.second][(dire + 7) % 8] = true;
					dir[coor.first][coor.second][(dire + 1) % 8] = true;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; ++ i){
		for (int j = 0; j < N; ++ j){
			if (vis[i][j]){
				++ cnt;	
			}
		}
	}
	return printf("%d\n", cnt), 0;
}