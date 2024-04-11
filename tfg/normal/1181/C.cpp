#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long solve(const std::vector<int> &vals, const std::string &str) {
	int n = (int) str.size();
	//for(int i = 0; i < n; i++) std::cout << "(" << vals[i] << ", " << str[i] << ") "; std::cout << std::endl;
	long long ans = 0;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && str[r] == str[l]) {
			r++;
		}
		if(l - (r-l) < 0 || r + (r-l) > n) {
			continue;
		}
		int val = 16236321;
		int pos[3] = {l - (r-l), l, l + (r-l)};
		for(int i = 0; i < 3 * (r-l); i++) {
			if(str[pos[0] + i] != str[pos[i/(r-l)]]) {
				val = 0;
			}
			val = std::min(val, vals[pos[0] + i]);
		}
		//std::cout << "at range " << l << ", " << r << " got " << val << '\n';
		ans += val;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> mat(n);
	std::vector< std::vector<int> > dp(n, std::vector<int>(m, 1));
	for(int i = 0; i < n; i++) {
		std::cin >> mat[i];
		for(int j = m-2; j >= 0; j--) {
			if(mat[i][j] == mat[i][j+1]) {
				dp[i][j] += dp[i][j+1];
			}
		}
	}
	long long ans = 0;
	for(int j = 0; j < m; j++) {
		std::string str;
		std::vector<int> ha;
		for(int i = 0; i < n; i++) {
			str += mat[i][j];
			ha.push_back(dp[i][j]);
		}
		ans += solve(ha, str);
	}
	std::cout << ans << '\n';
}