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

char a[200200] = {};
int ans[200200] = {};
int cnt = 0;
int len;

int main () {
	int T = read();
	while (T--) {
		scanf("%s", a + 1);
		len = strlen(a + 1);
		int i, j;
		cnt = 0;
		for (i = 1; i <= len; i++) {
			if (i <= len - 2 && a[i] == 't' && a[i + 1] == 'w' && a[i + 2] == 'o') {
				if (i <= len - 4 && a[i + 3] == 'n' && a[i + 4] == 'e') {
					ans[++cnt] = i + 2;
					i += 3;
					continue;
				}
				else {
					ans[++cnt] = i + 1;
					i++;
					continue;
				}
			}
			if (i <= len - 2 && a[i] == 'o' && a[i + 1] == 'n' && a[i + 2] == 'e') {
				ans[++cnt] = i + 1;
				i++;
				continue;
			}
		}
		printf("%d\n", cnt);
		for (i = 1; i <= cnt; i++) printf("%d ", ans[i]); putchar('\n');
	}
	return 0;
}