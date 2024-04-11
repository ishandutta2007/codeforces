#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int dx[] = {0, 0, 1, -1, 0}, dy[] = {0, 1, 0, 0, -1}; 

int n, m, vis[505][505];
char map[505][505];
vector<pair<char, pair<int, int> > > ans;

void dfs(const int i, const int j) {
  ans.push_back(make_pair('B', make_pair(i, j)));
  for (int d = 1; d <= 4; ++d) {
    int ti = i + dx[d], tj = j + dy[d];
    if (map[ti][tj] == '.' && vis[ti][tj] == 0) {
      vis[ti][tj] = 2;
      dfs(ti, tj);
		}
	}
  if (vis[i][j] == 2) {
	  ans.push_back(make_pair('D', make_pair(i, j)));
	  ans.push_back(make_pair('R', make_pair(i, j)));    
	}
}

int main() {
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 1; i <= n; ++i) scanf("%s", map[i] + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (map[i][j] != '#' && vis[i][j] == 0) {
        vis[i][j] = 1;
        dfs(i, j);
			}
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i) {
	  printf("%c %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
	}
	return 0;
}