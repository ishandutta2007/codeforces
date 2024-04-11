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

int main () {
	int T = read();
	while (T--) {
		int n = read(), now = 1;
		while ((now << 1) - 1 < n) now <<= 1;
		cout << now - 1 << endl;
	}
	return 0;
}