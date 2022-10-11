#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef long long ll;

const int ms = 1010;

ll row[ms], col[ms];

ll getCost(int n, ll cost[ms], int x) {
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ll dist = abs((i - x) * 4 + 2);
		ans += dist * dist * cost[i];
	}
	return ans;
}

int bsearch(int n, ll cost[ms]) {
	int l = 0, r = n;
	while(l != r) {
		int mid = (l + r) / 2;
		if(getCost(n, cost, mid) <= getCost(n, cost, mid + 1)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			ll c;
			scanf("%lld", &c);
			row[i] += c;
			col[j] += c;
		}
	}
	int x = bsearch(n, row);
	int y = bsearch(m, col);
	std::cout << getCost(n, row, x) + getCost(m, col, y) << "\n";
	std::cout << x << " " << y << '\n';
}