#include <bits/stdc++.h>

using i64 = long long;

const double eps = 0.5;

double query(std::vector<std::pair<double, double>> p) {
	std::cout << "? " << p.size() << std::endl;
	for (auto [x, y] : p) {
		std::cout << x << " " << y << std::endl;
	}
	double res;
	std::cin >> res;
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::pair<double, double>> p;
	p.push_back({0, m});
	for (int i = m - 1; i > 0; i--) {
		p.push_back({n, i});
		p.push_back({0, i});
	}
	p.push_back({n, 0});
	p.push_back({n + 1, 0});
	p.push_back({n + 1, m});

	double x = (n * query(p)) - eps;

	p.clear();
	p.push_back({0, m + 1});
	p.push_back({0, 0});
	for (int i = 1; i < n; i++) {
		p.push_back({i, m});
		p.push_back({i, 0});
	}
	p.push_back({n, m});
	p.push_back({n, m + 1});	

	double y = (m * query(p)) - eps;

	std::cout << std::setprecision(10) << std::fixed << "! " << x << " " << y << std::endl;

	return 0;
}