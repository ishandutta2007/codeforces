#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Range {
	Range(){}
	Range(long long a, long long b, int wtf) : l(a), r(b), st(wtf) {}
	long long l, r;
	int st;
};

bool solve(std::pair<long long, long long> a) {
	long long e = a.second;
	long long s = a.first;
	if(e % 2 == 1) {
		if(s % 2 == 1) {
			return 0;
		} else {
			return 1;
		}
	} else {
		if(s * 2 > e) {
			return s % 2 ? 1 : 0;
		} else if(s * 4 > e) {
			return 1;
		} else {
			return solve(std::pair<long long, long long>(s, e / 4));
		}
	}
}

std::vector<bool> win, loss;

void solve(const std::vector<std::pair<long long, long long>> &a) {
	int n = (int) a.size();
	win.resize(n);
	loss.resize(n);
	for(int i = 0; i < n; i++) {
		win[i] = solve(a[i]);
		loss[i] = a[i].first * 2 > a[i].second ? true : solve(std::pair<long long, long long>(a[i].first, a[i].second / 2)) > 0;
	}
}
int n;

int memo[100100][2];
int dp(int on, int turn) {
	if(on == n) return turn == 0 ? 2 : 1;
	int &ans = memo[on][turn];
	if(ans != -1) return ans;
	ans = 0;
	if(turn == 0) {
		if(win[on]) {
			ans |= dp(on+1, 1);
		}
		if(loss[on]) {
			ans |= dp(on+1, 0);
		}
	} else {
		if(!win[on]) {
			ans |= dp(on+1, 1);
		}
		if(!loss[on]) {
			ans |= dp(on+1, 0);
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	std::vector<std::pair<long long, long long>> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
	}
	solve(a);
	memset(memo, -1, sizeof memo);
	std::cout << (dp(0, 0) % 2) << ' ' << (dp(0, 0) / 2) << '\n';
}