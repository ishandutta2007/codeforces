#include <cstdio>

const int LG = 30;
int n;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int c[LG] = {0};
		for (int i = 0; i < n; ++i) {
			int v;
			scanf("%d", &v);
			for (int j = 0; j < LG; ++j) if ((v >> j) & 1) ++c[j];
		}
		int res = 0;
		for (int i = LG - 1; i >= 0 && !res; --i) if (c[i]) {
			if (c[i] & 1) {
				if ((c[i] & 3) == 1 || !(n & 1)) res = 1;
				else res = 2;
			}
		}
		if (!res) printf("DRAW\n");
		else if (res == 1) printf("WIN\n");
		else printf("LOSE\n");
	}
	return 0;
}