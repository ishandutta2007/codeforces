#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	typedef int T;
	T x, y;
	PT(T xx = 0, T yy = 0) : x(xx), y(yy){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	T operator !()        const { return x*x+y*y;   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
	bool operator < (const PT &p) const { return x != p.x ? x < p.x : y < p.y; }
	bool operator == (const PT &p)const { return x == p.x && y == p.y; }
};


struct Event {
	int i, j, cost;

	bool operator < (Event o) const {
		return cost > o.cost;
	}
};

const int ms = 3030;

PT pts[ms];
std::bitset<ms> to[ms];
Event a[ms*ms/2];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int c = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> pts[i].x >> pts[i].y;
		for(int j = 0; j < i; j++) {
			Event cur;
			cur.i = i;
			cur.j = j;
			cur.cost = !(pts[i]-pts[j]);
			a[c++] = cur;
		}
	}
	std::sort(a, a + c);
	for(int e = 0; e < c; e++) {
		int i = a[e].i, j = a[e].j, cc = a[e].cost;
		if((to[i] & to[j]).count()) {
			std::cout << std::fixed << std::setprecision(10) << sqrt(cc) / 2 << '\n';
			return 0;
		}
		to[i][j] = to[j][i] = true;
	}
	assert(0);
}