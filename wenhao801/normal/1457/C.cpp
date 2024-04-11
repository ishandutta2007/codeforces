#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>
 
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
 
char a[100100];
int s[200200];
 
signed main () {
	int t = read();
	while (t--) {
		int n = read(), p = read(), k = read();
		int i, j;
		scanf("%s", a + 1);
		int x = read(),y  = read();
		for (i = n; i >= 1; i--) s[i] = ('1' - a[i]) * x + s[i + k];
		int ans = LLONG_MAX;
		for (i = 0; i <= n - p; i++) {
			ans = min(ans, y * i + s[i + p]);
		}
		for (i = 1; i <= n; i++) s[i] = 0;
		printf("%lld\n", ans);
	}
	return 0;
}