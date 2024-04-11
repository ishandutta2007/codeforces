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

int cnt[28] = {};
int cnt2[28] = {};
char a[101], b[101];

int main () {
	int T = read();
	while (T--) {
		scanf("%s", a + 1); scanf("%s", b + 1);
		int i, j;
		int la = strlen(a + 1), lb = strlen(b + 1);
		for (i = 1; i <= 26; i++) cnt[i] = 0;
		for (i = 1; i <= la; i++) cnt[a[i] - 'a' + 1]++; bool f = false;
		for (i = 1; i + la - 1 <= lb; i++) {
			for (j = 1; j <= 26; j++) cnt2[j] = 0;
			for (j = i; j <= i + la - 1; j++) cnt2[b[j] - 'a' + 1]++;
			bool f2 = false;
			for (j = 1; j <= 26; j++) if (cnt2[j] != cnt[j]) {f2 = true; break; }
			if (!f2) { f = true; break; }
		}
		if (f) puts("YES"); else puts("NO");

	}
	return 0;
}