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

char s[111];

int main () {
	int T = read();
	while (T--) {
		int n = read(), a = read(), b = read();
		cin >> s; int ans = n * a;
		if (b >= 0) { cout << ans + n * b << endl; continue; }
		int now = 0, x1 = 0, x2 = 0;
		for(int i = 0; i < n; i++) {
			if (i == 0 || s[i] != s[i - 1]) {
				now ^= 1;
				if (now) ++x1; else ++x2;
			}
		}
		cout << ans + b * (min(x1, x2) + 1) << endl;
	}
	return 0;
}