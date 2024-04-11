#include <cstdio>

int t, n, s;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &s);
		printf("%d\n", s / ((n >> 1) + 1));
	}
	return 0;
}