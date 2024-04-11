#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

/*struct Fraction {
	long long p, q;

	Fraction(long long a = 0, long long b = 1) {
		if(b < 0) {
			b = -b;
			a = -a;
		}
		p = a, q = b;
		fix();
	}

	void fix() {
		long long g = gcd(std::max(a, -a), b);
		a /= g;
		b /= g;
	}
};

struct PT {
	Fraction x, y;
	PT(Fraction a = Fraction(), Fraction b = Fraction()) {
		x = a, y = b;
	}
};*/

struct Segment {
	long long A, B, C;
	int id;
	void read() {
		std::cin >> A >> B >> C;
		C = -C;
	}

	bool para(Segment o) {
		return A * o.B - B * o.A == 0;
	}

	Segment inter(Segment o) {
		long long D = A * o.B - B * o.A;
		long long X = C * o.B - B * o.C;
		long long Y = A * o.C - C * o.A;
		Segment cur;
		cur.A = X;
		cur.B = Y;
		cur.C = D;
		return cur;
	}

	bool hasPoint(Segment pt) {
		return A * pt.A + B * pt.B == C * pt.C;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	int k;
	std::cin >> n >> k;
	std::vector<Segment> segs(n);
	for(int i = 0; i < n; i++) {
		segs[i].read();
		segs[i].id = i + 1;
	}
	std::vector<std::pair<int, int>> ans;
	while(n > 0 && k > 0) {
		k--;
		int val = 1;
		std::pair<int, int> got(1, -1);
		for(int rep = 0; rep < 100 && n > 1; rep++) {
			int i, j;
			do {
				i = rng() % n;
				j = rng() % n;
			} while(i == j);
			if(segs[i].para(segs[j])) {
				continue;
			}
			int cnt = 0;
			auto inter = segs[i].inter(segs[j]);
			for(int id = 0; id < n; id++) {
				if(segs[id].hasPoint(inter)) {
					cnt++;
				}
			}
			if(cnt > val) {
				val = cnt;
				got = std::pair<int, int>(i+1, j+1);
			}
		}
		std::pair<int, int> real(segs[got.first-1].id, got.second == -1 ? -1 : segs[got.second-1].id);
		ans.push_back(real);
		if(got.second == -1) {
			std::vector<Segment> nxt(segs.begin() + 1, segs.end());
			nxt.swap(segs);
		} else {
			std::vector<Segment> nxt;
			auto inter = segs[got.first-1].inter(segs[got.second-1]);
			for(int id = 0; id < n; id++) {
				if(!segs[id].hasPoint(inter)) {
					//std::cout << "reinserting " << segs[id].id << '\n';
					nxt.push_back(segs[id]);
				}
			}
			nxt.swap(segs);
		}
		n = (int) segs.size();
	}
	if(n == 0) {
		std::cout << "YES\n";
		std::cout << ans.size() << '\n';
		for(auto p : ans) {
			std::cout << p.first << ' ' << p.second << '\n';
		}
	} else {
		std::cout << "NO\n";
	}
}