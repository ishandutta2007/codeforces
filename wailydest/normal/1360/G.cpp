#include <cstdio>
using namespace std;

const int N = 50;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, a, b;
		scanf("%d%d%d%d", &n, &m, &a, &b);
		bool matrix[N][N] = {{0}};
		if (n * a != m * b) printf("NO\n");
		else {
			printf("YES\n");
			for (int i = 0; i < n; ++i) for (int j = 0; j < a; ++j) matrix[i][(i * a + j) % m] = true;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) printf("%d", (int)matrix[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}