#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

#define int long long

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int A[4];
	std::cin >> A[0] >> A[1] >> A[2] >> A[3];
	std::sort(A, A + 4);
	do {
		int c = A[3] - A[0];
		int a = A[1] - c;
		int b = A[2] - c;
		if(a + b == A[0] && a + c == A[1] && b + c == A[2] && a + b + c == A[3]) {
			std::cout << a << ' ' << b << ' ' << c << '\n';
			return 0;
		}
	} while(std::next_permutation(A, A + 4));
}