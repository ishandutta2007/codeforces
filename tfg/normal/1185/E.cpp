#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 2020;

int n, m;

std::string ans[ms], str[ms];
int memo[2][ms][ms];

int go(int dir, int i, int j) {
	if(dir == 0) {
		if(i >= 0 && ans[i][j] != '.') {
			return memo[dir][i][j] = go(dir, memo[dir][i][j], j);
		} else {
			return i;
		}
	} else {
		if(j >= 0 && ans[i][j] != '.') {
			return memo[dir][i][j] = go(dir, i, memo[dir][i][j]);
		} else {
			return j;
		}
	}
}

void solve() {
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> X(26, std::pair<int, int>(ms, -1));
	auto Y = X;
	for(int i = 0; i < n; i++) {
		std::cin >> str[i];
		for(int j = 0; j < m; j++) {
			memo[0][i][j] = i-1;
			memo[1][i][j] = j-1;
			if(str[i][j] != '.') {
				int x = str[i][j] - 'a';
				X[x].first = std::min(X[x].first, i);
				X[x].second = std::max(X[x].second, i);
				Y[x].first = std::min(Y[x].first, j);
				Y[x].second = std::max(Y[x].second, j);
			}
		}
		ans[i] = std::string(m, '.');
	}
	int last = 25;
	while(last >= 0 && X[last].second == -1) {
		last--;
	}
	int got = last + 1;
	while(last >= 0) {
		if(X[last].second == -1) {
			X[last] = X[last+1];
			Y[last] = Y[last+1];
		}
		if(X[last].first == X[last].second) {
			int l = Y[last].first, r = Y[last].second;
			while(1) {
				r = go(1, X[last].first, r);
				if(r < l) break;
				//std::cout << "(" << l << ", " << r << ")" << std::endl;
				ans[X[last].first][r] = char('a' + last);
			}
		} else {
			int l = X[last].first, r = X[last].second;
			while(1) {
				r = go(0, r, Y[last].first);
				if(r < l) break;
				//std::cout << "(" << l << ", " << r << ")" << std::endl;
				ans[r][Y[last].first] = char('a' + last);
				//break;
			}
		}
		last--;
	}
	bool good = true;
	for(int i = 0; i < n; i++) {
		good = good && str[i] == ans[i];
	}
	if(good) {
		std::cout << "YES\n";
		std::cout << got << '\n';
		for(int i = 0; i < got; i++) {
			std::cout << X[i].first+1 << ' ' << Y[i].first+1 << ' ' << X[i].second+1 << ' ' << Y[i].second+1 << '\n';
		}
	} else {
		std::cout << "NO\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}