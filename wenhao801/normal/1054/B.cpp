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

#include <map>
map <int, bool> vis;
int now, n;

int main () {
	n = read(); now = 0;
	for (int i = 1; i <= n; i++) {
		int x = read();
		if (x > now) { cout << i << endl; return 0; }
		if (x == now) ++now;
	}
	cout << -1;
	return 0;
}