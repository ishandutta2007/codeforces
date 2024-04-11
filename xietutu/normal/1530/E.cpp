#include <bits/stdc++.h>
using namespace std;

int f[51], diff;
char s[200005];

int main() {
	int T;
	scanf("%d", &T);
	while (T --) {
		scanf("%s", s); int n = strlen(s);
		for (int i = 0; i < 26; ++ i) f[i] = 0;
		diff = 0;
		for (int i = 0; i < n; ++ i) {
			if (f[s[i] - 'a'] == 0) ++ diff;
			f[s[i] - 'a'] ++;
		}
		int fd = -1;
		for (int i = 0; i < 26; ++ i) {
			if (f[i] == 1) {
				fd = i;
				break;
			}
		}
		if (fd != -1) {
			putchar('a' + fd);
			-- f[fd];
			for (int t = 0; t < 26; ++ t) {
				for (int j = 0; j < f[t]; ++ j) putchar('a' + t);
			}
		} else {
			-- diff;
			int mint = 0;
			while (f[mint] == 0) ++ mint;
			if (f[mint] - 2 > n - f[mint]) {
				putchar('a' + mint);
				-- f[mint];
				if (diff > 1) {
					int t = mint + 1;
					while (f[t] == 0) ++ t;
					putchar('a' + t); -- f[t];
					for (int i = 0; i < f[mint]; ++ i) {
						putchar('a' + mint);
					}
					++ t; while (f[t] == 0) ++ t;
					putchar('a' + t); -- f[t];
					f[mint] = 0;
					for (t = 0; t < 26; ++ t) {
						for (int j = 0; j < f[t]; ++ j) putchar('a' + t);
					}
				} else {
					int t = mint + 1;
					for (; t < 26; ++ t) {
						for (int j = 0; j < f[t]; ++ j) putchar('a' + t);
					}
					for (int i = 0; i < f[mint]; ++ i) putchar('a' + mint);
				}
			} else {
				if (f[mint] > 1) {
					putchar('a' + mint);
					putchar('a' + mint);
					f[mint] -= 2;
				} else {
					putchar('a' + mint);
					f[mint] -= 1;
				}
				int t = mint + 1;
				for (int i = 0; i < f[mint]; ++ i) {
					while (t < 26 && f[t] == 0) ++ t;
					putchar('a' + t);
					-- f[t];
					putchar('a' + mint);
				}
				f[mint] = 0;
				for (t = 0; t < 26; ++ t) {
					for (int j = 0; j < f[t]; ++ j) putchar('a' + t);
				}
			}
		}
		putchar('\n'); 
	}
	return 0;
}