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
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int main() {
	int n = read(), d = read(), h = read();
	if (d == 1) {
		if (n == 2) puts("1 2"); else puts("-1");
		return 0;
	}
	if (2 * h >= d) {
		if (h == d) {
			int top = 1;
			for (int i = 1; i <= d; i++) ++top, printf("%d %d\n", top, top - 1);
			while (top < n) printf("%d %d\n", ++top, 2);
			return 0;
		}
		int top = 1, las = 1;
		for (int i = 1; i <= h; i++) printf("%d %d\n", ++top, las), las = top;
		las = 1;
		for (int i = 1; i <= d - h; i++) printf("%d %d\n", ++top, las), las = top;
		while (top < n) printf("%d %d\n", ++top, 1);
	}
	else puts("-1");
	return 0;
}