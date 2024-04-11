#include <iostream>
#include <algorithm>
#include <utility>

typedef long long ll;
typedef std::pair<ll, ll> ii;

bool cmp(ii a, ii b) {
	return a.first * b.second - a.second * b.first > 0;
}

ii a[100100];

int main() {
	int n;
	std::cin >> n;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		ii cur(0, 0);
		for(auto a : str) {
			if(a == 's') {
				cur.first++;
			} else {
				cur.second++;
				ans += cur.first;
			}
		}
		a[i] = cur;
	}
	ll s = 0;
	std::sort(a, a + n, cmp);
	for(int i = 0; i < n; i++) {
		ans += a[i].second * s;
		s += a[i].first;
	}
	std::cout << ans << '\n';
}