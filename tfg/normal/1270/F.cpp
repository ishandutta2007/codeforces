#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int bs = 100;
long long solve(const std::string &str, int x, std::vector<int> &sum) {
	int n = (int) str.size();
	sum.resize(n+1);
	sum[0] = 0;
	for(int i = 0; i < n; i++) {
		sum[i+1] = sum[i] + 1 - (str[i] == '1' ? x : 0);
	}
	std::sort(sum.begin(), sum.end());
	long long ans = 0;
	for(int l = 0, r = 0; l <= n; l = r) {
		while(r <= n && sum[l] == sum[r]) r++;
		ans += (r - l) * (r - l - 1LL) / 2;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	if(0){
		while(str.size() < 1000) {
			str += "1110001010110";
		}
	}
	long long ans = 0;
	std::vector<int> sum((int) str.size() + 1);
	for(int i = 1; i < bs; i++) {
		//std::cout << "solving for " << i << '\n';
		ans += solve(str, i, sum);
	}
	// solve for ratio >= bs
	int n = (int) str.size();
	std::vector<int> nxt(n, n);
	for(int i = n-2; i >= 0; i--) {
		if(str[i+1] == '1') {
			nxt[i] = i+1;
		} else {
			nxt[i] = nxt[i+1];
		}
	}
	for(int i = 0; i < n; i++) {
		int j = str[i] == '1' ? i : nxt[i];
		int got = 1;
		while(j < n && n / got >= bs) {
			//std::cout << "testing [" << i << ", " << j+1 << ")\n";
			int k = nxt[j];
			/*if((j - i + 1) % got == 0) {
				ans++;
			}*/
			// can get values of j in [j, k-1]
			// can get values of j-i in [j-i, k-i-1]
			// can get values of j-i+1 in [j-i+1, k-i]
			int r = (k-i)/got;
			int l = std::max((j-i)/got, bs-1);
			ans += std::max(r-l, 0);
			j = nxt[j];
			got++;
		}
	}
	std::cout << ans << '\n';
}