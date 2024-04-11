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

const int LIM = 1e6, MAXN = LIM + 5;
int p[MAXN], top; bool np[MAXN];
void genp () {
	for (int i = 2; i <= LIM; i++) {
		if (!np[i]) p[++top] = i;
		for (int j = 1; j <= top; j++) {
			if (i * p[j] > LIM) break;
			np[i * p[j]] = 1;			if (i % p[j] == 0) break;
		}
	}
}

int main () {
	genp();
	int T  = read();
	while (T--) {
		int d = read();
		int now = d + 1, a = 0, b = 0;
		for (now; !b; now++) {
			if (!np[now]) {
				if (!a) a = now;
				else if (now - a >= d) b = now;
			}
		}
		printf("%lld\n", min(1ll * a * a * a, 1ll * a * b));
	}
	return 0;
}