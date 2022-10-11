#include <iostream>
#include <map>
#include <vector>

int main() {
	std::map<int, int> freq;
	std::vector<int> v;
	for(int i = 0; i < 6; i++) {
		int t;
		std::cin >> t;
		freq[t]++;
	}
	for(auto a : freq) {
		v.push_back(a.second);
	}
	if(freq.size() == 1) {
		std::cout << "Elephant\n";
	} else if(freq.size() == 2) {
		if(std::max(v[0], v[1]) == 5) {
			std::cout << "Bear\n";
		} else if(std::max(v[0], v[1]) == 4) {
			std::cout << "Elephant\n";
		} else {
			std::cout << "Alien\n";
		}
	} else if(freq.size() == 3) {
		if(v[0] == 4 || v[1] == 4 || v[2] == 4) {
			std::cout << "Bear\n";
		} else {
			std::cout << "Alien\n";
		}
	} else {
		std::cout << "Alien\n";
	}
}