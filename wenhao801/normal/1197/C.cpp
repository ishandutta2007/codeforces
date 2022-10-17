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
 
int n, k;
int a[300300], d[300300];
 
bool cmp (int x, int y) { return x > y; }
 
int main () {
	n = read(), k = read();
	int i, j;
	for (i = 1; i <= n; i++)
		a[i] = read();
	for (i = 2; i <= n; i++)
		d[i - 1] = a[i] - a[i - 1];
	int ans = a[n] - a[1];
	sort(d + 1, d + n, cmp);
	for (i = 1; i < k; i++)
		ans -= d[i];
	printf("%d\n", ans);
	return 0;
}