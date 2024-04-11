#include <cstdio>


int n, tot;
int M[20], D[20];
bool vis[1000005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &M[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &D[i]);
	for (int j = 0; j <= 1000000; ++j)
		for (int i = 1; i <= n; ++i)
			if (j % M[i] == D[i]) {
				++tot; break;
			}
	printf("%.8lf\n", 1.0 * tot / 1000000);
	return 0;
}