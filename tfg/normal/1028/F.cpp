#include <iostream>
#include <vector>
#include <map>

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct PT {
	int x, y;

	PT(int xx = 0, int yy = 0) : x(xx), y(yy) {}

	PT operator + (PT o) { return PT(x + o.x, y + o.y); }

	PT simplify() {
		int g = gcd(x, y);
		return PT(x / g, y / g);
	}

	void read() {
		std::cin >> x >> y;
	}

	void print() {
		std::cout << "(" << x << ", " << y << ")";
	}

	int dist() { return x * x + y * y; }

	bool operator < (PT o) const { return x == o.x ? y < o.y : x < o.x; }
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::map<PT, int> freq;
	std::map<int, std::vector<PT>> m;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		PT cur;
		cur.read();
		int d = cur.dist();
		//std::cout << "on query " << i << ", " << t << " and (" << cur.x << ", " << cur.y << ")\n";
		if(t == 1) {
			std::vector<PT> &v = m[d];
			for(auto p : v) {
				//std::cout << "got something in "; (cur + p).simplify().print(); std::cout << "\n";
				freq[(cur + p).simplify()] += 2;
			}
			v.push_back(cur);
			freq[cur.simplify()]++;
			cnt++;
		} else if(t == 2) {
			std::vector<PT> &v = m[d];
			int pos = 0;
			while(v[pos].x != cur.x || v[pos].y != cur.y) {
				pos++;
			}
			std::swap(v[pos], v.back());
			v.pop_back();
			freq[cur.simplify()]--;
			for(auto p : v) {
				freq[(cur + p).simplify()] -= 2;
			}
			cnt--;
		} else {
			cur = cur.simplify();
			//std::cout << "query in "; cur.print(); std::cout << std::endl;
			std::cout << cnt - freq[cur] << std::endl;
		}
	}
}