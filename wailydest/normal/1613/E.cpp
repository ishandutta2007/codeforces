#include <cstdio>
#include <vector>
#include <string>

const int N = 1000000;
int t, n, m;
std::vector<int> to[N];
std::string s[N];
char buf[N + 1];

int move[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool good(int x, int y) 
{
	return x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '#';
}

void dfs(int x, int y) 
{
	if (s[x][y] != 'L') s[x][y] = '+';
	for (int i = 0; i < 4; ++i) {
		int xx = x + move[i][0], yy = y + move[i][1];
		if (good(xx, yy) && s[xx][yy] == '.') {
			--to[xx][yy];
			if (to[xx][yy] <= 1) dfs(xx, yy);
		}
	}
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		int x, y;
		for (int i = 0; i < n; ++i) {
			scanf("%s", buf);
			s[i] = buf;
			for (int j = 0; j < m; ++j) if (s[i][j] == 'L') {
				x = i;
				y = j;
			}
			to[i].assign(m, 0);
		}
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < 4; ++k) to[i][j] += good(i + move[k][0], j + move[k][1]);
		dfs(x, y);
		for (int i = 0; i < n; ++i) printf("%s\n", s[i].c_str());
	}
	return 0;
}