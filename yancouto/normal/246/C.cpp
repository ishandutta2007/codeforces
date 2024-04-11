#include <cstdio>
#include <algorithm>
using namespace std;
int a[53];

int main() {
	int n, k, i, j, l, c;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	c = 0;
	for(i = n; c < k && i >= 0; i--) {
		for(j = i - 1; c < k && j >= 0; j--) {
			printf("%d %d", 1 + n - i, a[j]);
			for(l = i; l < n; l++)
				printf(" %d", a[l]);
			putchar('\n');
			c++;
		}
	}
	return 0;
}