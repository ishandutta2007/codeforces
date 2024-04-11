#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
struct ZFunc {
	std::vector<int> z;
	ZFunc(const T &v) : z(v.size()) {
		int n = (int) v.size(), a = 0, b = 0;
		if (!z.empty()) z[0] = n;
		for (int i = 1; i < n; i++) {
			int end = i; if (i < b) end = std::min(i + z[i - a], b);
			while(end < n && v[end] == v[end - i]) ++end;
			z[i] = end - i; if(end > b) a = i, b = end;
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::string str;
	std::cin >> n >> k >> str;
	ZFunc z(str);
	z.z.push_back(0);
	std::vector<int> sum(n+1, 0);
	for(int step = 1; step <= n; step++) {
		for(int j = 0; step * j - 1 < n; j++) {
			if(j >= k) {
				sum[step * j - 1]++;
				sum[std::min(step * j + std::min(z.z[step * j], step), n)]--;
				break;
			}
			if(z.z[step * j] < step) {
				break;
			}
		}
	}
	std::string ans(n, '0');
	for(int i = 0; i < n; i++) {
		if(i) sum[i] += sum[i-1];
		if(sum[i] > 0) ans[i] = '1';
	}
	std::cout << ans << '\n';
}