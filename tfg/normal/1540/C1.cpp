#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

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
	modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	//void operator /= (modBase<mod> o) { *this = *this / o; }
	modBase<mod> operator * (modBase<mod> o) { return (int)((long long) val * o.val % mod); }
	modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

	friend std::ostream& operator << (std::ostream &os, const modBase<mod> &p) {
		return os << p.val;
	}
	friend std::istream& operator >> (std::istream &is, modBase<mod> &p) {
		return is >> p.val;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> rangeSize(n);
	for(int i = 0; i < n; i++) {
		std::cin >> rangeSize[i];
	}
	std::vector<modBase<>> val(n+1, 1);
	for(int i = n-1; i >= 0; i--) {
		val[i] = val[i+1] * (1 + rangeSize[i]);
	}
	std::vector<int> offset(n, 0);
	for(int i = 1; i < n; i++) {
		std::cin >> offset[i];
		offset[i] += offset[i-1];
	}
	int worstCase = 0;
	for(int i = 0; i < n; i++) {
		worstCase = std::max(worstCase, offset[i]);
	}
	std::map<int, modBase<>> memo;
	std::vector<int> a(n);
	auto qry = [&](int x) {
		x = -x;
		//if(x < 0) return modBase<>(0);
		//x = std::min(x, worstCase);
		if(memo.count(x)) return memo[x];
		//std::cout << "solving for " << x << std::endl;
		std::vector<modBase<>> cur(1, 1);
		for(int i = 0; i < n; i++) {
			a[i] = x - offset[i];
		}
		// use this to check if it dies, if it doesn't just add to answer
		std::vector<int> worst(n+1, 0);
		for(int i = n-1; i >= 0; i--) {
			worst[i] = std::min(worst[i+1] + a[i], 0);
		}
		// use this to check if it can stay alive
		std::vector<int> best(n+1, 0);
		for(int i = n-1; i >= 0; i--) {
			best[i] = std::max(best[i+1], 0) + a[i] + rangeSize[i];
		}
		int curSum = 0;
		modBase<> ans(0);
		for(int i = 0; i < n && !cur.empty(); i++) {
			//std::cout << "for " << i << " starting at " << curSum << '\n';
			std::vector<modBase<>> nxt(cur.size() + rangeSize[i] + 1, 0);
			for(int j = 0; j < (int) cur.size(); j++) {
				nxt[j] += cur[j];
				nxt[j + rangeSize[i] + 1] -= cur[j];
			}
			for(int j = 1; j < (int) nxt.size(); j++) {
				nxt[j] += nxt[j-1];
			}
			while(!nxt.empty() && nxt.back().val == 0) nxt.pop_back();
			int l = 0, r = (int) nxt.size();
			curSum += a[i];
			// check dead stuff
			while(l < r && curSum + l < 0) {
				l++;
			}
			while(l < r && curSum + l + best[i+1] < 0) {
				l++;
			}
			// check alive stuff
			while(r > l && curSum + (r-1) + worst[i+1] >= 0) {
				r--;
				ans += nxt[r] * val[i+1];
			}
			cur.resize(r - l);
			for(int j = l; j < r; j++) {
				cur[j - l] = nxt[j];
			}
			curSum += l;
		}
		//assert(cur.empty());
		for(auto i : cur) ans += i;
		return memo[x] = ans;
	};
	int q;
	std::cin >> q;
	while(q--) {
		int x;
		std::cin >> x;
		std::cout << qry(x) << '\n';
	}
}