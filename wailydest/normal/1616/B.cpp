#include <cstdio>

const int N = 100000;
int n, t;
char s[N + 1];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &n, s);
		if (s[0] == s[1]) {
			printf("%c%c\n", s[0], s[0]);
		} else {
			int ans = n - 1;
			for (int i = 0; i < n; ++i) {
				if (s[i] != s[i + 1] && s[i + 1] > s[i]) {
					ans = i;
					break;
				}
			}
			for (int i = 0; i <= ans; ++i) printf("%c", s[i]);
			for (int i = ans; i >= 0; --i) printf("%c", s[i]);
			printf("\n");
		}
	}
	return 0;
}