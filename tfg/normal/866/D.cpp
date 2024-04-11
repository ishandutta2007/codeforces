#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	long long ans = 0;
	std::multiset<int> wtf;
	while(n--) {
		int v;
		std::cin >> v;
		wtf.insert(v);
		if(*wtf.begin() < v) {
			ans += v - *wtf.begin();
			//std::cout << "pairing " << v << " with " << *wtf.begin() << "\n";
			wtf.erase(wtf.begin());
			wtf.insert(v);
		}
	}
	std::cout << ans << '\n';
}