#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

	auto on = [](double x, double y, int x1, int y1, int x2, int y2) {
		return ((x >= x1 && x <= x2) && (y >= y1 && y <= y2));
	};

	auto chk = [&](double x, double y) {
		return !on(x, y, x3, y3, x4, y4) && !on(x, y, x5, y5, x6, y6);
	};

	for (double i = x1 + .5; i < x2; ++i) {
		if (chk(i, y1) || chk(i, y2)) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	for (double i = y1 + .5; i <= y2; ++i) {
		if (chk(x1, i) || chk(x2, i)) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
}