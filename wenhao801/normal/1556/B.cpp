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

const int MAXN = 100100;
int n, a[MAXN];

int main () {
	int T = read();
	while (T--) {
		n = read(); int i, j, cnt[2] = {};
		for (i = 1; i <= n; i++) a[i] = read(), ++cnt[a[i] & 1];
		if (cnt[0] - cnt[1] < -1 || cnt[0] - cnt[1] > 1) { puts("-1"); continue; }
		long long ans = 0;
		if (cnt[0] > cnt[1]) {
			cnt[0] = cnt[1] = 0; 
			for (i = 1; i <= n; i++) {
				if (a[i] & 1) ++cnt[1], ans += abs(i - cnt[1] * 2);
			}
		}
		else if (cnt[0] < cnt[1]) {
			cnt[0] = cnt[1] = 0; 
			for (i = 1; i <= n; i++) {
				if (a[i] % 2 == 0) ++cnt[0], ans += abs(i - cnt[0] * 2);
			}
		}
		else {
			cnt[0] = cnt[1] = 0; 
			long long tmp = 0;
			for (i = 1; i <= n; i++) {
				if (a[i] & 1) ++cnt[1], ans += abs(i - (cnt[1] * 2 - 1)), tmp += abs(i - cnt[1] * 2);
			}
			ans = min(ans, tmp);
		}
		cout << ans << endl;
	}
	return 0;
}