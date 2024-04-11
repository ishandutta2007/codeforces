#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long double INF = 2e9;
typedef long long T;
struct Line {
	T a, b; // y = a * x + b

	Line(T aa = 0, T bb = 0) : a(aa), b(bb) {}

	Line operator - (Line o) {
		return Line(o.b - b, a - o.a);
	}

	T operator % (Line o) {
		long double brute = (long double) a * o.b - (long double)b * o.a;
		if(brute < -100000000) {
			return -100000000;
		} else if(brute > 100000000) {
			return 10000000;
		} else {
			return a * o.b - b * o.a;
		}
	}

	T eval(T x) {
		return a * x + b;
	}
};

bool operator < (Line a, Line b) {
	return a.a > b.a;
}

class CHT {
public:
	CHT(){}
	CHT(Line a) {
		pts.push_back(a);
	}

	CHT(CHT &a, CHT &b) {
		int sz = a.pts.size() + b.pts.size();
		if(sz == (int) a.pts.size()) {
			pts = a.pts;
			return;
		} else if(sz == (int) b.pts.size()) {
			pts = b.pts;
			return;
		}
		std::vector<Line> buffer(sz);
		std::merge(a.pts.begin(), a.pts.end(), b.pts.begin(), b.pts.end(), buffer.begin());
		for(int i = 0; i < sz; i++) {
			addLine(buffer[i]);
		}
	}

	void addLine(Line cur) {
		cur.a = -cur.a;
		cur.b = -cur.b;
		//std::cout << "adding (" << cur.a << ", " << cur.b << ")" << std::endl;
		if(!pts.empty() && pts.back().a == cur.a) {
			if(pts.back().b > cur.b) {
				pts.pop_back();
			} else {
				return;
			}
		}
		int got = (int) pts.size();
		while(got >= 2 && (pts[got - 2] - pts[got - 1]) % (pts[got - 2] - cur) >= 0) {
			got--;
			pts.pop_back();
		}
		pts.push_back(cur);
	}

	T qry(T x) {
		int l = 0, r = pts.size() - 1;
		while(l != r) {
			int mid = (l + r) / 2;
			if((pts[mid] - pts[mid + 1]) % Line(x, 1) >= 0) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return -pts[l].eval(x);
	}
private:
	std::vector<Line> pts;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	long long s;
	std::cin >> n >> s;
	std::vector<std::pair<int, int>> hmm(n);
	for(int i = 0; i < n; i++) {
		std::cin >> hmm[i].second >> hmm[i].first;
	}
	std::sort(hmm.begin(), hmm.end());
	std::vector<std::pair<int, int>> a;
	for(int i = 0; i < n; i++) {
		if(i == 0) {
			a.push_back(hmm[i]);
			continue;
		}
		if(hmm[i].first == hmm[i-1].first) {
			a.back().second = hmm[i].second;
		} else {
			a.push_back(hmm[i]);
		}
	}
	hmm = a;
	a.clear();
	n = (int) hmm.size();
	for(int i = 0; i < n; i++) {
		if(i == 0 || hmm[i].second > a.back().second) {
			a.push_back(hmm[i]);
		}
	}
	n = (int) a.size();
	CHT hull;
	assert(a[0].first == 0);
	hull.addLine(Line(a[0].second, 0));
	for(int i = 1; i < n; i++) {
		long long l = 0, r = 1;
		while(hull.qry(r) < a[i].first) {
			l = r + 1;
			r += r;
		}
		while(l != r) {
			long long mid = (l + r) / 2;
			if(hull.qry(mid) >= a[i].first) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		//std::cout << "got to (" << a[i].first << ", " << a[i].second << ") at time " << r << "\n";
		hull.addLine(Line(a[i].second, hull.qry(r) - (long long) a[i].second * r - a[i].first));
	}
	long long l = 0, r = 1;
	while(hull.qry(r) < s) {
		l = r + 1;
		r += r;
	}
	while(l != r) {
		long long mid = (l + r) / 2;
		if(hull.qry(mid) >= s) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l << '\n';
}