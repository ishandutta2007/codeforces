#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
 
using namespace std;
 
#define int long long
inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}
 
const int MAXN = 300300;
int n, h[MAXN], b[MAXN];
struct ins { int h, v, maxf; } s[MAXN]; int top;
int f[MAXN];
 
signed main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) h[i] = read();
	for (i = 1; i <= n; i++) b[i] = read();
	s[0].v = -1e18;
	for (i = 1; i <= n; i++) {
		int mxf = f[i - 1];
		while (top && s[top].h > h[i]) mxf = max(mxf, s[top].maxf), --top;
		f[i] = mxf + b[i]; f[i] = max(f[i], s[top].v);
		// cout << f[i] << ' ';
		++top; s[top].h = h[i], s[top].maxf = mxf, s[top].v = f[i];
		// printf("! %lld %lld\n", max(mxf + b[i], f[i]), pq.top());
	}
	cout << f[n] << endl;
	return 0;
}