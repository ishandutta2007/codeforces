#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <bitset>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 110;

std::bitset<3 * ms> dp[ms];
std::vector<int> v[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int val;
		std::cin >> val;
		v[val-1].push_back(i);
	}
	dp[0][n + 2] = true;
	for(int i = 0; i < 100; i++) {
		int s = (int) v[i].size();
		if(s != 1) {
			dp[i + 1] |= dp[i];
		}
		if(s != 2 && s != 0) {
			dp[i + 1] |= (dp[i] >> 1) | (dp[i] << 1);
		}
	}
	if(!dp[100][n + 2]) {
		std::cout << "NO\n";
		return 0;
	}
	std::cout << "YES\n";
	std::string ans(n, 'A');
	for(int i = 100, j = n + 2; i > 0;) {
		int s = (int) v[i-1].size();
		if(s == 0) {
			i--;
			continue;
		}
		//std::cout << "on (" << i << ", " << j << ")\n";
		if(s != 1 && dp[i - 1][j]) {
			i--;
			continue;
		}
		if(dp[i-1][j-1]) {
			i--;
			for(int id = 0; id < 1; id++) {
				ans[v[i][id]] = 'B';
			}
			for(int id = 1; id < (int) s; id++) {
				ans[v[i][id]] = 'A';
			}
			j--;
		} else {
			i--;
			for(int id = 0; id < 1; id++) {
				ans[v[i][id]] = 'A';
			}
			for(int id = 1; id < (int) s; id++) {
				ans[v[i][id]] = 'B';
			}
			j++;
		}
	}
	std::cout << ans << std::endl;
}