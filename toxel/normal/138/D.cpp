#include<bits/stdc++.h>

const int N = 22;
typedef std::pair <int, int> pii;
typedef std::pair <pii, pii> piiii;

int sg[N << 1][N << 1][N << 1][N << 1][2];
char s[N][N];
piiii p[5];
std::bitset <400> set;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
	}
	for (int di = 0; di <= n + m - 2; ++ di){
		for (int dj = 0; dj <= n + m - 2; ++ dj){
			for (int i = 0; di + i <= n + m - 2; ++ i){
				for (int j = 1 - m; dj + j <= n - 1; ++ j){
					for (int par = 0; par < 2; ++ par){
						set.reset();
						for (int u = (i + par & 1) ? i + 1 : i; u <= i + di; u += 2){
							for (int v = (u + j & 1) ? j + 1 : j; v <= j + dj; v += 2){
								int x = u + v >> 1, y = u - v >> 1;
								if (x < 0 || x >= n || y < 0 || y >= m) continue;
								int z = 0;
								if (s[x][y] == 'L'){
									p[0] = {{i, u - 1 - i}, {j, dj}};
									p[1] = {{u + 1, i + di - u - 1}, {j, dj}};
									for (int k = 0; k < 2; ++ k){
										if (p[k].first.second >= 0 && p[k].second.second >= 0){
											z ^= sg[p[k].first.first][p[k].first.second][p[k].second.first + N][p[k].second.second][par];
										}
									}
								}
								else if (s[x][y] == 'R'){
									p[0] = {{i, di}, {j, v - 1 - j}};
									p[1] = {{i, di}, {v + 1, j + dj - v - 1}};
									for (int k = 0; k < 2; ++ k){
										if (p[k].first.second >= 0 && p[k].second.second >= 0){
											z ^= sg[p[k].first.first][p[k].first.second][p[k].second.first + N][p[k].second.second][par];
										}
									}
								}
								else{
									p[0] = {{i, u - 1 - i}, {j, v - 1 - j}};
									p[1] = {{u + 1, i + di - u - 1}, {j, v - 1 - j}};
									p[2] = {{i, u - 1 - i}, {v + 1, j + dj - v - 1}};
									p[3] = {{u + 1, i + di - u - 1}, {v + 1, j + dj - v - 1}};
									for (int k = 0; k < 4; ++ k){
										if (p[k].first.second >= 0 && p[k].second.second >= 0){
											z ^= sg[p[k].first.first][p[k].first.second][p[k].second.first + N][p[k].second.second][par];
										}
									}
								}
								set.set(z);
							}
						}
						for (int k = 0; ; ++ k){
							if (!set.test(k)){
								sg[i][di][j + N][dj][par] = k;
								break;
							}
						}
					}
				}
			}
		}
	}
	puts(sg[0][n + m - 2][1 - m + N][n + m - 2][0] ^ sg[0][n + m - 2][1 - m + N][n + m - 2][1] ? "WIN" : "LOSE");
	return 0;
}