#include <iostream>

const int ms = 100100;

int c = 0;
int stacks[ms];

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j <= n; j++) {
			bool got = false;
			for(int k = 0; k < c; k++) {
				if(stacks[k] <= i) {
					stacks[k] = j;
					got = true;
					break;
				}
			}
			if(!got) {
				stacks[c++] = j;
			}
		}
	}
	std::cout << c << '\n';
}