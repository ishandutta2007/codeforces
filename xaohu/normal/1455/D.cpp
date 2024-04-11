#include <bits/stdc++.h>
 
using ll = long long;
using namespace std;

const int N = 505;

int t, n, x, a[N], ans;

bool ok() {
	for (int i = 1; i < n; ++i)
		if (a[i] > a[i + 1])
			return 0;
	return 1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; ++i)
			scanf("%d", a + i);
		ans = 0;
		while (!ok()) {
			int b = 0;
			for (int i = 1; i <= n; ++i) {
				if (a[i] > x) {
					b = i;
					break;
				}
			}
			if (!b) break;
			ans++;
			swap(a[b], x);
		}
		if (!ok()) ans = -1;
		printf("%d\n", ans);		
	}
	return 0;
}