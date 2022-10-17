#include <cstdio>

const int N = 100;
int t, n, a[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bool ok = 1;
		int len = 1;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			if (ok) {
				if (a[i]) {
					if (i && a[i - 1]) len += 5;
					else ++len;
				} else if (i && !a[i - 1]) ok = 0;
			}
		}
		if (ok) printf("%d\n", len);
		else printf("-1\n");
	}
	return 0;
}