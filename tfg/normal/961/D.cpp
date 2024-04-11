#include <iostream>
#include <vector>
#include <cstdio>

typedef long long ll;

struct PT {
	ll x, y;

	PT(ll a = 0, ll b = 0) {x = a; y = b;}

	ll operator % (PT o) {return x * o.y - y * o.x;}
	PT operator - (PT o) {return PT(x - o.x, y - o.y);}

	void read() {
		scanf("%lld %lld", &x, &y);
	}
};

int n;
PT pts[100100];

bool colinear(PT a, PT b, PT c) {
	return (a - b) % (a - c) == 0;
}

bool can(PT a, PT b) {
	std::vector<PT> rest;
	for(int i = 0; i < n; i++) {
		if(!colinear(a, b, pts[i])) {
			rest.push_back(pts[i]);
		}
	}
	for(int i = 2; i < rest.size(); i++) {
		if(!colinear(rest[0], rest[1], rest[i])) return false;
	}
	return true;
}

int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		pts[i].read();
	}
	std::cout << (can(pts[0], pts[1]) || can(pts[0], pts[2]) || can(pts[1], pts[2]) ? "YES\n" : "NO\n");
}