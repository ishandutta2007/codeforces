#include <bits/stdc++.h>

typedef long long ll;

const int N = 100000;

ll f[N + 5];
struct node{ll a, b;}a[N + 5]; int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld%lld", &a[i].a, &a[i].b);
	std::sort(a + 1, a + n + 1, [](const node &a, const node &b) {
		return a.b < b.b;
	});

	ll s = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = std::max(f[i - 1], a[i].b - s), s += a[i].a;
	}

	ll t = 0, ans = 0;
	if (s <= a[1].b) {
		ans = s;
	} else {
		for (int i = n; i >= 1; i--) {
			if (f[i] <= t + a[i].a - 1) {
				ans = f[i];
				break;
			}
			t += a[i].a;
		}
	}
	printf("%lld\n", ans + s);
}