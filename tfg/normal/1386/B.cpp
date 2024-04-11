#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int sign(long long x) {
	if(x > 0) return 1;
	else if(x < 0) return -1;
	else return 0;
}

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
	int safeCross(const PT &p) const {
		long double wtf = (long double) x * p.y - (long double) y * p.x;
		if(std::max(wtf, -wtf) > 1e9) return wtf > 0 ? 1 : -1;
		else return sign(*this % p);
	}
	void simplify() {
		if(x != 0 || y != 0) {
			auto g = gcd(std::max(x, -x), std::max(y, -y));
			x /= g;
			y /= g;
		}
	}
	int h() const {
		if((x > 0 && y == 0) || y > 0) return x > 0 ? 0 : 1;
		else return x < 0 ? 2 : 3;
	}

	bool operator < (const PT &p) const {
		if(h() != p.h()) return h() < p.h();
		long double wtf = (long double) x * p.y - (long double) y * p.x;
		if(std::max(wtf, -wtf) > 1e9) return wtf > 0;
		else return *this % p > 0;
	}

	friend std::ostream& operator << (std::ostream &os, const PT &p) {
		return os << p.x << ' ' << p.y;
	}
	friend std::istream& operator >> (std::istream &is, PT &p) {
		return is >> p.x >> p.y;
	}
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long st[3];
	std::cin >> st[0] >> st[1] >> st[2];
	int special = 0;
	while(st[special] == 0) special++;
	std::swap(st[special], st[0]);
	int q;
	std::cin >> q;
	std::vector<PT> pts;
	long long zeroes = 0, pairs = 0;
	int good = 0;
	std::map<PT, int> freq;
	std::set<PT> radial;
	auto test = [](PT l, PT r) { return l.safeCross(r) >= 0 ? 1 : 0; };
	while(q--) {
		char ch;
		std::cin >> ch;
		if(ch == 'A') {
			long long A, B, C;
			std::cin >> A >> B >> C;
			if(special == 1) {
				std::swap(B, A);
			} else if(special == 2) {
				std::swap(C, A);
			}
			PT pt(B * st[0] - st[1] * A, C * st[0] - st[2] * A);
			pt.simplify();
			//std::cout << "adding " << pt << '\n';
			pts.push_back(pt);
			if(pt.x == 0 && pt.y == 0) {
				zeroes++;
			} else {
				pairs += freq[PT(-pt.x, -pt.y)];
				freq[pt]++;
				if(freq[pt] == 1) {
					// adding in radial
					if(radial.empty()) {
						radial.insert(pt);
					} else {
						auto itr = radial.lower_bound(pt);
						if(itr == radial.begin()) {
							good += test(pt, *itr);
						} else if(itr == radial.end()) {
							itr--;
							good += test(*itr, pt);
						} else {
							auto itl = itr;
							itl--;
							good += test(pt, *itr) + test(*itl, pt) - test(*itl, *itr);
						}
						radial.insert(pt);
					}
				}
			}
		} else {
			int id;
			std::cin >> id;
			id--;
			auto pt = pts[id];
			//std::cout << "removing " << pt << '\n';
			if(pt.x == 0 && pt.y == 0) {
				zeroes--;
			} else {
				pairs -= freq[PT(-pt.x, -pt.y)];
				freq[pt]--;
				if(freq[pt] == 0) {
					// removing in radial
					auto it = radial.lower_bound(pt);
					auto itr = it;
					itr++;
					if(it == radial.begin()) {
						if(itr != radial.end()) good -= test(*it, *itr);
					} else {
						it--;
						if(itr != radial.end()) good += test(*it, *itr) - test(pt, *itr);
						good -= test(*it, pt);
					}
					radial.erase(pt);
				}
			}
		}
		if(zeroes > 0) {
			std::cout << "1\n";
			continue;
		}
		if(pairs > 0) {
			std::cout << "2\n";
			continue;
		}
		if((int) radial.size() <= 2 || good + 1 != (int) radial.size()) {
			std::cout << "0\n";
			continue;
		}
		std::cout << (test(*radial.rbegin(), *radial.begin()) ? "3\n" : "0\n");
	}
}