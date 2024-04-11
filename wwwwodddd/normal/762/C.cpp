#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[100020];
char b[100020];
int zf[100020];
int zb[100020];
int main() {
	scanf("%s", a);
	scanf("%s", b);
	int la = strlen(a);
	int lb = strlen(b);
	zf[0] = 0;
	zb[la] = lb;
	for (int i = 1; i <= la; i++) {
		if (a[i - 1] == b[zf[i - 1]]) {
			zf[i] = zf[i - 1] + 1;
		} else {
			zf[i] = zf[i - 1];
		}
	}
	for (int i = la - 1; i >= 0; i--) {
		if (a[i] == b[zb[i + 1] - 1]) {
			zb[i] = zb[i + 1] - 1;
		} else {
			zb[i] = zb[i + 1];
		}
	}
	int ans = lb + 1;
	int p = -1;
	for (int i = 0; i <= la; i++) {
		int tmp = max(zb[i] - zf[i], 0);
		if (ans > tmp) {
			ans = tmp;
			p = i;
		}
	}
//	printf("%d %d %d\n", ans, zf[p], zb[p]);
	for (int i = 0; i < zf[p]; i++) {
		printf("%c", b[i]);
	}
	for (int i = max(zf[p], zb[p]); i < lb; i++) {
		printf("%c", b[i]);
	}
	if (ans == lb) {
		printf("-");
	}
	printf("\n");
	return 0;
}