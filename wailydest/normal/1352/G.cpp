#include <cstdio>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		if (n <= 3) printf("-1\n");
		else {
			int i;
			for (i = (1 ^ (n & 1)) + 1; i <= n; i += 2) printf("%d ", i);
			i -= 5;
			printf("%d %d ", i, i + 2);
			i -= 2;
			while (i > 0) {
				printf("%d ", i);
				i -= 2;
			}
			printf("\n");
		}
	}
	return 0;
}