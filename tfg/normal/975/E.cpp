#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

typedef double ld;

struct PT {
	ld x, y;

	PT(ld a = 0, ld b = 0) {
		x = a;
		y = b;
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

	ld operator ! () {
		return sqrt(x * x + y * y);
	}

	PT operator * (ld c) {
		return PT(x * c, y * c);
	}

	ld operator * (PT o) {
		return x * o.x + y * o.y;
	}

	ld operator % (PT o) {
		return x * o.y - y * o.x;
	}

	ld operator ^ (PT o) {
		return atan2(*this % o, *this * o);
	}

	PT rotate(ld angle) {
		return PT(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
	}

	void read() {
		//std::cout << "READING!\n";
		std::cin >> x >> y;
		//print();
	}

	void print() {
		//printf("%lf %lf\n", (double)x, (double)y);
		std::cout << x << ' ' << y << '\n';
	}
};

PT pts[100100];
ld dist[100100];
ld wut[100100];

int main() {
	int n, q;
	std::cin >> n >> q;
	std::cout << std::fixed << std::setprecision(10);
	PT cen;
	double mass=0;
	for(int i = 1; i <= n; i++) {
		pts[i].read();
	}
    for(int i = 3; i <= n; i++){
        PT temp = (pts[1]+pts[i-1]+pts[i])/3;
        double tmass=fabs((pts[i-1]-pts[1])%(pts[i]-pts[1]));
        cen = cen * mass + temp * tmass;
        mass += tmass;
        cen = cen / mass;
    }
    PT center = cen;
	PT ori_center = center;
	PT pins[2] = {pts[1], pts[2]};
	int idxs[2] = {1, 2};
	for(int i = 1; i <= n; i++) {
		dist[i] = !(center - pts[i]);
		wut[i] = ((pts[i] - center) ^ PT(0, 1));
	}
	ld angle = 0;
	while(q--) {
		int typ;
		scanf("%d", &typ);
		if(typ == 1) {
			int f, t;
			scanf("%d %d", &f, &t);
			if(idxs[1] == f) {
				std::swap(idxs[1], idxs[0]);
				std::swap(pins[1], pins[0]);
			}
			center = pins[1] - PT(0, dist[idxs[1]]);
			idxs[0] = t;
			angle = wut[idxs[1]];
			pins[0] = center + (pts[t] - ori_center).rotate(angle);
			//pins[1] = center + (pts[idxs[1]] - ori_center).rotate(angle);
		} else {
			int x;
			scanf("%d", &x);
			(center + (pts[x] - ori_center).rotate(angle)).print();
		}
	}
}