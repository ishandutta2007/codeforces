#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
		  if (i * j >= n) {
				printf("%d%d", i * j / n, i * j % n);
			} else {
			  printf("%d", i * j);
			}
			if (j != n - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}