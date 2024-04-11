#include <cstdio>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		printf("%d\n", n * (k / (n - 1)) + (k % (n - 1)) - (!(k % (n - 1))));
	}
	return 0;
}