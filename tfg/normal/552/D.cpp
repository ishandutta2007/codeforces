#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	typedef long long T;
	T x, y;
	PT(T xx = 0, T yy = 0) : x(xx), y(yy){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	//double operator !()        const { return sqrt(x*x+y*y);   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
	//PT rotate(double a) const { return PT(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a)); }
	bool operator < (const PT &p) const { return x != p.x ? x < p.x : y < p.y; }
	bool operator == (const PT &p)const { return x == p.x && y == p.y; }
};

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::map<std::pair<PT, long long>, std::set<int>> norms;
	std::vector<PT> a(n);
	long long ans = (long long) n * (n-1) * (n-2) / 6;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].x >> a[i].y;
		for(int j = 0; j < i; j++) {
			PT dir = a[i] - a[j];
			if(dir.x < 0) dir = PT() - dir;
			if(dir.y < 0) dir = PT() - dir;
			long long g = gcd(std::max(dir.x, -dir.x), std::max(dir.y, -dir.y));
			dir.x /= g;
			dir.y /= g;
			norms[{dir, a[i] % dir}].insert(i);
			norms[{dir, a[i] % dir}].insert(j);
		}
	}
	for(auto it : norms) {
		long long s = (long long) it.second.size();
		ans -= (long long) s * (s-1) * (s-2) / 6;
	}
	std::cout << ans << std::endl;
}