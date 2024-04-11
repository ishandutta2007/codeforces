#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct point{
	long double x, y;
	point() {}
	void init() {
		cin >> x >> y;
	}
	point(long double x, long double y) {
		this->x = x;
		this->y = y;
	}
	long double man_dist(point a) {
		return (abs(x - a.x) + abs(y - a.y));
	}
	long double dist(point a) {
		return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
	}
};

point some_p, diff;
vector <point> good;

struct line{
	long double a, b, c;
	line() {}
	void init() {
		cin >> a >> b >> c;
	}
	line(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	long double get_y(long long x) {
		return (-c - a * x) / b;
	}
	long double get_x(long long y) {
		//cout << 42 << endl;
		return (-c - b * y) / a;
	}
	void find_near_p(point t) {	
		good.push_back(point(t.x, get_y(t.x)));
		good.push_back(point(get_x(t.y), t.y));
	}
};

int main() {
	//cout << gcd(-6, 2) << ' ' << gcd(-2, 6) << endl;
	cout.precision(20);
	point a, b;
	line l;
	l.init();
	a.init();
	b.init();
	long double ans = a.man_dist(b);
	if (l.a == 0 || l.b == 0) {
		cout << fixed << ans << endl;
		return 0;
	}
	l.find_near_p(a);
	l.find_near_p(b);
	for (int i = 0; i < good.size(); i++) {
		for (int j = 0; j < good.size(); j++) {
			ans = min(ans, a.man_dist(good[i]) + good[i].dist(good[j]) + good[j].man_dist(b));
		}
	}
	cout << fixed << ans << endl;
	return 0;
}