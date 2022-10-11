#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

struct Info {
	ll cur, tot;
	
	void read() {
		scanf("%lld %lld", &tot, &cur);
	}
};

bool operator < (Info a, Info b) {
	return a.tot - a.cur < b.tot - b.cur;
}

int main() {
	int n, a, b;
	std::cin >> n >> a >> b;
	
	b = std::min(b, n);
	std::vector<Info> v(n);
	for(int i = 0; i < n; i++) {
		v[i].read();
	}
	std::sort(v.begin(), v.end());
	ll end = 0;
	ll rest = 0;
	for(int i = 0; i < b; i++) {
		end += std::max(0LL, v[n - i - 1].tot - v[n - i - 1].cur);
	}
	for(int i = 0; i < n; i++) {
		rest += v[n - i - 1].cur;
	}
	ll ans = rest + end;
	if(b == 0) {
		std::cout << ans << std::endl;
		return 0;
	}
	//std::cout << end << ' ' << rest << ' ' << ans << std::endl;
	ll fact = 1 << a;
	for(int i = 0; i < b; i++) {
		ans = std::max(ans, end + rest + v[n - i - 1].tot * fact - std::max(v[n - i - 1].tot, v[n - i - 1].cur));
	}
	//std::cout << ans << std::endl;
	end -= std::max(0LL, v[n - b].tot - v[n - b].cur);
	for(int i = b; i < n; i++) {
		ans = std::max(ans, end + rest + v[n - i - 1].tot * fact - v[n - i - 1].cur);
	}
	std::cout << ans << std::endl;
}