#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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

	void addLine(Line cur) {
		int got = (int) pts.size();
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
	int pt = 0;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, p;
	std::cin >> m >> n >> p;
	std::vector<int> pos(m, 0);
	for(int i = 1; i < m; i++) {
		std::cin >> pos[i];
		pos[i] += pos[i-1];
	}
	std::vector<int> a(n);
	long long extra = 0;
	for(int i = 0; i < n; i++) {
		int h, t;
		std::cin >> h >> t;
		a[i] = t - pos[h-1];
		/*if(a[i] < 0) {
			extra -= a[i];
			a[i] = 0;
		}*/
	}
	std::sort(a.begin(), a.end());
	std::vector<long long> dp(n + 1, (long long) -1);
	dp[0] = 0;
	while(p--) {
		// make transition
		// nxt[i] = min ((i - j) * a[i-1] - sum[j] + sum[i] + dp[j])
		// nxt[i] = i * a[i-1] + sum[i] + min (-j * a[i-1] - sum[j] + dp[j])
		// lines are (-j, -sum[j] + dp[j])
		CHT trick;
		long long sum = 0;
		for(int i = 0; i <= n; i++) {
			long long x = i == 0 ? 0 : a[i-1];
			sum += x;
			assert(Line(-i, dp[i] + sum).eval(x) + i * x - sum == dp[i]);
			if(dp[i] >= 0) trick.addLine(Line(-i, dp[i] + sum));
			dp[i] = trick.qry(x) + i * x - sum;
			//std::cout << "at " << i << " got " << trick.qry(x) << '\n';
		}
		for(int i = n-1; i >= 0; i--) {
			assert(dp[i] <= dp[i+1]);
			dp[i] = std::min(dp[i], dp[i+1]);
		}
	}
	std::cout << dp.back() + extra << '\n';
}