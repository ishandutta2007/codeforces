#include <cstdio>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int i;
		for (i = 1; i * i <= n && (n % i || n / i > k); ++i);
		if (i * i <= n) {
			printf("%d\n", i);
			continue;
		}
		while (n % i || i > k) --i;
		printf("%d\n", n / i);
	}
	return 0;
}