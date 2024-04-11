#include <iostream>
#include <cstdio>
#include <algorithm>

const int me = 21;
const int ms = 1 << 21;

typedef long long ll;

int a[ms];
int buffer[ms];
ll tot[me], cur[me];

void pre(int n) {
	int pot = 0;
	for(int len = 1; len < n; len += len) {
		pot++;
		for(int i = 0; i < n; i += 2 * len) {
			for(int l = 0, r = 0; l < len;) {
				while(r < len && a[i + len + r] < a[i + l]) r++;
				int valsl = 0, valsr = 0;
				while(r < len && a[i + len + r] == a[i + l]) r++, valsr++;
				l++;
				valsl++;
				while(l < len && a[i + l] == a[i + l - 1]) l++, valsl++;
				tot[pot] -= (ll) valsl * valsr;
				cur[pot] += (ll) valsl * (r - valsr);
			}
			std::merge(a + i, a + i + len, a + i + len, a + i + len + len, buffer);
			for(int j = 0; j < len + len; j++) {
				a[i + j] = buffer[j];
			}
			tot[pot] += (ll) len * len;
		}
		// std::cout << "for pot " << pot << ", got (" << cur[pot] << ", " << tot[pot] << ")\n";
	}
}

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < (1 << n); i++) {
		scanf("%d", a + i);
	}
	pre(1 << n);
	int m;
	std::cin >> m;
	while(m--) {
		int x;
		scanf("%d", &x);
		ll ans = 0;
		for(int i = 0; i <= x; i++) {
			cur[i] = tot[i] - cur[i];
		}
		for(int i = 0; i <= n; i++) {
			ans += cur[i];
		}
		printf("%lld\n", ans);
	}
}