#include <bits/stdc++.h>
using namespace std;

using point = complex<long long>;
#define x real()
#define y imag()

long long cross(point p, point q) {
	return (conj(p) * q).y;
}

long long orient(point p, point q, point r) {
	return cross(q - p, r - p);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<point> points;
	for (int i = 0; i < n; ++i) {
		long long xi, yi;
		cin >> xi >> yi;
		yi -= xi * xi;
		points.emplace_back(xi, yi);
	}

	sort(points.begin(), points.end(), [](point a, point b) {
		return make_tuple(a.x, a.y) < make_tuple(b.x, b.y);
	});

	vector<point> hull;
	for (auto i : points) {
		if (!hull.empty() && hull.back().x == i.x) {
			hull.pop_back();
		}
		while (hull.size() >= 2u && orient(hull[hull.size() - 2u], hull.back(), i) >= 0) {
			hull.pop_back();
		}
		hull.push_back(i);
	}

	cout << hull.size() - 1u << "\n";
}