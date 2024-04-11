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

const int MAXN = 10010;
char a[MAXN]; bool f[MAXN][4];
string ans[MAXN * 5]; int top;

int main () {
	scanf("%s", a + 1); int n = strlen(a + 1);
	int i, j;
	f[n + 1][2] = f[n + 1][3] = 1;
	for (i = n - 1; i >= 6; i--) {
		if (i + 4 - 1 > n || a[i] != a[i + 2] || a[i + 1] != a[i + 3]) f[i][2] |= f[i + 2][2];
		if (i + 6 - 1 > n || a[i] != a[i + 3] || a[i + 1] != a[i + 4] || a[i + 2] != a[i + 5]) f[i][3] |= f[i + 3][3];
		f[i][2] |= f[i + 2][3]; f[i][3] |= f[i + 3][2];
		if (f[i][2]) ++top, ans[top].push_back(a[i]), ans[top].push_back(a[i + 1]);
		if (f[i][3]) ++top, ans[top].push_back(a[i]), ans[top].push_back(a[i + 1]), ans[top].push_back(a[i + 2]);
	}
	sort(ans + 1, ans + top + 1); top = unique(ans + 1, ans + top + 1) - ans - 1;
	printf("%d\n", top);
	for (i = 1; i <= top; i++) cout << ans[i] << endl;
	return 0;
}