#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int ans[2002000], top;

int main () {
	int T = read();
	while (T--) {
		int a = read(), b = read(); top = 0;
		for (int i = 0; i <= a; i++) {
			int tmp = (a + b + 1) / 2 - (a - i);
			if (tmp < 0) continue;
			if (tmp > b) continue;
			ans[++top] = tmp + i;
		}
		swap(a, b);
		for (int i = 0; i <= a; i++) {
			int tmp = (a + b + 1) / 2 - (a - i);
			if (tmp < 0) continue;
			if (tmp > b) continue;
			ans[++top] = tmp + i;
		}
		sort(ans + 1, ans + top + 1); top = unique(ans + 1, ans + top + 1)  -ans-1;
		printf("%d\n", top); for (int i = 1; i <= top; i++) cout << ans[i] << ' '; cout << endl;
	}
	return 0;
}