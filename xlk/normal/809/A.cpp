#include <bits/stdc++.h>
using namespace std;

int a[300020], n, p = 1000000007;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	long long t = 1, ans = 0;
	for (int i = 0; i < n; i++) {
		ans = (ans + t * a[i]) % p;
		t = t * 2 % p;
	}
	t = 1;
	for (int i = n - 1; i >= 0; i--) {
		ans = (ans - t * a[i]) % p;
		t = t * 2 % p;
	}
	if (ans < 0) {
		ans += p;
	}
	printf("%d\n", (int)ans);
	return 0;
}