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

char s[100100];

int main () {
	int T = read();
	while (T--) {
		int n= read(); scanf("%s", s + 1); int f = 0;
		for (int i = 1; i <= n; i++) if (s[i] == '0') ++f;
		if (n % 2 == 1 && f == 1 && s[n / 2 + 1] == '0') { puts("BOB"); }
		else if (!(n % 2 == 1 && s[n / 2 + 1] == '0')) puts(((!f)) ? "DRAW" : "BOB");
		else puts(!f ? "DRAW" : "ALICE");
	}
	return 0;
}