#include <cstdio>
#include <cstring>

const int LG = 30;
const int N = 200000;
int t, n, amt[LG];
bool u[N + 1];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(amt, 0, LG << 2);
		for (int i = 0; i < n; ++i) {
			int v;
			scanf("%d", &v);
			for (int i = 0; i < LG; ++i) if (v >> i & 1) ++amt[i];
		}
		memset(u, 0, n + 1);
		for (int i = 0; i < LG; ++i) for (int j = 1; j <= n; ++j) if (amt[i] % j) u[j] = true;
		for (int i = 1; i <= n; ++i) if (!u[i]) printf("%d ", i);
		printf("\n");
	}
	return 0;
}