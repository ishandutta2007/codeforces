#include <cstdio>
#include <cassert>

const int K = 720720;
int n, m;

int main() 
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int v;
			scanf("%d", &v);
			if (i + j & 1) printf("%d ", K);
			else {
				for (int j = 1;; ++j) {
					int x = j * j * j * j;
					assert(x <= K);
					if (!((K - x) % v)) {
						printf("%d ", K - x);
						break;
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}