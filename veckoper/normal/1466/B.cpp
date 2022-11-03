#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int Case, n, a[N];
int main() {
	scanf("%d", &Case);
	while (Case--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
		}
		a[n + 1] = 1e9;
		for (int i = n; i; --i) {
			if (a[i] + 1 < a[i + 1]) ++a[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) ans += (a[i] != a[i + 1]);
		printf("%d\n", ans);
	}
	return 0;
}