#include <cstdio>

const int N = 50;
int t, n, m, r, c;
char s[N + 1];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &n, &m, &r, &c);
		bool any = 0, rc = 0, rrcc = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			for (int j = 0; s[j]; ++j) if (s[j] == 'B') {
				any = 1;
				if (c - 1 == j || r - 1 == i) rc = 1;
				if (c - 1 == j && r - 1 == i) rrcc = 1;
			}
		}
		if (rrcc) printf("0");
		else if (rc) printf("1");
		else if (any) printf("2");
		else printf("-1");
		printf("\n");
	}
	return 0;
}