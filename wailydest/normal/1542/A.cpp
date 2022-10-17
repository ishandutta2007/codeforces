#include <cstdio>

int t, n;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int r[2] = {0, 0};
		for (int i = 0; i < 2 * n; ++i) {
			int v;
			scanf("%d", &v);
			++r[v & 1];
		}
		if (r[0] == r[1]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}