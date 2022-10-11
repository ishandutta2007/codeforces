#include <iostream>
#include <algorithm>
#include <cstdio>

const int bs = 1000;
const int ms = 1001000;

struct PT {
	int x, y;
	int idx;

	PT(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}

	void read() {
		scanf("%i %i", &x, &y);
	}
};

bool operator < (PT a, PT b) {
	if(a.x / bs != b.x / bs) {
		return a.x < b.x;
	} else {
		return a.x / bs % 2 == 0 ? a.y < b.y : a.y > b.y;
	}
}

PT pts[ms];

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		pts[i].read();
		pts[i].idx = i + 1;
	}
	std::sort(pts, pts + n);
	for(int i = 0; i < n; i++) {
		printf("%i%c", pts[i].idx, i + 1 == n ? '\n' : ' ');
	}

}