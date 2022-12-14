#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include <cassert>

#include <iostream>
#include <vector>

int main() {
	int n; std::cin >> n;
	bool had100 = false;
	int anyother = 0;
	bool had_nonzero_10x = false,
	had_nonzero_singledigit = false;

	std::vector<int> result;

	while (n --> 0) {
		int d; std::cin >> d;
		if (d == 0) {
			result.push_back(0);
			continue;
		}
		if (d == 100 && !had100) {
			had100 = true;
			result.push_back(100);
			continue;
		}
		if (d % 10 == 0 && !had_nonzero_10x) {
			had_nonzero_10x = true;
			result.push_back(d);
			continue;
		}
		if (d < 10 && !had_nonzero_singledigit) {
			had_nonzero_singledigit = true;
			result.push_back(d);
			continue;
		}
		anyother = d;
	}

	if ((!had_nonzero_10x) && (!had_nonzero_singledigit) && (anyother != 0)) {
		result.push_back(anyother);
	}
	std::cout << result.size() <<'\n';
	for (int x:result) std::cout << x << ' ';
	std::cout << '\n';
}