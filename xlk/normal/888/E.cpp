#include <bits/stdc++.h>
using namespace std;
int a[40], n, m, ans;
int l[1 << 20];
int r[1 << 20];
void gen(int *a, int n, int *b) {
	for (int i = 0; i < n; i++) {
		b[1 << i] = a[i];
	}
	for (int i = 0; i < 1 << n; i++) {
		b[i] = (b[i - (i & -i)] + b[i & -i]) % m;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] %= m;
	}
	int L = n / 2;
	int R = n - L;
	gen(a, L, l);
	gen(a + L, R, r);
	sort(l, l + (1 << L));
	sort(r, r + (1 << R));
	int pr = (1 << R) - 1;
	for (int pl = 0; pl < 1 << L; pl++) {
		while (l[pl] + r[pr] >= m) {
			pr--;
		}
		ans = max(ans, l[pl] + r[pr]);
	}
	cout << ans << endl;
	return 0;
}