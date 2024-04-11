#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long INF = (int) 1e9 + 10;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, y;
	std::cin >> n >> y;
	std::set<int> wtf;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		wtf.insert(a[i]);
	}
	int m;
	std::cin >> m >> y;
	std::vector<int> b(m);
	int ans = 1;
	for(int i = 0; i < m; i++) {
		std::cin >> b[i];
		if(wtf.count(b[i])) {
			ans = 2;
		}
	}
	for(int i = 1; (INF + (1LL << (i - 1)) - 1) / (1LL << (i - 1)) > ans; i++) {
		if(i <= 20) {
			std::vector<int> freq(1 << i, 0);
			for(auto v : a) {
				freq[(v ^ (1 << (i - 1))) % (1 << i)]++;
			}
			for(auto v : b) {
				freq[v % (1 << i)]++;
			}
			for(auto v : freq) {
				ans = std::max(v, ans);
			}
		} else {
			std::map<long long, int> freq;
			for(auto v : a) {
				freq[(v ^ (1LL << (i - 1))) % (1LL << i)]++;
			}
			for(auto v : b) {
				freq[v % (1LL << i)]++;
			}
			for(auto v : freq) {
				ans = std::max(v.second, ans);
			}
		}
	}
	std::cout << ans << std::endl;
}