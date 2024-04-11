#include <cstdio>
#include <cstring>

const int N = 500005;
int t, n, dp[N], u[N];
char s[N];

int f(int x) {
	if (x <= 100) return dp[x];
	return dp[x % 34 + 34 * 3];
}

int main() {
	dp[2] = 1;
	for (int i = 3; i <= 500; ++i) {
		memset(u, 0, sizeof u);
		for (int j = 0; j <= i - 2; ++j) u[dp[j] ^ dp[i - 2 - j]] = 1;
		for (dp[i] = 0; u[dp[i]]; ++dp[i]);
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &n, s);
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'R') ++cnt;
			else --cnt;
		}
		bool al;
		if (cnt > 0) al = 1;
		else if (cnt < 0) al = 0;
		else {
			int res = 0;
			for (int i = 0; i < n;) {
				int len = 0;
				do {
					++len;
					++i;
				} while (i < n && s[i] != s[i - 1]);
				res ^= f(len);
			}
			al = (bool)res;
		}
		printf("%s\n", al ? "Alice" : "Bob");
	}
	return 0;
}