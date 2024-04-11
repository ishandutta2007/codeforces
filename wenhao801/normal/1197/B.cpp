#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}
 
struct lianbiao {
	int l;
	int r;
	int x;
} a[200200];
 
int main () {
	int n = read();
	int i, j;
	int Max = 0;
	for (i = 1; i <= n; i++) {
		a[i].x = read();
		a[i].l = i - 1, a[i].r = i + 1;
		if (a[i].x > a[Max].x) Max = i;
	}
	for (i = 1; i < n; i++) {
		if (a[Max].x == a[a[Max].l].x + 1) {
			a[Max].x--;
			a[Max].l--;
		}
		else if (a[Max].x == a[a[Max].r].x + 1) {
			a[Max].x--;
			a[Max].r++;
		}
		else {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}