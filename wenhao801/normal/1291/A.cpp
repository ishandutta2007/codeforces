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

char a[3030] = {};
int n;

int main () {
	int T = read();
	while (T--) {
		n = read();
		scanf("%s", a + 1);
		int i, j;
		for (i = n; i >= 1; i--) if ((a[i] - '0') % 2 != 0) break;
		if (i == 0) {
			puts("-1");
			continue;
		}
		bool f = false;
		for (j = 1; j < i; j++) if ((a[j] - '0') % 2 != 0) f ^= 1;
		if (f) {
			for (j = 1; j <= i; j++) cout << a[j]; cout << endl;
			continue;
		}
		f = false;
		for (j = 1; j < i; j++) if ((a[j] - '0') % 2 != 0){
			if (!(j == 1 && n >= 2 && a[2] == '0')) f = true;
		}
		if (!f) { puts("-1"); continue; }
		f = false;
		for (j = 1; j <= i; j++) {
			if (f == false && ((a[j] - '0') % 2 != 0)) {
				if (!(j == 1 && n >= 2 && a[2] == '0')) {
				f = true;
				continue;
				}
			}
			cout << a[j];
		}
		cout << endl;
	}
	return 0;
}