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

const int LIM = 1e6, MAXN = LIM + 5;
int p[MAXN], top, phi[MAXN]; bool np[MAXN];
void genp () {
	phi[1] = 1; int i, j;
	for (i = 2; i <= LIM; i++) {
		if (!np[i]) p[++top] = i, phi[i] = i - 1;
		for (j = 1; j <= top; j++) {
			if (i * p[j] > LIM) break;
			np[i * p[j]] = 1;
			if (i % p[j] == 0) { phi[i * p[j]] = phi[i] * p[j]; break; }
			phi[i * p[j]] = phi[i] * phi[p[j]];
		}
	}
}

int main () {
	genp(); int i, j;
	int n = read(), k = read();
	if (k == 1) { puts("3"); return 0; }
	sort(phi + 3, phi + n + 1); long long ans = 2;
	for (i = 3; i <= 3 + k - 1; i++) ans += phi[i];
	cout << ans << endl;
	return 0;
}