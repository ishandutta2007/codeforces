#include <iostream>
#include <vector>

int main() {
	#ifndef _GLIBCXX_DEBUG
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	#endif // _GLIBCXX_DEBUG

	int nSheet, nRound, maxValue;
	std::cin >> nSheet >> nRound >> maxValue;

	std::vector<int> numbers (nSheet, -1);
	int ptrL = 0, ptrR = nSheet - 1;
	int min = -1, max = maxValue + 1;
	while (true) {
		int num; std::cin >> num;
		if (min <= num && num <= max) {
			if (num * 2 <= maxValue) {
				std::cout << 1+ptrL << std::endl;
				numbers[ptrL++] = num;
				min = num;
			} else {
				std::cout << 1+ptrR << std::endl;
				numbers[ptrR--] = num;
				max = num;
			}
			if (ptrL > ptrR) return 0; // we won :)
		} else if (num < min) {
			int ptr = ptrL - 1;
			while (ptr != -1 && numbers[ptr] > num) --ptr;
			numbers[++ptr] = num;
			std::cout << ptr+1 << std::endl;

			min = numbers[ptrL-1];
		} else { // num > max
			int ptr = ptrR + 1;
			while (ptr != nSheet && numbers[ptr] < num) ++ptr;
			numbers[--ptr] = num;
			std::cout << ptr+1 << std::endl;

			max = numbers[ptrR+1];
		}
	}
}