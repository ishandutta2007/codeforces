#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include <cassert>

#include <iostream>
#include <vector>
#include <array>
#include <string>

const int N = 5001;

int main() {
	#ifndef _GLIBCXX_DEBUG
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	#endif // _GLIBCXX_DEBUG

	std::array<int, N> g = {0};

	g[0] = 0; // lose
	g[1] = 1;
	g[2] = 1;

	for (int x = 3; x < N; ++x) {
		std::array<bool, N> v = {false};
		v[g[x-2]] = true;
		v[g[x-3]] = true;
		for (int leftslice = 1; leftslice <= (x - 3 - leftslice); ++leftslice) {
			int g1 = g[leftslice] xor g[
				x - 3 - leftslice
			];
			v[g1] = true;
		}
		g[x] = 0;
		while (v[g[x]]) ++g[x];
	}
	// g[x] = grundy_value(std::string(x+2, 'a'));

	std::string st; std::cin >> st;
	st += '?';
	int value = 0, contsize = 0;
	std::vector<std::pair<int, int>> segs;
	for (size_t i = 1; i < st.size() - 1; ++i) {
		if (st[i-1] == st[i+1]) {
			if (contsize == 0) segs.emplace_back(i, 0);
			++contsize;
		} else {
			value ^= g[contsize];
			if (contsize) segs.back().second = contsize;
			contsize = 0;
		}
	}
	assert(contsize == 0);

	if (value != 0) {
		std::cout << "First\n";
	for (auto x : segs) {
		assert(std::cerr << x.first << ' ' << x.second << '\n');

		int difval = value ^ g[x.second];

		if ((difval ^ g[std::max(0, x.second-2)]) == 0) { std::cout << x.first + 1; return 0; }
		if ((difval ^ g[std::max(0, x.second-3)]) == 0) { std::cout << x.first + 2; return 0; }
		for (int leftslice = 1; leftslice <= (x.second - 3 - leftslice); ++leftslice) {
			int g1 = g[leftslice] xor g[
				x.second - 3 - leftslice
			];
			if ((difval ^ g1) == 0) {
				std::cout << x.first + leftslice + 2; return 0;
 			}
		}
	}

	} else {
		std::cout << "Second\n";
	}
}