#include <cstdio>
#include <algorithm>

int t, n;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int ll = ~(1 << 31), rr = 1 << 31, lc, rc, both;
		for (int i = 0; i < n; ++i) {
			int l, r, c;
			scanf("%d%d%d", &l, &r, &c);
			if (l < ll) {
				ll = l;
				lc = c;
				both = ~(1 << 31);
			}
			if (l == ll) lc = std::min(lc, c);
			if (r > rr) {
				rr = r;
				rc = c;
				both = ~(1 << 31);
			}
			if (r == rr) rc = std::min(rc, c);
			if (l == ll && r == rr) both = std::min(both, c);
			printf("%d\n", std::min(both, rc + lc));
		}
	}
	return 0;
}