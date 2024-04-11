#include <iostream>
#include <vector>
#include <algorithm>

// this CHT is for min!
const int ms = 100100;

const long double INF = 2e9;
typedef long long T;
struct Line {
	T a, b; // y = a * x + b

	Line(T a = 0, T b = 0) : a(a), b(b) {}

	long double inter(Line o) {
		// a * x + b = o.a * x + o.b
		// x = (o.b - b) / (a - o.a)
		return (o.b - b) / (long double) (a - o.a);
	}

	Line operator - (Line o) {
		return Line(o.b - b, a - o.a);
	}

	T operator % (Line o) {
		long double brute = (long double) a * o.b - (long double)b * o.a;
		if(brute < -10) {
			return -10;
		} else if(brute > 10) {
			return 10;
		} else {
			return a * o.b - b * o.a;
		}
	}

	bool under(Line o) {
		return a == o.a && b >= o.b;
	}

	T eval(T x) {
		return a * x + b;
	}
};

bool operator < (Line a, Line b) {
	if(a.a != b.a) return a.a > b.a;
	else return a.under(b);
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

	CHT(std::vector<Line> buffer) {
		std::sort(buffer.begin(), buffer.end());
		for(int i = 0; i < (int) buffer.size(); i++) {
			addLine(buffer[i]);
		}
	}

	void addLine(Line cur) {
		if(!pts.empty() && pts.back().a == cur.a) {
			if(pts.back().b > cur.b) {
				pts.pop_back();
			} else {
				return;
			}
		}
		int got = (int) pts.size();
		/*while(got > 0 && cur.eval(-INF) < pts.back().eval(-INF)) {
			got--;
			pts.pop_back();
		}*/
		while(got >= 2 && (pts[got - 2] - pts[got - 1]) % (pts[got - 2] - cur) >= 0) {
			got--;
			pts.pop_back();
		}
		pts.push_back(cur);
	}

	T qry(T x) {
		if(pts.size() == 0) return 3e18;
		int l = 0, r = pts.size() - 1;
		while(l != r) {
			int mid = (l + r) / 2;
			if((pts[mid] - pts[mid + 1]) % Line(x, 1) >= 0) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return pts[l].eval(x);
	}
private:
	std::vector<Line> pts;
};

template <class Group, class Element, class T = long double>
class Binary_Partition {
public:
	Binary_Partition() {
	}

	void init(int n) {
		this->n = n;
		pt = 0;
		want.assign(2 * n, 1);
		tree.resize(2 * n);
		for(int i = n - 1; i > 0; i--) {
			want[i] = want[i + i] + want[i + i + 1];
		}
	}

	T qry(int l, int r, T pos) {
		T ans = 1e18;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) ans = std::min(ans, tree[l++].qry(pos));
			if(r & 1) ans = std::min(ans, tree[--r].qry(pos));
		}
		return ans;
	}

	void add(Element e) {
		int i = n + pt;
		tree[i] = Group(e);
		for(i /= 2; i > 0; i /= 2) {
			want[i]--;
			if(want[i] == 0) {
				tree[i] = Group(tree[i + i], tree[i + i + 1]);
			}
		}
		pt++;
	}
private:
	int n, pt;
	std::vector<Group> tree;
	std::vector<int> want;
};

int a[ms], b[ms];
long long dp[ms];

int main() {
	int n;
	std::cin >> n;
	Binary_Partition<CHT, Line, T> tree;
	tree.init(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	tree.add(Line(b[0], 0));
	for(int i = 1; i < n; i++) {
		dp[i] = tree.qry(0, i, a[i]) + 0.5;
		tree.add(Line(b[i], dp[i]));
	}
	std::cout << dp[n - 1] << '\n';
}