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
const int MAXN = 200200;
int a[MAXN], d[MAXN], w[MAXN], top;

int main () {
	int T = read();
	while (T--) {
		int n = read(); int i, j;
		long long sum = 0;
		top = 0; for (i = 1; i <= n; i++) d[i] = 0;
		for (i = 1; i <= n; i++) a[i] = read(), sum += a[i];
		for (i = 1; i < n; i++ ){
			int u = read(), v = read();
			++d[u], ++d[v];
		}
		for (i = 1; i <= n; i++) for (j = 1; j < d[i]; j++) w[++top] = a[i];
		sort(w + 1, w + top + 1);
		for (i = top; i >= top - n + 2; i--) {
			printf("%lld ", sum);
			sum += w[i];
		}
		puts("");
	}
	return 0;
}