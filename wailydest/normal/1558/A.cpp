#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

const int N = 400005;
int t, n, a, b;
bool u[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
		n = a + b;
		memset(u, 0, n << 1);
		for (int i = 0; i <= n && a >= 0 && b >= 0; i += 2) {
			int x = (n - i) / 2, y = (n - i + 1) / 2;
			if (x >= a) u[i + x - a] = true;
			if (y >= a) u[i + y - a] = true;
			if (x >= b) u[i + x - b] = true;
			if (y >= b) u[i + y - b] = true;
			--a;
			--b;
		}
		int sum = 0;
		for (int i = 0; i <= n; ++i) sum += u[i];
		printf("%d\n", sum);
		for (int i = 0; i <= n; ++i) if (u[i]) printf("%d ", i);
		printf("\n");
	}
	return 0;
}