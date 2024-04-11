#include <iostream>

int c[30];

int main() {
	int n;
	int l;
	std::cin >> n >> l;
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> c[i];
		if(i) {
			c[i] = std::min(c[i], c[i - 1] * 2);
		}
	}
	long long tot_ans = 1e18;
	for(int i = n - 1; i >= 0; i--) {
		int got = l / (1 << i);
		ans += (long long) got * c[i];
		tot_ans = std::min(tot_ans, ans + c[i]);
		l -= (long long) (1 << i) * got;
	}
	tot_ans = std::min(ans, tot_ans);
	std::cout << tot_ans << '\n';
}