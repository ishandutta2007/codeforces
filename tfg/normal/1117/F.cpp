#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<std::vector<int>> table(k, std::vector<int>(1 << k, 0));
	std::string str;
	std::cin >> str;
	for(int l = 0; l < n; l++) {
		int r = l+1;
		int msk = 0;
		while(r != n && str[l] != str[r]) {
			int o = 1 << (str[r] - 'a');
			if((msk & o) == 0) {
				table[str[l] - 'a'][msk] |= o;
			}
			msk |= o;
			r++;
		}
		if(r < n) {
			table[str[l] - 'a'][msk] |= 1 << (str[r] - 'a');
		}
	}
	std::vector<int> masks(k, 0);
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < k; j++) {
			int v;
			std::cin >> v;
			masks[i] |= v << j;
		}
		//std::cout << "mask " << i << " is " << masks[i] << '\n';
	}
	for(int c = 0; c < k; c++) {
		for(int len = 1; len < (1 << k); len *= 2) {
			for(int i = 0; i < (1 << k); i += 2 * len) {
				for(int j = 0; j < len; j++) {
					table[c][i+j+len] |= table[c][i+j];
				}
			}
		}
		for(int i = 0; i < (1 << k); i++) {
			table[c][i] &= ~i;
			if(i & (1 << c)) {
				table[c][i] = 0;
			}
			//std::cout << "table " << c << ' ' << i << " is " << table[c][i] << '\n';
		}
	}
	std::vector<int> freq(1 << k, 0);
	for(auto c : str) freq[c - 'a']++;
	int ans = n;
	std::vector<bool> dp(1 << k, false);
	dp[0] = true;
	for(int i = 0; i < (1 << k); i++) {
		if(!dp[i]) continue;
		//std::cout << "got to " << i << '\n';
		{
			int sum = 0;
			for(int j = 0; j < k; j++) {
				if((i >> j) % 2 == 0) {
					sum += freq[j];
				}
			}
			//std::cout << "sum is " << sum << '\n';
			ans = std::min(ans, sum);
		}
		for(int j = 0; j < k; j++) {
			if((i >> j) % 2 == 0) {
				// test if can
				bool valid = true;
				for(int x = 0; x < k; x++) {
					valid = valid && (table[x][i|(1<<j)] & masks[x]) == table[x][i|(1<<j)];
					if(!valid) {
						//std::cout << "invalid at " << x << '\n';
					}
				}
				if(valid) {
					dp[i | (1 << j)] = true;
				}
			}
		}
	}
	std::cout << ans << '\n';
}