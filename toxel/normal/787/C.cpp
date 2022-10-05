#include<bits/stdc++.h>

const int N = 7010;
const int INF = 0x7f7f7f7f;

std::queue <std::pair <int, int>> q;
int n, k[2];
int num[2][N], ans[2][N], cnt[2][N];


int main(){
	memset(ans, 0x7f, sizeof(ans));
	scanf("%d%d", &n, &k[0]);
	for (int i = 0; i < k[0]; ++ i){
		scanf("%d", &num[0][i]);
	}
	scanf("%d", &k[1]);
	for (int i = 0; i < k[1]; ++ i){
		scanf("%d", &num[1][i]);
	}
	ans[0][0] = ans[1][0] = 0;
	q.push({0, 0});
	q.push({1, 0});
	while (q.size()){
		while (q.size()){
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < k[x ^ 1]; ++ i){
				int x1 = x ^ 1, y1 = (y - num[x1][i] + n) % n;
				if (!ans[x1][y1] || ans[x1][y1] == 1){
					continue;
				}
				ans[x1][y1] = 1;
				for (int j = 0; j < k[x]; ++ j){
					int y2 = (y1 - num[x][j] + n) % n;
					++ cnt[x][y2];
				}
			}
		}
		for (int i = 0; i < 2; ++ i){
			for (int j = 0; j < n; ++ j){
				if (!ans[i][j] || ans[i][j] == 1){
					continue;
				}
				if (cnt[i][j] == k[i]){
					ans[i][j] = 0;
					q.push({i, j});
				}
			}
		}
	}
	for (int i = 0; i < 2; ++ i){
		for (int j = 1; j < n; ++ j){
			switch (ans[i][j]){
				case 0 : printf("Lose "); break;
				case 1 : printf("Win "); break;
				default : printf("Loop "); break;
			}
		}
		printf("\n");
	}
	return 0;
}