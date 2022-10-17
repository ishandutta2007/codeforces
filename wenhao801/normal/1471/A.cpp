#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

int main () {
	int T = read();
	while (T--) {
		long long n = read(), x = read();
		long long ans1 =0, ans2 = 0;
		while (n--) {
			int p = read();
			ans1 += p; ans2 += (p /x) + ((p % x == 0) ? 0 : 1);
		}
		ans1 = (ans1 / x) + ((ans1 % x == 0) ? 0ll : 1ll);
		printf("%lld %lld\n", ans1, ans2);
	}
	return 0;
}