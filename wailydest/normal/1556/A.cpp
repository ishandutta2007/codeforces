#include <cstdio>

int t, c, d;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &c, &d);
		if (!c && !d) printf("0");
		else if (c == d) printf("1", c);
		else if (c + d & 1) printf("-1");
		else printf("2");
		printf("\n");
	}
	return 0;
}