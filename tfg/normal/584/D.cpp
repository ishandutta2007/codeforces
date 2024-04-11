#include <iostream>
#include <vector>

const int ms = 34000;
const int mw = 1e4;

std::vector<int> primes;
bool np[ms];
bool seg[mw];

int main() {
	int n;
	std::cin >> n;
	int from = std::max(n - mw + 1, 1);
	np[1] = true;
	if(from == 1) {
		seg[0] = true;
	}
	for(int i = 2; i < ms; i++) {
		if(np[i]) {
			continue;
		}
		primes.push_back(i);
		for(int j = i + i; j < ms; j += i) {
			np[j] = true;
		}
	}
	for(auto p : primes) {
		if(p > n) {
			break;
		}
		//std::cout << "from prime " << p << "\n";
		int on = ((from + p - 1) / p) * p;
		on = std::max(on, 2 * p);
		for(int i = on; i <= n; i += p) {
			//std::cout << i << '\n';
			seg[i - from] = true;
		}
	}
	if(seg[n - from] == false) {
		std::cout << "1\n" << n << "\n";
		return 0;
	}
	for(int i = from; i < n; i++) {
		if(seg[i - from]) {
			continue;
		}
		int look = n - i;
		if(look >= 2 && look < ms) {
			if(!np[look]) {
				std::cout << "2\n" << i << " " << look << "\n";
				return 0;
			}
		}
		for(auto p : primes) {
			if(look - p < 2) {
				break;
			}
			if(!np[look - p]) {
				std::cout << "3\n" << i << " " << p << " " << look - p << "\n";
				return 0;
			}
		}
	}
}