#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define int long long
inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}
int a[300300];
bool f = false;
signed main () {
	int n = read();
	int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	int s0 =0 , s1 = 0;
	for (i = 1; i <= n; i++) {
		if (!f) s0 += a[i] / 2 + (a[i] % 2), s1 += a[i] / 2;
		else s0 += a[i] / 2, s1 += a[i] / 2 + (a[i] % 2);
		f = !f;
	} if (s0 < s1) cout << s0 << endl; else cout << s1 << endl;
	return 0;
}