#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct ZFunc {
	std::vector<int> z;
	ZFunc(const std::string v) : z(v.size()) {
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
	int n;
	std::cin >> n;
	std::string ans;
	while(n--) {
		std::string cur;
		std::cin >> cur;
		int use = (int) std::min(ans.size(), cur.size());
		ZFunc z(cur + "#" + ans.substr(ans.size() - use, use));
		int mx = 0;
		for(int i = 0; i < use; i++) {
			if(i+z.z[cur.size()+1+i] == use) {
				mx = std::max(mx, z.z[cur.size()+1+i]);
			}
		}
		for(int i = mx; i < (int) cur.size(); i++) {
			ans += cur[i];
		}
	}
	std::cout << ans << '\n';
}