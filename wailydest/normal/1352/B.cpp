#include <cstdio>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		if (n & 1 && !(k & 1)) printf("NO\n");
		else {
			int x;
			if (!(k & 1) || n & 1) x = 1;
			else x = 2;
			if (k * x > n) {
				printf("NO\n");
				continue;
			}
			printf("YES\n");
			while (k > 1) {
				printf("%d ", x);
				n -= x;
				--k;
			}
			printf("%d\n", n);
		}
	}
	return 0;
}