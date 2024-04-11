#include <cstdio>
#include <algorithm>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		if (n <= 3) {
			printf("1\n%d\n", n - 2);
			continue;
		}
		int lg = 31 - __builtin_clz(n);
		printf("%d\n", lg);
		for (int i = 1; i < lg - 1; ++i) printf("%d ", 1 << (i - 1));
		n -= (1 << lg) - 1;
		int f = min(n / 2, (1 << (lg - 1)) >> 1);
		printf("%d %d\n", f, n - f * 2);
	}
}