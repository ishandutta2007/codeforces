#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 50;
int t, n, a[N];
bool u[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		std::sort(a, a + n);
		bool ok = 1;
		memset(u, 0, n);
		for (int i = n; i > 0 && ok; --i) {
			int j;
			for (j = 0; j < n; ++j) if (!u[j]) {
				int k;
				for (k = a[j]; k > i; k >>= 1);
				if (k == i) {
					u[j] = 1;
					break;
				}
			}
			if (j == n) ok = 0;
		}
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}