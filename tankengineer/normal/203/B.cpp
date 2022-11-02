#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;
int map[N][N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		map[x][y] = 1;
		for (int x0 = max(0, x - 2); x0 <= x; ++x0) {
			for (int y0 = max(0, y - 2); y0 <= y; ++y0) {
				bool flag = true;
				for (int dx = 0; dx < 3 && flag; ++dx) {
					for (int dy = 0; dy < 3 && flag; ++dy) {
						if (map[x0 + dx][y0 + dy] != 1) {
							flag = false;
						}
					}
				}
				if (flag) {
					cout << i + 1 << endl;
					return 0;
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}