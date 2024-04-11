#include <iostream>
#include <vector>

const int INF = 1.1e9;

std::pair<int, int> combine(std::pair<int, int> a, std::pair<int, int> b) {
	return std::pair<int, int>(std::max(a.first, b.first), std::min(a.second, b.second));
}

std::vector<std::pair<int, int> > compress(std::vector<std::pair<int, int> > a) {
	int n = a.size();
	std::vector<std::pair<int, int> > pref(n + 1, std::pair<int, int>(-INF, INF));
	std::vector<std::pair<int, int> > suf(n + 1, std::pair<int, int>(-INF, INF));
	for(int i = 0; i < n; i++) {
		pref[i + 1] = combine(pref[i], a[i]);
		suf[n - i - 1] = combine(suf[n - i], a[n - i - 1]);
	}
	for(int i = 0; i < n; i++) {
		a[i] = combine(pref[i], suf[i + 1]);
	}
	return a;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int> > x, y;

	for(int i = 1; i <= n; i++) {
		int x1, x2, y1, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		x.push_back(std::pair<int, int>(x1, x2));
		y.push_back(std::pair<int, int>(y1, y2));
	}
	x = compress(x);
	y = compress(y);
	for(int i = 0; i < n; i++) {
		//std::cout << i << ": (" << x[i].first << ", " << x[i].second << "), (" << y[i].first << ", " << y[i].second << ")\n";
		if(x[i].first <= x[i].second && y[i].first <= y[i].second) {
			std::cout << x[i].first << ' ' << y[i].first << std::endl;
			return 0;
		}
	}
}