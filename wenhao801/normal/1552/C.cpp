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

int p[110], q[110];

int main () {
	int T = read();
	while (T--) {
		int n = read(), K = read();
		for (int i = 1; i <= K; i++) { p[i] = read(), q[i] = read(); if (p[i] > q[i]) swap(p[i], q[i]); }
		int ans = 1ll * (n - K) * (n - K - 1) / 2;
		for (int i = 1; i <= K; i++) {
			int pt1 = q[i] - p[i] - 1, pt2 = 2 * n - (q[i] - p[i] + 1);
			for (int j = 1; j <= K; j++) if (i != j) {
				if (p[j] > p[i] && p[j] < q[i]) --pt1; else --pt2;
				if (q[j] > p[i] && q[j] < q[i]) --pt1; else --pt2;
				if (j > i) ans += ((p[j] > p[i] && p[j] < q[i]) ^ (q[j] > p[i] && q[j] < q[i]));
			}
			ans += min(pt1, pt2);
		}
		cout << ans << endl;
	}
	return 0;
}