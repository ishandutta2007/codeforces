#include <iostream>
#include <vector>
#include <set>
#include <utility>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> freq(m, 0);
	std::multiset<int> missing;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		freq[a[i] % m]++;
	}
	for(int i = 0; i < m; i++) {
		freq[i] -= n / m;
		//std::cout << "freq for " << i << " is " << freq[i] << std::endl;
		while(freq[i] < 0) {
			freq[i]++;
			missing.insert(i);
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		if(freq[a[i] % m] > 0) {
			freq[a[i] % m]--;
			auto it = missing.lower_bound(a[i] % m);
			int add = -(a[i] % m);
			if(it == missing.end()) {
				it = missing.begin();
				add = (m - a[i] % m) % m;
			}
			add += *it;
			missing.erase(it);
			a[i] += add;
			ans += add;
		}
	}
	std::cout << ans << std::endl;
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
}