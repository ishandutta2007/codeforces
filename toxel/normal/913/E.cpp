#include<bits/stdc++.h>

const int N = 1 << 8;
const int M = 3;
typedef std::pair <int, int> pii;

std::string ans[N][M];
bool inque[N][M];
char s[N];

bool update(std::string &oldstr, std::string newstr){
	if (!oldstr.size() || newstr.size() < oldstr.size() || newstr.size() == oldstr.size() && newstr < oldstr){
		oldstr = newstr;
		return true;
	}
	return false;
}

int main(){
	std::queue <pii> q;
	ans[0xf0][0] = "x";
	ans[0xcc][0] = "y";
	ans[0xaa][0] = "z";
	inque[0xf0][0] = true;
	inque[0xcc][0] = true;
	inque[0xaa][0] = true;
	q.push({0xf0, 0});
	q.push({0xcc, 0});
	q.push({0xaa, 0});
	int cnt = 0;
	while (!q.empty()){
		++ cnt;
		//if (cnt > 100) break;
		pii u = q.front();
		q.pop();
		inque[u.first][u.second] = false;
		if (update(ans[u.first][0], '(' + ans[u.first][u.second] + ')')){
			if (!inque[u.first][0]){
				q.push({u.first, 0});
				inque[u.first][0] = true;
			}
		}
		if (!u.second){
			int sit = ~u.first & N - 1;
			if (update(ans[sit][0], '!' + ans[u.first][u.second])){
				if (!inque[sit][0]){
					q.push({sit, 0});
					inque[sit][0] = true;
				}
			}
		}
		if (u.second <= 1){
			for (int i = 0; i < N; ++ i){
				for (int j = 0; j <= 1; ++ j){
					if (ans[i][j].size()){
						std::string str = std::min(ans[u.first][u.second] + '&' + ans[i][j],
						                           ans[i][j] + '&' + ans[u.first][u.second]);
						int sit = u.first & i;
						if (update(ans[sit][1], str)){
							if (!inque[sit][1]){
								q.push({sit, 1});
								inque[sit][1] = true;
							}
						}
					}
				}
			}
		}
		if (u.second <= 2){
			for (int i = 0; i < N; ++ i){
				for (int j = 0; j <= 2; ++ j){
					if (ans[i][j].size()){
						std::string str = std::min(ans[u.first][u.second] + '|' + ans[i][j],
						                           ans[i][j] + '|' + ans[u.first][u.second]);
						int sit = u.first | i;
						if (update(ans[sit][2], str)){
							if (!inque[sit][2]){
								q.push({sit, 2});
								inque[sit][2] = true;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < N; ++ i){
		for (int j = 1; j < M; ++ j){
			update(ans[i][0], ans[i][j]);
		}
	}
	int query;
	scanf("%d", &query);
	while (query --){
		scanf("%s", s);
		int x = 0;
		for (int i = 0; i < 8; ++ i){
			x |= s[i] - '0' << i;
		}
		std::cout << ans[x][0] << std::endl;
	}
	return 0;
}