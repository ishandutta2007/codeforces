#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	int n = (int) str.size();
	std::vector<int> a(n, 0); 
	for(int i = 2; i >= 0; i--) {
		std::string qr;
		for(int j = 0; j < n; j++) {
			int id = j;
			for(int x = 0; x < i; x++) {
				id /= 26;
			}
			id %= 26;
			qr += char('a' + id);
		}
		std::cout << "? " << qr << std::endl;
		std::cin >> qr;
		assert(qr.size() == str.size());
		for(int j = 0; j < n; j++) {
			a[j] = a[j] * 26 + qr[j] - 'a';
		}
	}
	std::vector<int> b(n);
	for(int i = 0; i < n; i++) {
		b[a[i]] = i;
	}
	std::cout << "! ";
	for(int i = 0; i < n; i++) {
		std::cout << str[b[i]];
	}
	std::cout << std::endl;
}