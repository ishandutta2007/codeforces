#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	#ifndef _GLIBCXX_DEBUG
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	#endif // _GLIBCXX_DEBUG

    int64_t p, q, n;
    std::cin >> p >> q >> n;
    std::vector<int64_t> contfrac (n);
    for (int64_t& x : contfrac) std::cin >> x;

    if (contfrac.size() >= 2 && contfrac.back() == 1) {
		contfrac.pop_back();
		++contfrac.back();
    }

    std::reverse(contfrac.begin(), contfrac.end());

    while (contfrac.size() > 1) {
		if (q == 0) {
			std::cout << "NO\n";
			return 0;
		}
		int64_t intpart = p / q; p %= q;
		if (intpart != contfrac.back()) {
			std::cout << "NO\n";
			return 0;
		}
		contfrac.pop_back(); std::swap(p, q);
    }
	if (q == 0) {
		std::cout << "NO\n";
		return 0;
	}
    int64_t mod = p % q; p /= q; q = 1;
    if (mod != 0) {
		std::cout << "NO\n";
		return 0;
    }
    std::cout << (p == contfrac[0] ? "YES\n" : "NO\n");
    return 0;
}