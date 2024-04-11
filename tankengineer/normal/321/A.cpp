#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105;
int x, y;
char s[N];

int main() {
	scanf("%d%d%s", &x, &y, s);
	int tx = 0, ty = 0, dx = 0, dy = 0, n = strlen(s);
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'U') {
			++dy;
		}
		if (s[i] == 'D') {
			--dy;
		}
		if (s[i] == 'L') {
			--dx;
		}
		if (s[i] == 'R') {
			++dx;
		}
	}
	for (int i = 0; i <= n; ++i) {
		if (dx == 0) {
			if (dy == 0) {
				if (tx == x && ty == y) {
					puts("Yes");
					return 0;
				}
			} else {
				if (tx == x && ty % dy == y % dy && (y - ty) / dy >= 0) {
					puts("Yes");
					return 0;
				}
			}
		} else {
			if (dy == 0) {
				if (tx % dx == x % dx && ty == y && (x - tx) / dx >= 0) {
					puts("Yes");
					return 0;
				}
			} else {
				if (tx % dx == x % dx && ty % dy == y % dy && (x - tx) / dx == (y - ty) / dy && (y - ty) / dy >= 0) {
					puts("Yes");
					return 0;
				}
			}
		}
		if (s[i] == 'U') {
			++ty;
		} else if (s[i] == 'D') {
			--ty;
		} else if (s[i] == 'L') {
			--tx;
		} else {
			++tx;
		}
	}
	puts("No");
	return 0;
}