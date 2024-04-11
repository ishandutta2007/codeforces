#include <cstdio>
#include <algorithm>
#include <iostream>
typedef long long ll;
ll n,m,max,l,r,mid,k;
bool check(ll x) {
	ll s = 0; --x;
	for (int i = 1; i <= n; ++i)
		s += std::min(x / i,m);
	return s < k;
}
int main() {
	std::cin >> n >> m >> k;
	ll max = n * m;
	l = 1,r = max;
	while (l + 1 < r) {
		mid = (l + r) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	if (check(r)) std::cout << r;
	else std::cout << l;
}