#include <cstdio>

const int N = 500000;
int t, n;
char s[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &n, s);
		int amt = 0;
		for (int i = 0; s[i];) {
			int len = 0;
			do {
				++len;
				++i;
			} while (s[i] && (len != 1 || s[i - 1] != '(' || s[i] != ')') && s[i] != s[i - len]);
			if (s[i]) {
				++amt;
				++i;
				n -= len + 1;
			}
		}
		printf("%d %d\n", amt, n);
	}
	return 0;
}