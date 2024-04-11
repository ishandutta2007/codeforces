#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	typedef long long T;
	T x, y;
	PT(T x = 0, T y = 0) : x(x), y(y){}
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
	PT d1, d2;
	int n;
	std::cin >> n;
	{
	char trash;
	std::cin >> d1.y >> trash >> d1.x;
	std::cin >> d2.y >> trash >> d2.x;
	}
	std::vector<std::pair<long long, long long>> a;
	// d1 % (o - cur) > 0
	// d1 % o > d1 % cur
	// (o - cur) % d2 > 0
	for(int i = 0; i < n; i++) {
		PT cur;
		std::cin >> cur.x >> cur.y;
		a.emplace_back(d1 % cur, cur % d2);
		if(a.back().first <= 0 || a.back().second <= 0) {
			a.pop_back();
			n--;
			i--;
		}
		//std::cout << a.back().first << ' ' << a.back().second << '\n';
	}
	std::sort(a.begin(), a.end());
	std::vector<int> where(n);
	std::vector<long long> lis;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && a[r].first == a[l].first) r++;
		for(int i = l; i < r; i++) {
			where[i] = std::lower_bound(lis.begin(), lis.end(), a[i].second) - lis.begin();
		}
		for(int i = l; i < r; i++) {
			if(where[i] >= (int) lis.size()) {
				lis.push_back(a[i].second);
			} else {
				lis[where[i]] = std::min(lis[where[i]], a[i].second);
			}
		}
	}
	std::cout << lis.size() << std::endl;
}