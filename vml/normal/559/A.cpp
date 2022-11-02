#pragma comment (linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct vt {
	double x;
	double y;

	vt(): x(0), y(0) {

	}

	vt(double x, double y): x(x), y(y) {

	}
};

vt operator +(vt a, vt b) {
	a.x += b.x;
	a.y += b.y;

	return a;
}

vt operator *(vt a, double x) {
	a.x *= x;
	a.y *= x;

	return a;
}

const double pi = acos(-1.0);

vt rotate(vt a, double ang) {
	return vt(a.x * cos(ang) - a.y * sin(ang), a.x * sin(ang) + a.y * cos(ang));
}

double operator *(vt a, vt b) {
	return a.x * b.y - a.y * b.x;
}

const double eps = 1e-4;

int main() {
	vt a = vt(0.0, 0.0);
	vt x = vt(1.0, 0.0);

	vector <vt> v;

	for (int i = 0; i < 6; i++) {
		int d;

		scanf("%d", &d);

		v.push_back(a);

		a = a + x * d;

		x = rotate(x, pi / 3);
	}

	double s = 0;

	for (int i = 0; i < 6; i++) {
		int j = (i + 1) % 6;

		s += v[i] * v[j];
	}

	s = abs(s) / 2;

	double s1 = 1 * 1.0 / 2 * sin(pi / 3);

	printf("%d", (int)(s / s1 + eps));

	return 0;
}