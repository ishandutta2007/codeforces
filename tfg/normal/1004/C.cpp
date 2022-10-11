#include <iostream>
#include <vector>

const int ms = 100100;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> sum(n + 1, 0);
	std::vector<bool> got(ms, false);
	for(int i = 1; i <= n; i++) {
		if(!got[a[i]]) {
			got[a[i]] = true;
			sum[i]++;
		}
		sum[i] += sum[i - 1];
	}
	got.assign(ms, false);
	long long ans = 0;
	for(int i = n; i > 0; i--) {
		if(!got[a[i]]) {
			ans += sum[i - 1];
			got[a[i]] = true;
		}
	}
	std::cout << ans << std::endl;
}