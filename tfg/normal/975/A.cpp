#include <iostream>
#include <set>

int main() {
	int n;
	std::cin >> n;
	std::set<int> diffs;
	while(n--) {
		std::string str;
		std::cin >> str;
		int mask = 0;
		for(auto c : str) {
			mask |= 1 << (c - 'a');
		}
		diffs.insert(mask);
	}
	std::cout << diffs.size() << std::endl;
}