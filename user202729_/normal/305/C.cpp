#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include <cassert>

#include <iostream>
#include <queue>
#include <functional>

int main() {
	#ifndef _GLIBCXX_DEBUG
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	#endif // _GLIBCXX_DEBUG

	int n; std::cin >> n;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	while (n --> 0) {
		int ai; std::cin >> ai;
		pq.push(ai);
	}
	std::vector<int> data;
	while (!pq.empty()) {
		int x = pq.top(); pq.pop();
		if (data.empty() || data.back() < x) {
			data.push_back(x); continue;
		}
		assert(data.back() == x); // cannot be >
		data.pop_back();
		pq.push(x + 1);
	}

	assert(!data.empty());
	std::cout << data.back() + 1 - data.size() << '\n';

	return 0;
}