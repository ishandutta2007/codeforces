#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cmath>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long f(long long x) { return x * x * x; }
long long g(long long x) {
	long long cur = std::max(0LL, (long long) ((long long) powl((long double)x, 1.0/3) - 2));
	while(f(cur+1) <= x) cur++;
	return cur;
}

struct PT {
	typedef long long T;
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

PT go(long long x) {
	if(x == 0) return PT();
	auto y = g(x);
	if(y == 1) return PT(x, x);
	return  std::max(go(x - f(y)) + PT(1, f(y)), go(f(y) - f(y-1) - 1) + PT(1, f(y-1)));
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n;
	std::cin >> n;
	std::cout << go(n) << '\n';
}