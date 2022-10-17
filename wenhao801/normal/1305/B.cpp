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

char a[1010];
int ans[1010], top = 0;

int main () {
	scanf("%s", a + 1);
	int l = strlen(a + 1);
	int i, j;
	for (i = 1; i <= l && a[i] == ')'; i++);
	for (; i <= l && a[i] == '('; i++);
	if (i == l + 1) { puts("0"); return 0; }
	int L = 0, R = l + 1;
	puts("1");
	while (L < R) {
		while (a[++L] != '(');
		while (a[--R] != ')');
		if (L < R) ans[++top] = L, ans[++top] = R;
	}
	sort(ans + 1, ans + top + 1);
	printf("%d\n", top);
	for (i = 1; i <= top; i++) printf("%d ", ans[i]);
	return 0;
}