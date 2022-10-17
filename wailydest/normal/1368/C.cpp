#include <cstdio>
using namespace std;

int main() 
{
	int n;
	scanf("%d", &n);
	printf("%d\n", (n - 1) * 2 + 14 + n);
	printf("0 0\n1 0\n2 0\n0 1\n2 1\n0 2\n1 2\n");
	for (int i = 1; i <= n; ++i) printf("%d %d\n%d %d\n%d %d\n", i + 1, i + 1, i + 2, i + 1, i + 1, i + 2);
	printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n", n + 3, n + 1, n + 3, n + 2, n + 3, n + 3, n + 2, n + 3, n + 1, n + 3);
	return 0;
}