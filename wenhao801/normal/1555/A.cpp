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
		long long n; cin >> n;
		n = (n + 1) >> 1;
		if (n <= 100) {
			int ans = 1e9;
			for (int i = 0; i <= n / 3 + 1; i++) for (int j = 0; j <= n / 4 + 1; j++) for (int k = 0; k <= n / 5 + 1; k++)
				if (i * 3 + j * 4  + k * 5 >= n) ans = min(ans, i * 15 + j * 20 + k * 25);
			cout << ans << endl;
		}
		else {
			printf("%lld\n", n * 5);
		}
	}
	return 0;
}