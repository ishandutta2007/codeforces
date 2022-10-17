#include <cstdio>

const int N = 100000;
int t, n, k;
char s[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%s", &n, &k, s);
		int pref, suf;
		for (pref = 0; pref < n && s[pref] == '0'; ++pref);
		if (pref == n) printf("%d\n", 0);
		else {
			for (suf = 0; s[n - suf - 1] == '0'; ++suf);
			int ans = 0;
			for (int i = 0; i < n - 1; ++i) ans += (s[i] == '1') * 10;
			for (int i = 1; i < n; ++i) ans += s[i] == '1';
			int upd = 0;
			if (pref + suf != n - 1 || pref && suf) {
				if (pref && pref <= k) upd = -1;
				if (suf && suf <= k) upd = -10;
				if (pref && suf && pref + suf != n - 1 && pref + suf <= k) upd = -11;
			} else if (suf && n - 1 <= k) upd = -9;
			printf("%d\n", ans + upd);
		}
	}
	return 0;
}