#include <bits/stdc++.h>
using namespace std;
char s[5020];
bool p[5020][5020];
int f[5020][5020];
int c[5020];
int main() {
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + i < n; j++) {
			if (i == 0) {
				p[j][j + i] = true;
			} else if (i == 1) {
				p[j][j + i] = (s[j] == s[j + i]);
			} else {
				p[j][j + i] = (s[j] == s[j + i] && p[j + 1][j + i - 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + i < n; j++) {
			if (p[j][j + i]) {
				int t = (i + 1) / 2;
				f[j][j + i] = min(f[j][j + t - 1], f[j + i - t + 1][j + i]) + 1;
				c[f[j][j + i]]++;
			}
		}
	}
	for (int i = n; i > 0; i--) {
		c[i - 1] += c[i];
	}
	for (int i = 1; i <= n; i++) {
		printf("%d%c", c[i], i == n ? '\n' : ' ');
	}
	return 0;
}