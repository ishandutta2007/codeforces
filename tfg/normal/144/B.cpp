#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());\

struct PT {
	typedef int T;
	T x, y;
	PT(T _x = 0, T _y = 0) : x(_x), y(_y){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	//double operator !()        const { return sqrt(x*x+y*y);   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
	bool operator < (const PT &p) const { return x != p.x ? x < p.x : y < p.y; }
	bool operator == (const PT &p)const { return x == p.x && y == p.y; }

	friend std::ostream& operator << (std::ostream &os, const PT &p) {
		return os << p.x << ' ' << p.y;
	}
	friend std::istream& operator >> (std::istream &is, PT &p) {
		return is >> p.x >> p.y;
	}
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int x[2], y[2];
	std::cin >> x[0] >> y[0] >> x[1] >> y[1];
	if(x[0] > x[1]) std::swap(x[0], x[1]);
	if(y[0] > y[1]) std::swap(y[0], y[1]);
	int n;
	std::cin >> n;
	std::vector<PT> a(n);
	std::vector<int> r(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i] >> r[i];
	}
	auto check = [&](PT pt) {
		for(int i = 0; i < n; i++) {
			PT cur = pt - a[i];
			if(cur * cur <= r[i] * r[i]) return true;
		}
		return false;
	};
	int ans = 0;
	for(int i = x[0]; i <= x[1]; i++) {
		if(!check(PT(i, y[0]))) ans++;
		if(!check(PT(i, y[1]))) ans++;
	}
	for(int i = y[0]+1; i < y[1]; i++) {
		if(!check(PT(x[0], i))) ans++;
		if(!check(PT(x[1], i))) ans++;
	}
	std::cout << ans << '\n';
}