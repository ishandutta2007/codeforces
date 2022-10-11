#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int me = 20;

struct Gauss {
	int table[me];
	int size;

	Gauss() {
		for(int i = 0; i < me; i++) {
			table[i] = 0;
		}
		size = 0;
	}

	bool add(int x) {
		for(int i = me-1; i >= 0; i--) {
			if((x & (1 << i)) == 0) {
				continue;
			}
			if(table[i]) {
				x ^= table[i];
			} else {
				table[i] = x;
				size++;
				return true;
			}
		}
		return false;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<int> curBase;
	std::vector<int> bestBase;
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	Gauss gauss;
	for(auto v : a) {
		int size = 0;
		while((1 << size) <= v) {
			size++;
		}
		if(gauss.add(v)) {
			curBase.push_back(v);
		}
		if(size == gauss.size) {
			bestBase = curBase;
		}
	}
	int cur = 0;
	std::cout << bestBase.size() << '\n';
	for(int i = 0; i < (1 << (int) bestBase.size()); i++) {
		if(i) std::cout << ' ';
		int curAns = 0;
		cur ^= i & -i;
		//std::cout << "at " << i << ", got " << cur << std::endl;
		for(int j = 0; j < (int) bestBase.size(); j++) {
			if(cur & (1 << j)) {
				curAns ^= bestBase[j];
			}
		}
		std::cout << curAns;
	}
	std::cout << std::endl;
}