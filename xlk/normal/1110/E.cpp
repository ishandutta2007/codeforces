#include <bits/stdc++.h>
using namespace std;
int n;
int a[100020];
int b[100020];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = n; i > 0; i--) {
		a[i] -= a[i - 1];
		b[i] -= b[i - 1];
	}
	sort(a + 2, a + 1 + n);
	sort(b + 2, b + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}