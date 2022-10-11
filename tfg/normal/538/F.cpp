#include <iostream>
#include <algorithm>
#include <utility>

typedef std::pair<int, int> ii;

const int ms = 200200;

int bit[ms];

void upd(int x, int v) {
	for(; x < ms; x += x & - x) {
		bit[x] += v;
	}
}

int qry(int x) {
	x = std::min(x, ms - 1);
	int ans = 0;
	for(; x > 0; x -= x & -x) {
		ans += bit[x];
	}
	return ans;
}

int qry(int l, int r) {
	//std::cout << "making qry(" << l << ", " << r << ")\n";
	return qry(r) - qry(l - 1);
}

ii a[ms];
int ans[ms];

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first;
		a[i].second = i + 1;
	}
	std::sort(a, a + n);
	for(int i = 0, j = 0; i < n; i++) {
		while(a[j].first < a[i].first) {
			upd(a[j].second, 1);
			j++;
		}
		int pos = a[i].second;
		for(int k = 1; k * (pos - 1) + 2 <= n && k < n; k++) {
			//std::cout << "for pair (" << pos << ", " << k << ")\n";
			ans[k] += qry(k * (pos - 1) + 2, k * pos + 1);
		}
	}
	for(int i = 1; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}