#include <iostream>
#include <vector>
#include <queue>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::priority_queue<long long> hp;
	int n;
	std::cin >> n;
	while(n--) {
		int t;
		std::cin >> t;
		hp.push(t);
	}
	long long ans = 0;
	while(hp.size() > 1) {
		long long cur = hp.top();
		hp.pop();
		cur += hp.top();
		hp.pop();
		hp.push(cur);
		ans += cur;
	}
	ans += hp.top();
	std::cout << ans << std::endl;
}