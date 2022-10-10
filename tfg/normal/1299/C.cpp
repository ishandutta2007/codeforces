#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

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
	bool operator < (const PT &p) const { return x != p.x ? x < p.x : y < p.y; }
	bool operator == (const PT &p)const { return x == p.x && y == p.y; }
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<PT> st;
	for(int i = 0; i < n; i++) {
		PT cur;
		std::cin >> cur.y;
		cur.x = 1;
		while(!st.empty() && st.back() % cur <= 0) {
			cur = cur + st.back();
			st.pop_back();
		}
		st.push_back(cur);
	}
	std::cout << std::fixed << std::setprecision(10);
	for(auto pt : st) {
		std::string val;
		int integerPart = pt.y / pt.x;
		int rest = pt.y % pt.x;
		for(int i = 0; i < 12; i++) {
			rest *= 10;
			val += char(rest / pt.x + '0');
			rest %= pt.x;
		}
		while(pt.x--) {
			std::cout << integerPart << '.' << val << ' ';
		}
	}
	std::cout << std::endl;
}