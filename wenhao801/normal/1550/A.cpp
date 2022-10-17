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

int main () {
	int T = read();
	while (T--) {
		int s = read(), ans = 0;
		--s, ++ans;
		for (int i = 3; s; i += 2) if (s >= i) ++ans, s -= i; else break;
		if (s) ++ans; cout << ans << endl;
	}
	return 0;
}