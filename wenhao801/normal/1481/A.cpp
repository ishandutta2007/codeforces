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
int cnt[1010] = {};

int main () {
	int T = read();
	while (T--) {
		int x = read(), y = read(), nx = 0, ny = 0;
		scanf("%s", s + 1); int len = strlen(s + 1);
		cnt['L'] = cnt['R'] = cnt['U'] = cnt['D'] = 0;
		for (int i = 1; i <= len; i++) {
			++cnt[s[i]];
			if (s[i] == 'L') --nx;
			if (s[i] == 'R') ++nx;
			if (s[i] == 'U') ++ny;
			if (s[i] == 'D') --ny;
		}
		bool ans = 1;
		ans &= (nx >= x) || (nx < x && x - nx <= cnt['L']);
		ans &= (nx <= x) || (nx > x && nx - x <= cnt['R']);
		ans &= (ny >= y) || (ny < y && y - ny <= cnt['D']);
		ans &= (ny <= y) || (ny > y && ny - y <= cnt['U']);
		puts(ans ? "YES" : "NO");	
	}
	return 0;
}