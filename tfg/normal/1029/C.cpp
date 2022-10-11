#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int test(std::vector<std::pair<int, int>> a, int sk) {
	int l = 0, r = 1e9;
	for(int i = 0; i < a.size(); i++) {
		if(i != sk) {
			l = std::max(a[i].first, l);
			r = std::min(a[i].second, r);
		}
	}
	return r - l;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
		p[i] = i;
	}
	int ans = 0;
	std::sort(p.begin(), p.end(), [&](int l, int r) { return a[l].first > a[r].first; });
	ans = std::max(ans, std::max(test(a, p[0]), test(a, p[1])));
	std::sort(p.begin(), p.end(), [&](int l, int r) { return a[l].second < a[r].second; });
	ans = std::max(ans, std::max(test(a, p[0]), test(a, p[1])));
	std::cout << ans << std::endl;
}