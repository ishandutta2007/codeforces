#include <iostream>

int main() 
{  
	char curr, c = 0;
	unsigned count = 1;
	while (std::cin >> curr) {
		if (curr == c) {
			if (!count) {
				std::cout << curr;
				count = 2;
			}
		}
		else {
			if (count)
				--count;
			std::cout << curr;
		}
		c = curr;
	}
	return 0;
}