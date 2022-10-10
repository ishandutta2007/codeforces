#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	typedef long long T;
	T x, y;
	PT(T _x = 0, T _y = 0) : x(_x), y(_y){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	//PT operator /(double c)    const { return PT(x/c,y/c);     }
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

bool comp(PT a, PT b){
	int hp1 = (a.x < 0 || (a.x==0 && a.y<0));
	int hp2 = (b.x < 0 || (b.x==0 && b.y<0));
	if(hp1 != hp2) return hp1 < hp2;
	long long R = a%b;
	if(R) return R > 0;
	return a*a < b*b;
}

const int ms = 6060;

int choice[3];
long long f[4];
long long go(int on, int lst) {
	if(on == 3) {
		int got = 0;
		for(int i = 0; i < 3; i++) for(int j = i+1; j < 3; j++) {
			if(choice[i] ^ choice[j]) {
				got++;
			}
		}
		if(got % 2 == 0) {
			long long ans = 1;
			for(int l = 0, r = 0; l < 3; l = r) {
				while(r < 3 && choice[r] == choice[l]) r++;
				long long v = f[choice[l]];
				if(r - l == 1) {
					ans *= v;
				} else if(r - l == 2) {
					ans *= v * (v - 1) / 2;
				} else {
					ans *= v * (v - 1) * (v - 2) / 6;
				}
			}
			return ans;
		}
		return 0;
	}
	long long ans = 0;
	choice[on] = lst;
	ans = go(on+1, lst);
	if(lst < 3) {
		ans += go(on, lst+1);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<PT> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		int v1 = (int) a[i].x % 4 / 2, v2 = (int) a[i].y % 4 / 2;
		//std::cout << v1 << ", " << v2 << '\n';
		f[v1 * 2 + v2]++;
	}
	std::cout << go(0, 0) << '\n';
}