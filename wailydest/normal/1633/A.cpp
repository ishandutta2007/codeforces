#include <cstdio>

int t, n;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n % 7) {
			n = n / 10 * 10;
			while (n % 7) ++n;
		}
		printf("%d\n", n);
	}
	return 0;
}