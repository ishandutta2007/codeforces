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
const int MAXN = 1001000;
int n; char a[MAXN], b[MAXN];
void add (char s[MAXN]) {
	++s[n];
	for (int i = n; i >= 1 && s[i] == '2'; i--) s[i] = '0', ++s[i - 1];
}

int main () {
	n = read(); scanf("%s", a + 1); scanf("%s", b + 1);
	int i, j;
	if (strcmp(a + 1, b + 1) == 0) { printf("%s", b + 1); return 0; }
	if (a[1] != b[1]) { while (n--) putchar('1'); return 0; }
	else if (b[n] == '0') {
		add(a);
		for (i = 1; i <= n; i++) if (a[i] != b[i]) {
			add(b); break;
		}
	}
	printf("%s", b + 1);
	return 0;
}