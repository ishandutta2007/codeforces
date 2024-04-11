#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	modBase<mod> operator * (modBase<mod> o) { return (long long) val * o.val % mod; }
	modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
};

struct Box {
	int i, j;
	int val;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 1010;
	int n, m;
	std::cin >> n >> m;
	std::vector<Box> boxes;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			Box cur;
			cur.i = i+1;
			cur.j = j+1;
			std::cin >> cur.val;
			boxes.push_back(cur);
		}
	}
	std::sort(boxes.begin(), boxes.end(), [](Box a, Box b) { return a.val < b.val; });
	std::vector<modBase<>> dp(n * m);
	modBase<> totTwo(0);
	int wantX, wantY;
	std::cin >> wantX >> wantY;
	modBase<> gotX(0), gotY(0);

	for(int l = 0, r = 0; l < n*m; l = r) {
		while(r < n*m && boxes[l].val == boxes[r].val) {
			r++;
		}
		for(int i = l; i < r; i++) {
			modBase<> x(boxes[i].i), y(boxes[i].j);
			auto two = x * x + y * y;
			dp[i] = totTwo + two * l;
			dp[i] = dp[i] - gotX * x * 2;
			dp[i] = dp[i] - gotY * y * 2;
			if(l) {
				dp[i] = dp[i] / l;
			}
		}
		for(int i = l; i < r; i++) {
			modBase<> x(boxes[i].i), y(boxes[i].j);
			auto two = x * x + y * y;
			gotX = gotX + x;
			gotY = gotY + y;
			totTwo = totTwo + two + dp[i];
		}
	}
	for(int i = 0; i < n*m; i++) {
		if(wantX == boxes[i].i && wantY == boxes[i].j) {
			std::cout << dp[i].val << '\n';
		}
	}
}