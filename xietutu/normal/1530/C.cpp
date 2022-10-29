#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005];

int calcmax(int n, int a[], int mid) {
	int K = n + mid - (n + mid) / 4;
	int sum = 0;
	sum += 100 * min(mid, K);
	K -= min(mid, K);
	return sum + a[n - K + 1];
}

int calcmin(int n, int b[], int mid) {
	int K = n + mid - (n + mid) / 4;
	if (K > n) K = n;
	return b[n - K + 1];
}


int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &b[i]);
		}
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		for (int i = n - 1; i; -- i) {
			a[i] += a[i + 1];
			b[i] += b[i + 1];
		}
		int l = 0, r = 400000;
		while (r - l + 1 > 0) {
			int mid = (l + r) >> 1;
			if (calcmax(n, a, mid) >= calcmin(n, b, mid)) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		printf("%d\n", l);
	}
	return 0;
}