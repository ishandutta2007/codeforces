#include <cstdio>

const int N = 1000;
int t, n, m;
char s[N][N + 1];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%s", s[i]);
		if (m & 1) {
			printf("YES\n");
			for (int i = 0; i <= m; ++i) printf("%d ", (i & 1) + 1);
			printf("\n");
		}
		else if (n == 2) {
			if (s[0][1] == s[1][0]) {
				printf("YES\n");
				for (int i = 0; i <= m; ++i) printf("%d ", (i & 1) + 1);
				printf("\n");
			}
			else printf("NO\n");
		}
		else {
			printf("YES\n");
			int f;
			if (s[0][1] == s[1][2]) f = 1;
			else if (s[2][0] == s[0][1]) f = 0;
			else f = 2;
			for (int i = 0; i <= m; ++i) printf("%d ", (f + m + i) % 3 + 1);
			printf("\n");
		}
	}
	return 0;
}