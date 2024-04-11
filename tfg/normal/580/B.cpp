#include <iostream>
#include <utility>
#include <algorithm>

typedef long long ll;
typedef std::pair<ll, ll> ii;

const int ms = 200200;

ii a[ms];

int main() {
	int n, d;
	std::cin >> n >> d;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
	}
	std::sort(a, a + n);
	ll ans = 0;
	ll cur_ans = 0;
	for(int l = 0, r = 0; l < n; l++) {
		while(r < n && a[r].first - a[l].first < d) {
			cur_ans += a[r].second;
			r++;
		}
		ans = std::max(ans, cur_ans);
		cur_ans -= a[l].second;
	}
	std::cout << ans << '\n';
}