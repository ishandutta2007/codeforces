#include <iostream>
#include <vector>
#include <string>
#include <set>

int main() {
	int n; std::string base;
	std::cin >> base >> n;
	std::set<std::string> words;
	std::set<char> first, second;
	for (int i = 0; i < n ;++i) {
		std::string word;
		std::cin >> word;
		words.insert(word);
		first.insert(word[0]);
		second.insert(word[1]);
	}
	std::cout << ((words.count(base) || (first.count(base[1]) && second.count(base[0]))) ? "YES\n" : "NO\n");
}