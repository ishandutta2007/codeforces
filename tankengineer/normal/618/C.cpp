#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct Point {
	int x, y;

	Point(int x = 0, int y = 0) : x(x), y(y) {}

	void in() {
		scanf("%d%d", &x, &y);
	}

	long long len() {
		return (long long)x * x + (long long)y * y;
	}
};

const int N = 100005;

Point p[N];

long long det(const Point &a, const Point &b) {
	return (long long)a.x * b.y - (long long)a.y * b.x;
}

int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		p[i].in();
	}
	int mins = 1;
	for (int i = 1; i < n; ++i) {
		p[i].x -= p[0].x;
		p[i].y -= p[0].y;
		if (p[i].len() < p[mins].len()) {
			mins = i;
		}
	}
	long long area = (1ll << 63) - 1;
	int mins2 = -1;
	for (int i = 1; i < n; ++i) {
		long long tmp = llabs(det(p[i], p[mins]));
		if (tmp > 0 && tmp < area) {
			mins2 = i;
			area = tmp;
		}
	}
	printf("%d %d %d\n", 1, mins + 1, mins2 + 1);
	return 0;
}