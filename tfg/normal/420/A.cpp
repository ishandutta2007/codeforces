#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	auto r = str;
	std::reverse(r.begin(), r.end());
	bool valid = r == str;
	std::set<char> good;
	good.insert('A');
	good.insert('H');
	good.insert('I');
	good.insert('M');
	good.insert('O');
	good.insert('T');
	good.insert('U');
	good.insert('V');
	good.insert('W');
	good.insert('Y');
	good.insert('X');
	for(auto c : str) {
		valid = valid && good.count(c);
	}
	std::cout << (valid ? "YES\n" : "NO\n");
}