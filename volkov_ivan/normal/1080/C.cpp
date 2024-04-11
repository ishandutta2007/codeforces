#include <iostream>

using namespace std;

struct rect{
	long long x1, y1, x2, y2;
	rect() {}
	rect(long long x1, long long y1, long long x2, long long y2) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
	void init() {
		cin >> x1 >> y1 >> x2 >> y2;
	}
	long long sz() {
		return (x2 - x1 + 1) * (y2 - y1 + 1);
	}
};

rect intersec(rect a, rect b) {
	rect c(max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2));
	return c;
}

long long get_black(rect a) {
	long long ans = a.sz() / 2; 
	if ((a.x1 + a.y1) % 2 == 1) ans = a.sz() - ans;
	return ans;
}

long long get_white(rect a) {
	return (a.sz() - get_black(a));
}

int main() {
	//freopen("Desktop/inp.in", "r", stdin);
	int q;
	rect a, black, white;
	long long n, m;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n >> m;
		a = rect(1, 1, n, m);
		white.init();
		black.init();
		long long ans = get_black(a);
		ans -= get_black(white);
		ans += get_white(black);
		rect both = intersec(black, white);
		if (both.x1 <= both.x2 && both.y1 <= both.y2) {
			ans += get_black(both);
		}
		cout << a.sz() - ans << ' ' << ans << '\n';
	}
	return 0;
}