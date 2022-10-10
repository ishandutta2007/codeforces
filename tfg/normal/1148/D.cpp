#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Stuff {
	int val, id;
	bool operator < (const Stuff &o) const { return val < o.val; }
};

const int ms = 300300;

int to[ms], memo[ms];

int dp(int x) {
	if(x == -1) return 0;
	int &ans = memo[x];
	if(ans != -1) return ans;
	else return ans = 1 + dp(to[x]);
}

void solve(std::vector<Stuff> a) {
	std::sort(a.begin(), a.end());
	std::vector<Stuff> lis;
	for(auto s : a) {
		int id = std::lower_bound(lis.begin(), lis.end(), s) - lis.begin();
		if(id == (int) lis.size()) {
			lis.push_back(s);
		}
		lis[id] = s;
		if(id == 0) {
			to[s.id] = -1;
		} else {
			to[s.id] = lis[id-1].id;
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<Stuff> s1, s2;
	for(int i = 0; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		Stuff s;
		s.id = i;
		if(u < v) {
			s.val = -v;
			s1.push_back(s);
		} else {
			s.val = v;
			s2.push_back(s);
		}
	}
	solve(s1);
	solve(s2);
	memset(memo, -1, sizeof memo);
	int ans = 0;
	for(int i = 1; i < n; i++) {
		if(dp(i) > dp(ans)) {
			ans = i;
		}
	}
	std::vector<int> wtf;
	while(ans != -1) {
		wtf.push_back(ans);
		ans = to[ans];
	}
	std::cout << wtf.size() << '\n';
	std::reverse(wtf.begin(), wtf.end());
	for(int i = 0; i < (int) wtf.size(); i++) {
		std::cout << wtf[i] + 1 << (i + 1 == (int) wtf.size() ? '\n' : ' ');
	}
}