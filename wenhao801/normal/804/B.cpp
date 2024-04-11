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

const int mod = 1e9 + 7;
int qpow (int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = 1ll * ret * x % mod;
		x = 1ll * x * x % mod; y >>= 1;
	}return ret;
}
char a[1001000];

int main () {
	scanf("%s", a + 1); int n = strlen(a + 1), now = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 'a') ++now;
		else ans = (ans + qpow(2, now) - 1) % mod;
	}
	printf("%d\n", (ans + mod) % mod);
	return 0;
}