#include <cstdio>

int t, n, d;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &d);
		int mn1 = 500, mn2 = 500;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			int v;
			scanf("%d", &v);
			if (v > d) ok = false;
			if (v < mn1) {
				mn2 = mn1;
				mn1 = v;
			}
			else if (v < mn2) mn2 = v;
		}
		if (ok || mn1 + mn2 <= d) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}