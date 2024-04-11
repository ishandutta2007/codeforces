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

int n; char s[44], t[44];

int main () {
	int T = read();
	while (T--) {
		cin >> n; scanf("%s", s + 1); strcpy(t + 1, s + 1);
		sort(t + 1, t + n + 1);
		int ans = 0;
		for (int i = 1; i <= n; i++) ans += s[i] != t[i];
		cout << ans << endl;
	}
	return 0;
}