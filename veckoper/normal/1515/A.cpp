#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, Case, a[N], x;
int main() {
	scanf("%d", &Case);
	while (Case--) {
		scanf("%d%d" ,&n, &x);
		int sm = 0;
		int ps = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			sm += a[i];
			if (sm == x) ps = i;
		}
		if (ps == n) {
			puts("NO");
		} else if (ps) {
			puts("YES");
			for (int i = 1; i < ps; ++i) printf("%d ", a[i]);
			printf("%d %d ", a[ps + 1], a[ps]);
			for (int i = ps + 2; i <= n; ++i) printf("%d ", a[i]);
			puts("");
		} else {
			puts("YES");
			for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
			puts("");
		}
	}
	return 0;
}