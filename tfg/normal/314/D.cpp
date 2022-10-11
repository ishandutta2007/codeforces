#include <iostream>
#include <utility>
#include <algorithm>
#include <cstdio>

typedef long long ll;
typedef std::pair<ll, ll> ii;

const int ms = 100100;
const ll INF = 1e18;

int n;
ii a[ms];
ii suffix[ms];

ii combine(ii a, ii b) {
	return ii(std::min(a.first, b.first), std::max(a.second, b.second));
}

bool can(ll d) {
	ii left(INF, -INF);
	for(int l = 0, r = 0; l < n; l++) {
		while(r < n && a[r].first <= 2 * d + a[l].first) r++;
		ii cur = combine(left, suffix[r]);
		//std::cout << "for (" << l << ", " << r << "), got (" << left.first << ", " << left.second << "), (" << cur.first << ", " << cur.second << ")\n";
		left = combine(left, ii(a[l].second, a[l].second));
		if((cur.second - cur.first) <= 2 * d) return true;
	}
	return false;
}

int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		a[i] = ii(2 * (x + y), 2 * (x - y));
	}
	std::sort(a, a + n);
	//for(int i = 0; i < n; i++) std::cout << a[i].first << ' ' << a[i].second << '\n';
	suffix[n] = ii(INF, -INF);
	for(int i = n - 1; i >= 0; i--) {
		suffix[i] = combine(suffix[i + 1], ii(a[i].second, a[i].second));
	}
	ll l = 0, r = INF;
	while(l != r) {
		ll mid = (l + r) / 2;
		if(can(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l / 2 << '.' << l % 2 * 5 << '\n';
}