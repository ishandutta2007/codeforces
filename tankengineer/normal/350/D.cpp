#include <climits>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;

	Point (int x = 0, int y = 0) : x(x), y(y) {}

	void in() {
		scanf("%d%d", &x, &y);
		x *= 2, y *= 2;
	}

	Point delta() {
		int g = __gcd(abs(x), abs(y));
		x /= g, y /= g;
		if (x < 0 || x == 0 && y < 0) {
			x *= -1, y *= -1;
		}
		return *this;
	}

	Point dis1(Point d) {
		if (d.x == 0) {
			return Point(x, 0);
		} else {
			int k = x / d.x;
			return Point(x - k * d.x, y - k * d.y);
		}
	}

	int dis2(Point d) {
		if (d.x == 0) {
			return y;
		} else {
			return x / d.x;
		}
	}

	int len2() {
		return x * x + y * y;
	}

	Point rotate() {
		return Point(y, -x);
	}
};

bool operator < (const Point &a, const Point &b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool operator != (const Point &a, const Point &b) {
	return a.x != b.x || a.y != b.y;
}

bool operator == (const Point &a, const Point &b) {
	return a.x == b.x && a.y == b.y;
}
Point operator - (const Point &a, const Point &b) {
	return Point(a.x - b.x, a.y - b.y);
}

Point operator + (const Point &a, const Point &b) {
	return Point(a.x + b.x, a.y + b.y);
}

Point operator / (const Point &a, const int k) {
	return Point(a.x / k, a.y / k);
}

struct Event {
	Point d, o;
	int pos, evt;

	Event(Point d, Point o, int pos, int evt) : d(d), o(o), pos(pos), evt(evt) {}
};

vector<Event> e;

bool operator < (const Event &a, const Event &b) {
	if (a.d != b.d) {
		return a.d < b.d;
	}
	if (a.o != b.o) {
		return a.o < b.o;
	}
	return a.pos < b.pos  || a.pos == b.pos && a.evt > b.evt;
}

bool same (const Event &a, const Event &b) {
	return a.d == b.d && a.o == b.o;
}

int n, m;

const int N = 1505;
Point c[N]; 
int r[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		Point a, b;
		a.in(), b.in();
		Point d = (b - a).delta();
		if (a.dis2(d) > b.dis2(d)) {
			swap(a, b);
		}
		e.push_back(Event(d, a.dis1(d), a.dis2(d), 1));
		e.push_back(Event(d, b.dis1(d), b.dis2(d), -1));
	}
	for (int i = 0; i < m; ++i) {
		c[i].in(), scanf("%d", r + i);
		r[i] *= 2;
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < i; ++j) {
			if (r[i] == r[j] && (c[i] - c[j]).len2() > r[i] * r[i] * 4) {
				Point mid = (c[i] + c[j]) / 2,
					  d = (c[i] - c[j]).rotate().delta();
				e.push_back(Event(d, mid.dis1(d), mid.dis2(d), 0));
			}
		}
	}
	long long ans = 0;
	sort(e.begin(), e.end());
	for (int i = 0; i < (int)e.size(); ++i) {
		int j = i, cnt = 0;
		while (i < (int)e.size() && same(e[i], e[j])) {
//cout << e[i].d.x << ' ' << e[i].d.y << ' ' << e[i].o.x << ' ' << e[i].o.y << ' ' << e[i].pos << ' ' << e[i].evt << endl;
			int evt = e[i].evt;
			if (evt == 0) {
				ans += cnt;
			} else {
				cnt += evt;
			}
			++i;
		}
		--i;
	}
	cout << ans << endl;
	return 0;
}