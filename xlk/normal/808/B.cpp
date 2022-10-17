#include <bits/stdc++.h>
using namespace std;
int a[1000020];
int n, k;
int main() {
	scanf("%d%d", &n, &k);
	k = n - k + 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	double s = 0;
	for (int i = 0; i < k; i++) {
		s += a[i];
	}
	double ans = s;
	for (int i = k; i < n; i++) {
		s -= a[i - k];
		s += a[i];
		ans += s;
	}
	printf("%.9f\n", ans / k);
	return 0;
}