#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

typedef long long ll;

struct PT {
	ll x, y;
	int t, idx;

	void read(int id) {
		idx = id;
		scanf("%d", &t);
		scanf("%lld %lld", &x, &y);
	}
};

const int ms = 200200;

PT pts[ms];

int main() {
	int n;
	ll a, b;
	std::cin >> n >> a >> b;
	std::map<ll, int> freq;
	std::map<ll, std::map<ll, int> > other;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		pts[i].read(i);
		ll rate = pts[i].x * a - pts[i].y;
		ans += freq[rate]++;
		ans -= other[rate][pts[i].x]++;
	}
	std::cout << 2 * ans << std::endl;
}