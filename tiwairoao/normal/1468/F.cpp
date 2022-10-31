#include <bits/stdc++.h>

int gcd(int x, int y) {
	return y == 0 ? (x >= 0 ? x : -x) : gcd(y, x % y);
}

std::map<std::pair<int, int>, int>mp;

int calc(int x, int y) {
	int d = gcd(x, y); x /= d, y /= d;
	mp[std::make_pair(x, y)]++;
	return mp[std::make_pair(-x, -y)];
}

void solve() {
	mp.clear(); long long ans = 0; int n; scanf("%d", &n);
	while( n-- ) {
		int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		ans += calc(x2 - x1, y2 - y1);
	}
	printf("%lld\n", ans);
}


int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}