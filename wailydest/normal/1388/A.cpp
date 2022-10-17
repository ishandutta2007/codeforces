#include <cstdio>

int main() 
{
	int t;
	scanf("%d", &t);
	int a = 6, b = 10, c = 14;
	while (t--) {
		int n;
		scanf("%d", &n);
		int k = n - a - b - c;
		if (k > 0 && k != a && k != b && k != c) printf("YES\n%d %d %d %d\n", a, b, c, k);
		else if (k > 1) printf("YES\n%d %d %d %d\n", a, b, 15, k - 1);
		else printf("NO\n");
	}
	return 0;
}