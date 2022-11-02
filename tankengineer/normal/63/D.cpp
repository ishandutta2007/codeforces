#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105;

int n, m, a, b, c, d;

char map[N][N];

int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	n = max(b, d);
	m = a + c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			map[i][j] = '.';
		}
	}
	int k;
	scanf("%d", &k);
	int x, y, dir;
	if (a % 2 == 0) {
		x = 0, y = 0, dir = 1;
	} else {
		x = b - 1, y = 0, dir = -1;
	}
	for (int i = 0; i < k; ++i) {
		int s;
		scanf("%d", &s);
		while (s--) {
			map[x][y] = 'a' + i;
			if (dir == 1) {
				if (y < a) {
					if (x == b - 1) {
						++y;
						dir = -1;
					} else {
						++x;
					}
				} else {
					if (x == d - 1) {
						++y;
						dir = -1;
					} else {
						++x;
					}
				}
			} else {
				if (x == 0) {
					++y;
					dir = 1;
				} else {
					--x;
				}
			}
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		printf("%s\n", map[i]);
	}
	return 0;
}