#include <iostream>
#include <algorithm>
#include <iostream>

typedef long long ll;

const int ms = 200200;

ll a[ms];

int main() {
	int n, q;
	std::cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		a[i] += a[i - 1] + t;
	}
	ll prv = 0;
	while(q--) {
		ll v;
		scanf("%lld", &v);
		v = v + prv;
		int idx = std::upper_bound(a + 1, a + n + 1, v) - a - 1;
		if(idx == n) {
			prv = 0;
			idx = 0;
		} else {
			prv = v;
		}
		printf("%d\n", n - idx);
	}
}