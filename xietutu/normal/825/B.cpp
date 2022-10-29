#include <bits/stdc++.h>
using namespace std;
char s[12][12];
const int xy[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
int check(int x, int y, int d) {
	int t = 0;
	while (x >= 1 && y >= 1 && x <= 10 && y <= 10 && s[x][y] == 'X') {
		++t;
		x = x + xy[d][0];
		y = y + xy[d][1];
	}
	return t;
}
bool check(int sx, int sy) {
	for (int i = 0; i < 8; i += 2) {
		int t = check(sx, sy, i) + check(sx, sy, i + 1) - 1;
		if (t >= 5) return true;
	}
	return false;
}
int main() {
	//freopen("B.in","r",stdin);
	for (int i = 1; i <= 10; ++i)
		scanf("%s", s[i] + 1);
	bool flag = false;
	for (int i = 1; i <= 10; ++i)
		for (int j = 1; j <= 10; ++j)
			if (s[i][j] == '.') {
				s[i][j] = 'X';
				if (check(i, j)) flag = true;
				s[i][j] = '.';
			}
	puts(flag ? "YES" : "NO");
}