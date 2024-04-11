#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100;
const int me = 15;

int n;

struct Info {
	int size[100];
	int used;
	void normalize() {
		for(int i = 1; i < n; i++) {
			size[i] = size[i] - size[0];
		}
		size[0] = 0;
	}
	void convert() {
		for(int i = 0; i < n; i++) {
			size[i] = -size[i];
		}
	}

	void print() {
		for(int i = 0; i < n; i++) std::cout << size[i] << ' ';
		std::cout << std::endl;
	}

	bool operator < (const Info &o) const {
		for(int i = 0; i < n; i++) {
			if(size[i] != o.size[i]) return size[i] < o.size[i];
		}
		return false;
	}

	bool operator == (const Info &o) const {
		for(int i = 0; i < n; i++) {
			if(size[i] != o.size[i]) return false;
		}
		return true;
	}
};

int bits[1 << me];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i < (1 << me); i++) {
		bits[i] = bits[i/2] + i%2;
	}
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<Info> b[2];
	for(int rep = 0; rep < 2; rep++) {
		for(int i = 0; i < (1<<me); i++) {
			Info cur;
			for(int j = 0; j < n; j++) {
				cur.size[j] = bits[(rep == 0 ? a[j] % (1 << me) : a[j] >> me) ^ i];
			}
			cur.used = i << (rep * me);
			cur.normalize();
			if(rep == 1) {
				cur.convert();
			}
			//std::cout << "at rep " << rep << " using " << i << " got ";cur.print();
			b[rep].push_back(cur);
		}
		std::sort(b[rep].begin(), b[rep].end());
	}
	for(int i = 0, j = 0; i < (int) b[0].size(); i++) {
		while(j < (int) b[1].size() && b[1][j] < b[0][i]) j++;
		if(j < (int) b[1].size() && b[1][j] == b[0][i]) {
			std::cout << b[1][j].used + b[0][i].used << '\n';
			return 0;
		}
	}
	std::cout << "-1\n";
}