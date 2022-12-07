#include <bits/stdc++.h>

using namespace std;

int main() {
	int q;
	scanf ("%d", &q);
	while (q--) {
		int n, a, cnt = 0;
		scanf ("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf ("%d", &a);
			cnt += !a;
		}
		n >>= 1;
		if (cnt >= n) {
			printf ("%d\n", n);
			for (int i = 1; i <= n; ++i)
				printf ("0 ");
		}
		else {
			printf ("%d\n", n + (n & 1));
			for (int i = 1; i <= n + (n & 1); ++i)
				printf ("1 ");
		}
		puts("");
	}
	return 0;
}