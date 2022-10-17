#include <cstdio>
#include <cstring>

const int L = 30;
int t, n, l, amt[L];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &l);
		memset(amt, 0, l << 2);
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			for (int i = 0; i < l; ++i) if (x >> i & 1) ++amt[i];
		}
		int ans = 0;
		for (int i = 0; i < l; ++i) if (amt[i] * 2 > n) ans |= 1 << i;
		printf("%d\n", ans);
	}
	return 0;
}