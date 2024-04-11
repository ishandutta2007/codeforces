#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	typedef long long T;
	T x, y;
	int id;
	PT(T xx = 0, T yy = 0) : x(xx), y(yy){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	//double operator !()        const { return sqrt(x*x+y*y);   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
	bool operator < (const PT &p) const { return x != p.x ? x < p.x : y < p.y; }
};

long long absl(long long x) { return std::max(x, -x); }

long long area(PT a, PT b, PT c) { return absl((c-a) % (b-a)); }

bool col(PT a, PT b, PT c) {
	return (a-b) % (c-b) == 0;
}

bool mid(PT a, PT b, PT c) {
	return (c-b) * (a-b) < 0;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<PT> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}
	std::sort(a.begin(), a.end());
	int ans[3] = {0, 1, 2};
	PT tri[3] = {a[0], a[1], a[2]};
	while(col(tri[0], tri[1], tri[2])) {
		ans[2]++;
		tri[2] = a[ans[2]];
	}
	for(int i = ans[2] + 1; i < n; i++) {
		long long s = area(tri[0], tri[1], tri[2]);
		for(int j = 0; j < 3 && s >= 0; j++) {
			s -= area(tri[j], tri[(j+1)%3], a[i]);
		}
		if(s == 0 && !col(tri[0], tri[1], a[i])) {
			tri[2] = a[i];
			ans[2] = i;
		} else if(s == 0 && !col(tri[0], tri[2], a[i])) {
			tri[1] = a[i];
			ans[1] = i;
		} else if(s == 0 && !col(tri[1], tri[2], a[i])) {
			tri[0] = a[i];
			ans[0] = i;
		}
	}
	std::cout << a[ans[0]].id + 1 << " " << a[ans[1]].id + 1 << " " << a[ans[2]].id + 1 << '\n';
}