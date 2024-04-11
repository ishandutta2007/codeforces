#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int a[2020]; map <int, int> buc;

int main () {
	int n = read(), i, j, ans = 1e9;
	for (i = 1; i <= n; i++) cin >> a[i];
	for (i = 1; i <= n; i++) {
		++buc[a[i]];
		if (buc[a[i]] >= 2) { break; }
	}
	if (i > n) { cout << 0 << endl; return 0; }
	buc.clear();
	for (i = 0; i < n; i++) {
		buc.clear(); bool f = 0;
		for (j = 1; j <= i; j++) {
			++buc[a[j]];
			if (buc[a[j]] >= 2) { f = 1; break; }
		}
		if (f) continue;
		for (j = n; j > i; j--) {
			++buc[a[j]];
			if (buc[a[j]] >= 2) break;
		}
		ans = min(ans, j - i);
	}
	cout << ans << endl;
	return 0;
}