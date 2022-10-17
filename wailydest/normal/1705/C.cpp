#include <cstdio>
#include <algorithm>

const int N = 200000;
int n, c, q, t;
long long bef[N], l[N], r[N];
char s[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &c, &q);
		scanf("%s", s);
		bef[0] = n;
		for (int i = 0; i < c; ++i) {
			scanf("%lld%lld", l + i, r + i);
			--l[i];
			bef[i + 1] = std::min(~((long long)1 << 63) >> 2, bef[i] + r[i] - l[i]);
		}
		while (q--) {
			long long k;
			scanf("%lld", &k);
			--k;
			for (int i = c - 1; i >= 0; --i) if (k >= bef[i]) k += l[i] - bef[i];
			printf("%c\n", s[k]);
		}
	}
	return 0;
}