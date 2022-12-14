#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include <iostream>

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
	
	int n, m;
	std::cin >> n >> m;
	
	if (n > 30) n = 30;
	std::cout << m % (1 << n) << '\n';
}