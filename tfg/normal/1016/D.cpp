#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 31;

std::vector<std::vector<int>> solve(std::vector<int> rows, std::vector<int> cols) {
	int n = (int) rows.size();
	int m = (int) cols.size();
	std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));
	int pos = -1;
	for(int i = 0; i < m; i++) {
		if(cols[i]) {
			pos = i;
		}
	}
	if(pos == -1) {
		bool valid = true;
		for(int i = 0; i < n; i++) {
			if(rows[i]) {
				ans[i][0] = 1;
				valid = !valid;
			}
		}
		if(!valid) {
			ans.clear();
		}
		return ans;
	}
	bool fst = false;
	for(int i = 0; i < n; i++) {
		if(rows[i]) {
			ans[i][pos] = 1;
			fst = !fst;
		}
	}
	if(fst) {
		cols[pos] = false;
	}
	pos = -1;
	for(int i = 0; i < m; i++) {
		if(cols[i]) {
			if(pos == -1) {
				pos = i;
			} else {
				ans[0][pos] ^= 1;
				ans[0][i] ^= 1;
				pos = -1;
			}
		}
	}
	if(pos != -1) {
		ans.clear();
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	std::vector<int> b(m);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));
	for(int it = 0; it < ms; it++) {
		std::vector<int> r1(n);
		std::vector<int> r2(m);
		for(int i = 0; i < n; i++) {
			r1[i] = a[i] & 1;
			a[i] >>= 1;
		}
		for(int i = 0; i < m; i++) {
			r2[i] = b[i] & 1;
			b[i] >>= 1;
		}
		auto tmp = solve(r1, r2);
		if(tmp.size() == 0) {
			std::cout << "NO\n";
			return 0;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				ans[i][j] |= tmp[i][j] << it;
			}
		}
	}
	std::cout << "YES\n";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cout << ans[i][j] << (j + 1 == m ? '\n' : ' ');
		}
	}
}