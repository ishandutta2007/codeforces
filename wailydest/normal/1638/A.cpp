#include <cstdio>
#include <algorithm>

const int N = 500;
int t, n, p[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int fi = n, pos;
		for (int i = 0; i < n; ++i) {
			scanf("%d", p + i);
			if (fi == n && p[i] != i + 1) fi = i;
			if (fi != n && p[i] == fi + 1) pos = i;
		}
		int l, r;
		if (fi == n) l = n - 1, r = n - 1;
		else l = fi, r = pos;
		std::reverse(p + l, p + r + 1);
		for (int i = 0; i < n; ++i) printf("%d ", p[i]);
		printf("\n");
	}
	return 0;
}