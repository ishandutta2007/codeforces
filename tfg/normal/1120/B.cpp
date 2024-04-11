#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int n;
std::string s, t;
int a[ms], b[ms];
int pos[ms], neg[ms];

std::vector<std::pair<int, int>> ans;

bool canPos(int x) {
	return pos[x] && s[x] <= '8' && s[x+1] <= '8';
}

bool canNeg(int x) {
	return neg[x] && s[x] >= '1' + (x==0?1:0) && s[x+1] >= '1';
}

void dfs(int on) {
	if(on < 0 || on+2 > n || ans.size() >= 100000) return;
	if(canPos(on)) {
		s[on]++;
		s[on+1]++;
		pos[on]--;
		ans.emplace_back(on+1, 1);
		dfs(on-1);
		dfs(on);
		dfs(on+1);
	} else if(canNeg(on)) {
		s[on]--;
		s[on+1]--;
		neg[on]--;
		ans.emplace_back(on+1, -1);
		dfs(on-1);
		dfs(on);
		dfs(on+1);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	std::cin >> s >> t;
	for(int i = 0; i < n; i++) {
		if(i) {
			a[i] = -a[i-1];
			b[i] = -b[i-1];
		}
		a[i] += s[i]-'0';
		b[i] += t[i]-'0';
	}
	long long got = 0;
	for(int i = 0; i+2 <= n; i++) {
		if(a[i] < b[i]) {
			pos[i] = b[i] - a[i];
			got += b[i] - a[i];
		} else {
			neg[i] = a[i] - b[i];
			got += a[i] - b[i];
		}
	}
	if(a[n-1] != b[n-1]) {
		std::cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < n; i++) {
		dfs(i);
	}
	std::cout << got << '\n';
	for(auto v : ans) {
		std::cout << v.first << ' ' << v.second << '\n';
	}
}