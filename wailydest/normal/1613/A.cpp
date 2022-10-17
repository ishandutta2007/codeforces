#include <cstdio>

int t, x1, p1, x2, p2;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &x1, &p1, &x2, &p2);
		while (p1 && x1 < 1000000) {
			--p1;
			x1 *= 10;
		}
		while (p2 && x2 < 1000000) {
			--p2;
			x2 *= 10;
		}
		if (x1 == x2 && p1 == p2) printf("=");
		else {
			if (p1 && !p2) printf(">");
			else if (!p1 && p2) printf("<");
			else {
				if (p1 != p2) {
					x1 = p1;
					x2 = p2;
				}
				if (x1 < x2) printf("<");
				else printf(">");
			}
		}
		printf("\n");
	}
	return 0;
}