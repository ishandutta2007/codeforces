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

int w, n, m, buc[1 << 12];
char s[12];

double f[1 << 12];
void FWT (bool inv) {
	for (int i = 0; i < w; i++)
		for (int j = 0; j < (1 << w); j += (1 << (i + 1)))
			for (int k = j; k < j + (1 << i); k++) {
				double x = f[k], y = f[k + (1 << i)];
				if (!inv) {
					if (s[i] == 'O' || s[i] == 'o') f[k + (1 << i)] = (x + y);
					else if (s[i] == 'A' || s[i] == 'a') f[k] = (x + y);
					else f[k] = (x + y), f[k + (1 << i)] = (x - y);
				}
				else {
					if (s[i] == 'O' || s[i] == 'o') f[k + (1 << i)] = (y - x);
					else if (s[i] == 'A' || s[i] == 'a') f[k] = (x - y);
					else f[k] = (x + y) / 2, f[k + (1 << i)] = (x - y) / 2;
				}
			}
}

int main () {
	w = read(), n = read(), m = read();
	int i, j;
	for (i = 1; i <= n; i++) { int x = read(); ++buc[x]; }
	while (m--) {
		scanf("%s", s); reverse(s, s + w);
		for (i = 0; i < (1 << w); i++) f[i] = buc[i];
		FWT(0); for (int i = 0; i < (1 << w); i++) f[i] = f[i] * f[i]; FWT(1);
		int id = 0;
		for (i = 0; i < w; i++) id += (s[i] >= 'a' && s[i] <= 'z') << i;
		printf("%.0lf\n", f[id]);
	}
	return 0;
}