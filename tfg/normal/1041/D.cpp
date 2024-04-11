#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	long long h;
	std::cin >> n >> h;
	std::vector<long long> sum(n + 1, 0);
	std::vector<long long> start(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		int end;
		std::cin >> start[i] >> end;
		sum[i] = sum[i - 1] + end - start[i];
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		/*if((start[n] - start[i]) - (sum[n - 1] - sum[i - 1]) > 0) {
			ans = std::max(ans, h + (sum[n] - sum[i - 1]));
			//break;
		}*/
		int l = i, r = n;
		while(l != r) {
			int mid = (l + r + 1) / 2;
			if((start[mid] - start[i]) - (sum[mid - 1] - sum[i - 1]) < h) {
				// can get here
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		//std::cout << "from " << i << " got to " << l << std::endl;
		ans = std::max(ans, h + (sum[l] - sum[i - 1]));
	}
	std::cout << ans << std::endl;
}