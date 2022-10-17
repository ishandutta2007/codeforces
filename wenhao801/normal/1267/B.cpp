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

char a[300200] = {};
int l;
int cnt = 0;
int L[300200] = {};
int t[300300] = {};

int main () {
	scanf("%s", a + 1);
	l = strlen(a + 1);
	int i, j;
	for (i = 1; i <= l; i++) {
		if (a[i] != a[i - 1]) t[++cnt] = i, L[cnt] = 1;
		else L[cnt]++;
	}
	if (cnt % 2 == 0) { puts("0"); return 0; }
	int rua = cnt / 2 + 1;
	if (L[rua] <= 1) { puts("0"); return 0; }
	for (i = 1; rua - i >= 1; i++) {
		if (a[t[rua - i]] != a[t[rua + i]] || L[rua - i] + L[rua + i] < 3) { puts("0"); return 0; }
	}
	printf("%d\n", L[rua] + 1);
	return 0;
}