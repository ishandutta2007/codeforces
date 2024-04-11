#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include <iostream>
#include <vector>
#include <algorithm>

// #ifdef _GLIBCXX_DEBUG
// #define cin cin__
// #include <sstream>
// namespace std{std::stringstream cin{R"(

// 1 2 3
// 4 5 6
// 7 8 9

// )"};}
// #endif

int main() {
	#ifndef _GLIBCXX_DEBUG
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	#endif

	int nnode; std::cin >> nnode;
	std::vector<std::vector<int>> adjlist (nnode);
	for (int i = 1; i < nnode; ++i) { // loop nnode - 1 times
		int pi; std::cin >> pi; --pi;
		adjlist[pi].push_back(i);
	}
	for (int i = 0; i < nnode; ++i) {
		if (adjlist[i].empty()) continue;
		int count = 0;
		for (int a : adjlist[i]) {
			if (adjlist[a].empty()) ++count;
		}
		if (count < 3) {
			std::cout << "No\n";
			return 0;
		}
	}
	std::cout << "Yes\n";
}