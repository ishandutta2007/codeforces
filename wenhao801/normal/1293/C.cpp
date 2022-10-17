#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}
bool a[5][100100] = {};
int s = 0;
int main () {
	int n = read(), q = read();
	while (q--) {
		int r = read(), c = read();
			a[r][c] = 1 - a[r][c];
			if (a[r][c]) {
				s += (a[r - 1][c - 1]) + a[r - 1][c] + a[r - 1][c + 1] + a[r + 1][c - 1] + a[r + 1][c] + a[r + 1][c + 1]; 
			}
			else {
				s -= (a[r - 1][c - 1]) + a[r - 1][c] + a[r - 1][c + 1] + a[r + 1][c - 1] + a[r + 1][c] + a[r + 1][c + 1]; 
			
			}
		if (s == 0) { puts("Yes");  } else puts("No");
	}
	return 0;
}