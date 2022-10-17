#include <bits/stdc++.h>
using namespace std;
int a[200020];
int b[200020];
int c[200020];
int n, k, x;
int main() {
	scanf("%d%d%d", &n, &k, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] | a[i];
	}
	for (int i = n; i >= 1; i--) {
		c[i] = c[i + 1] | a[i];
	}
	long long ans = 0;
	long long tmp = 1;
	for (int i = 0; i < k; i++) {
		tmp *= x;
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, tmp * a[i] | b[i - 1] | c[i + 1]);
	}
	cout << ans << endl;
	return 0;
}