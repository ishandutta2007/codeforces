#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}
int Abs (int x) { return x<0 ? -x : x; }

int s[100100];
signed main () {
	int T = read();
	for (int i = 1; i <= 100000; i++) {
		s[i] = s[i - 1] + i;
	}
	while (T--) {
		int a = read(), b = read();
		int d = Abs(a - b);
		int i, j;
		for (i = 0; true; i++) {
			if ((s[i] - d) >= 0 && (s[i] - d) % 2 == 0) { cout << i << endl; break; }
		}
	}
	return 0;
}