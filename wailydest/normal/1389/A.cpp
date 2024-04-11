#include <cstdio>

int main() 
{
	int t;
	scanf("%d", &t);
	int l, r;
	while (t--) {
		scanf("%d%d", &l, &r);
		if (l * 2 <= r) printf("%d %d\n", l, l * 2);
		else printf("-1 -1\n");
	}
	return 0;
}