#include <cstdio>

int t, n, m;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		if (n == 1 && m == 1) printf("0\n");
		else if (n == 1 || m == 1) printf("1\n");
		else printf("2\n");
	}
	return 0;
}