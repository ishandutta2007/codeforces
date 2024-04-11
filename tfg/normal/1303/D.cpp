#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		const int ms = 61;
		std::vector<int> freq(ms + 1, 0);
		long long want;
		int n;
		std::cin >> want >> n;
		long long sum = 0;
		while(n--) {
			int x;
			std::cin >> x;
			sum += x;
			int p = 0;
			while(x > 1) {
				x /= 2;
				p++;
			}
			freq[p]++;
		}
		if(sum < want) {
			std::cout << "-1\n";
			continue;
		}
		int ans = 0;
		for(int i = 0; i < ms; i++) {
			if((1LL << i) & want) {
				if(freq[i]) {
					freq[i]--;
				} else {
					int j = i;
					while(!freq[j]) {
						freq[j++]++;
						ans++;
					}
					freq[j]--;
				}
			}
			freq[i+1] += freq[i] / 2;
			freq[i] %= 2;
		}
		std::cout << ans << std::endl;
	}
}