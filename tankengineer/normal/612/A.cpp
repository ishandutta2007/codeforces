#include<cstdio>

const int MAXL = 105;

bool vis[MAXL];

bool solve(int n, int p, int q, char *s, int cnt) {
	if (vis[n]) {
		return false;
	}
	vis[n] = true;
	if (n == 0) {
		printf("%d\n", cnt);
		return true;
	} else {
		if (p <= n) {
			if (solve(n - p, p, q, s + p, cnt + 1)) {
				for (int i = 0; i < p; ++i) {
					printf("%c", *(s + p - i - 1));
				}
				printf("\n");
				return true;
			}
		}
		if (q <= n) {
			if (solve(n - q, p, q, s + q, cnt + 1)) {
				for (int i = 0; i < q; ++i) {
					printf("%c", *(s + q - i - 1));
				}
				printf("\n");
				return true;
			}
		}
		return false;
	}
}

int main() {
	int n, p, q;
	char s[MAXL];
	scanf("%d%d%d%s", &n, &p, &q, s);
	for (int i = 0; i < n; ++i) {
		vis[i] = false;
	}
	for (int i = 0; i < n - i - 1; ++i) {
		char tmp = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = tmp;
	}
	if (!solve(n, p, q, s, 0)) {
		printf("-1\n");
	}
	return 0;
}