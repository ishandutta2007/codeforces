#include <cstdio>

int t, n, k;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		int fi, pr, lim, prx;
		scanf("%d", &fi);
		pr = fi;
		bool ok = 1;
		for (int i = 1; i < k; ++i) {
			int s;
			scanf("%d", &s);
			s -= pr;
			if (i > 1 && s < prx) ok = 0;
			if (i == 1) lim = s;
			prx = s;
			pr = s + pr;
		}
		printf("%s\n", ok && (k == 1 || (long long)(n - k + 1) * lim >= fi) ? "Yes" : "No");
	}
	return 0;
}