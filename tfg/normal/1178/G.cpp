#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;
const int bs = 300;

std::vector<int> edges[ms];
int in[ms], out[ms], tim = 0;
long long val[ms][2];
std::vector<int> path;

void dfs(int on) {
	path.push_back(on);
	in[on] = tim++;
	for(auto to : edges[on]) {
		val[to][0] += val[on][0];
		val[to][1] += val[on][1];
		dfs(to);
	}
	out[on] = tim;
}

typedef long long T;
struct Line {
	T a, b; // y = a * x + b

	Line(T aa = 0, T bb = 0) : a(aa), b(bb) {}

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

	T eval(T x) {
		return a * x + b;
	}
};

bool operator < (Line a, Line b) {
	return a.a > b.a;
}

class CHT {
public:
	void clear() {
		pt = 0;
		pts.clear();
	}
	CHT(){ pt = 0; }
	void addLine(Line cur) {
		//std::cout << "adding " << cur.a << ", " << cur.b << "\n";
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
		if(pts.size() == 0) return -3e18;
		while(pt + 1 < (int) pts.size() && pts[pt].eval(x) > pts[pt+1].eval(x)) {
			pt++;
		}
		return -pts[pt].eval(x);
	}
private:
	std::vector<Line> pts;
	int pt;
};

struct Bucket {
	Line a[bs];
	CHT trick;
	int p[bs];
	int size;
	long long lazy;

	Bucket() {
		lazy = 0;
		size = 0;
	}

	void push_back(Line ha) {
		a[size++] = ha;
	}

	void init() {
		for(int i = 0; i < size; i++) {
			//std::cout << "line number " << i << " is (" << a[i].a << ", " << a[i].b << ")\n";
			p[i] = i;
		}
		std::sort(p, p + size, [&](int v1, int v2) { return a[v1].a > a[v2].a; });
		build();
	}

	void build() {
		trick.clear();
		for(int i = 0; i < size; i++) {
			Line ha = a[p[i]];
			//ha.a = -ha.a;
			//ha.b = -ha.b;
			trick.addLine(ha);
		}
		for(int i = 0; i < size; i++) {
			Line ha = a[p[size-i-1]];
			ha.a = -ha.a;
			ha.b = -ha.b;
			trick.addLine(ha);
		}
	}

	long long qry(int l, int r) {
		//std::cout << "receiving query " << l << ", " << r << "\n";
		if(l == 0 && r == size) {
			return trick.qry(lazy);
		} else {
			long long ans = 0;
			for(int i = l; i < r; i++) {
				long long x = a[i].eval(lazy);
				x = std::max(x, -x);
				ans = std::max(ans, x);
			}
			return ans;
		}
	}

	void upd(int l, int r, long long x) {
		//std::cout << "receiving upd " << l << ", " << r << "\n";
		if(l == 0 && r == size) {
			lazy += x;
		} else {
			for(int i = l; i < r; i++) {
				a[i].b += a[i].a * x;
			}
			build();
		}
	}
};

Bucket buk[ms / bs + 2];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	for(int i = 1; i < n; i++) {
		int p;
		std::cin >> p;
		edges[p-1].push_back(i);
	}
	for(int i = 0; i < n; i++) {
		std::cin >> val[i][0];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> val[i][1];
	}
	dfs(0);
	for(int i = 0; i < n; i++) {
		std::swap(val[i][0], val[i][1]);
		val[i][0] = std::max(val[i][0], -val[i][0]);
	}
	for(int i = 0; i < n; i++) {
		int j = path[i];
		buk[i / bs].push_back(Line(val[j][0], val[j][0] * val[j][1]));
	}
	int buckets = (n-1)/bs+1;
	for(int i = 0; i < buckets; i++) {
		buk[i].init();
	}
	while(q--) {
		int t;
		std::cin >> t;
		if(t == 1) {
			int v, x;
			std::cin >> v >> x;
			v--;
			int l = in[v], r = out[v]-1;
			for(int i = l/bs; i <= r/bs; i++) {
				int cl = std::max(l, i*bs);
				int cr = std::min(r, (i+1)*bs-1);
				int hl = cl - i*bs;
				int hr = cr+1 - i*bs;
				buk[i].upd(hl, hr, x);
			}
		} else {
			int v;
			std::cin >> v;
			v--;
			int l = in[v], r = out[v]-1;
			long long ans = 0;
			for(int i = l/bs; i <= r/bs; i++) {
				int cl = std::max(l, i*bs);
				int cr = std::min(r, (i+1)*bs-1);
				int hl = cl - i*bs;
				int hr = cr+1 - i*bs;
				ans = std::max(ans, buk[i].qry(hl, hr));
			}
			std::cout << ans << '\n';
		}
	}
}