#include<bits/stdc++.h>

const int N = 1010;
typedef std::pair <int, int> pii;

int mat[N][N], col[2][N][N];
int a, b, m;
pii query[N * N];
int dega[N], degb[N];

int main(){
	scanf("%d%d%d", &a, &b, &m);
	for (int i = 0, x, y; i < m; ++ i){
		scanf("%d%d", &x, &y);
		mat[x][y] = -1;
		++ dega[x], ++ degb[y];
		query[i] = {x, y};
	}
	int max = 0;
	for (int i = 1; i <= a; ++ i){
		max = std::max(max, dega[i]);
	}
	for (int i = 1; i <= b; ++ i){
		max = std::max(max, degb[i]);
	}
	printf("%d\n", max);
	for (int i = 1; i <= a; ++ i){
		for (int j = 1; j <= b; ++ j){
			if (!mat[i][j]){
				continue;
			}
			int flag = 0, sit = 0, sit1 = 0;
			for (int k = 1; k <= max; ++ k){
				if (!col[0][i][k] && !col[1][j][k]){
					flag = k;
					break;
				}
				if (!col[0][i][k]){
					sit = k;
				}
				if (!col[1][j][k]){
					sit1 = k;
				}
			}
			if (flag){
				mat[i][j] = flag;
				col[0][i][flag] = j;
				col[1][j][flag] = i;
				continue;
			}
			int now = 0, x = i, y = j;
			do{
				int tmp = col[now ^ 1][y][sit];
				col[now][x][sit] = y;
				col[now ^ 1][y][sit] = x;
				(now ? mat[y][x] : mat[x][y]) = sit;
				x = y;
				y = tmp;
				now ^= 1;
				std::swap(sit, sit1);
			}
			while (col[now ^ 1][y][sit]);
			col[now][x][sit] = y;
			col[now ^ 1][y][sit] = x;
			col[now ^ 1][y][now ? mat[y][x] : mat[x][y]] = 0;
			(now ? mat[y][x] : mat[x][y]) = sit;
		}
	}
	for (int i = 0; i < m; ++ i){
		printf("%d%c", mat[query[i].first][query[i].second], " \n"[i == m - 1]);
	}
	return 0;
}