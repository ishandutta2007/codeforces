#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	long long sum = 0;
	std::priority_queue<int> hp;
	while(n--) {
		int x;
		std::cin >> x;
		sum += x;
		hp.push(-x);
		while(sum < 0) {
			sum += hp.top();
			hp.pop();
		}
	}
	std::cout << hp.size() << '\n';
}