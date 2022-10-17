#include <cstdio>

int t, n;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int s = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			s += x;
		}
		if (!(s % n)) printf("0\n");
		else printf("1\n");
	}
	return 0;
}