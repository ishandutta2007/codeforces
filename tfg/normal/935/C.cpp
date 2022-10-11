#include <iostream>
#include <cmath>
#include <iomanip>

typedef double ld;

struct PT {
	ld x, y;

	void read() {
		std::cin >> x >> y;
	}

	PT (ld x = 0, ld y = 0) {
		this->x = x;
		this->y = y;
	}

	ld operator * (PT o) {
		return x * o.x + y * o.y;
	}

	ld operator ! () {
		return sqrt(*this * *this);
	}

	PT operator + (PT o) {
		return PT(x + o.x, y + o.y);
	}

	PT operator - (PT o) {
		return PT(x - o.x, y - o.y);
	}

	PT operator / (ld c) {
		return PT(x / c, y / c);
	}

	PT operator * (ld c) {
		return PT(x * c, y * c);
	}
};

int main() {
	int R;
	std::cin >> R;
	PT ori;
	ori.read();
	PT fafa;
	fafa.read();
	PT relative = fafa - ori;
	ld dist = !relative;
	ld ans;
	PT pos;
	if(dist >= R) {
		ans = R;
		pos = ori;
	} else {
		ans = (R + dist) / 2;
		if(dist >= 0.5)
			pos = (ori - fafa) / dist;
		else
			pos = PT(1, 0);
		pos = pos * (R - ans);
		pos = pos + ori;
	}
	std::cout << std::fixed << std::setprecision(20) << pos.x << ' ' << pos.y << ' ' << ans << '\n';
}