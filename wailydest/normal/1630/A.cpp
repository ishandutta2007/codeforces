#include <cstdio>
#include <cstring>

int t, n, k;
bool u[100000];

int inv(int x) 
{
	return x ^ n - 1;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		if (k == n - 1 && n == 4) printf("-1\n");
		else {
			memset(u, 0, n);
			int l = 31 - __builtin_clz(n), un;
			for (un = 0; k >> un & 1; ++un);
			if (k) {
				int x = k, y = 0;
				if (k == n - 1) {
					x = k - 1;
					u[x] = u[y] = u[inv(x)] = u[inv(y)] = 1;
					printf("%d %d\n%d %d\n", x, inv(y), y, inv(x));
					x = (1 << l - 1) + 1;
					y = 1 << l - 1;
				}
				u[x] = u[y] = u[inv(x)] = u[inv(y)] = 1;
				printf("%d %d\n%d %d\n", x, inv(y), y, inv(x));
			}
			for (int i = 0; i < n; ++i) if (!u[i] && i < inv(i)) printf("%d %d\n", i, inv(i));
		}
	}
	return 0;
}