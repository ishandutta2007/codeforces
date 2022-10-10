#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int o = 0, x = 0;
	const int me = 10;
	int to[me][2];
	for(int i = 0; i < me; i++) {
		to[i][0] = 0;
		to[i][1] = 1;
	}
	while(n--) {
		char op;
		int val;
		std::cin >> op >> val;
		if(op == '|') {
			for(int i = 0; i < me; i++) {
				if(val & (1 << i)) {
					to[i][0] = to[i][1] = 1;
				}
			}
		} else if(op == '&') {
			for(int i = 0; i < me; i++) {
				if(val & (1 << i)) {

				} else {
					to[i][0] = to[i][1] = 0;
				}
			}
		} else {
			for(int i = 0; i < me; i++) {
				if(val & (1 << i)) {
					to[i][0] ^= 1;
					to[i][1] ^= 1;
				}
			}
		}
	}
	for(int i = 0; i < me; i++) {
		if(to[i][0] == 0 && to[i][1] == 0) {
			o |= 1 << i;
			x |= 1 << i;
		} else if(to[i][0] == 1 && to[i][1] == 1) {
			o |= 1 << i;
		} else if(to[i][0] == 0 && to[i][1] == 1) {

		} else {
			x |= 1 << i;
		}
	}
	std::cout << "2\n";
	std::cout << "| " << o << std::endl;
	std::cout << "^ " << x << std::endl;
}