#include <iostream>
#include <math.h>

using namespace std;

int r, d;
const long double eps = 1e-9;

class Vect{
public:
	int x;
	int y;
	Vect() {};
	Vect(int x, int y) {
		this->x = x;
		this->y = y;
	}
	long double len() {
		return sqrt(x * x + y * y);
	}
};

class circle{
public:
	Vect c;
	int r;
	circle() {};
	circle(Vect c, int r) {
		this->c = c;
		this->r = r;
	}
};

long double my_abs(long double a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

circle pizza;

bool bad(circle a) {
	 long double dist = a.c.len();
	 if (dist - a.r >= r - d || my_abs(dist - a.r - r + d) < eps) {
		 if (dist + a.r <= r || my_abs(dist + a.r - r) < eps) {
			 return true;
		 }
	 }
	 return false;
}

int main() {
	int xi, yi, ri, n, ans = 0;
	cin >> r >> d;
	pizza = circle(Vect(0, 0), r);
	circle now;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> xi >> yi >> ri;
		now = circle(Vect(xi, yi), ri);
		if (bad(now)) {
			ans++;
			//cout << i << endl;
		}
	}
	cout << ans << endl;
	return 0;
}