#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstdlib>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Op {
	Op() {}
	Op(long long a, char c, long long b) : v1(a), v2(b), ch(c) {}
	long long v1, v2;
	char ch;
	void print() {
		std::cout << v1 << ' ' << ch << ' ' << v2 << '\n';
	}
};

std::vector<Op> ans;
std::set<long long> wtf;
void add(long long v1, long long v2) {
	//std::cout << "adding " << v1 << " + " << v2 << std::endl;
	long long res = v1+v2;
	assert(wtf.count(v1) + wtf.count(v2) == 2);
	if(!wtf.count(res)) {
		wtf.insert(res);
		ans.emplace_back(v1, '+', v2);
		if(res == 1) {
			std::cout << ans.size() << '\n';
			for(auto op : ans) {
				op.print();
			}
			exit(0);
		}
	}
}

void xo(long long v1, long long v2) {
	//std::cout << "xoring " << v1 << " ^ " << v2 << std::endl;
	long long res = v1^v2;
	assert(wtf.count(v1) + wtf.count(v2) == 2);
	if(!wtf.count(res)) {
		wtf.insert(res);
		ans.emplace_back(v1, '^', v2);
		if(res == 1) {
			std::cout << ans.size() << '\n';
			for(auto op : ans) {
				op.print();
			}
			exit(0);
		}
	}
}

long long gcd(long long a, long long b) {
	//std::cout << "gcd between (" << a << ", " << b << ")" << std::endl;
	while(std::min(a, b) > 0) {
		if(a > b) std::swap(a, b);
		long long x = a;
		while((x^b) >= x) {
			add(x, x);
			x += x;
		}
		xo(b, x);
		b ^= x;
	}
	//std::cout << "answer is " << std::max(a, b) << std::endl;
	return std::max(a, b);
}

long long kek(long long a, long long b) {
	//std::cout << "kek of (" << a << ", " << b << ") = ";
	while(std::min(a, b) > 0) {
		if(a > b) std::swap(a, b);
		long long x = a;
		while((x^b) >= x) {
			x += x;
		}
		b ^= x;
	}
	//std::cout << std::max(a, b) << std::endl;
	return std::max(a, b);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long x;
	std::cin >> x;
	wtf.insert(x);
	for(int i = 3; i < 1e6; i += 2) {
		break;
		bool good = false;
		long long j = i;
		for(int k = 0; k <= 21; k++) {
			if(kek(i, j) != i) {
				good = true;
				break;
			}
			j = j * 2 + i;
		}
		assert(good);
	}
	while(x != 1) {
		long long y = x;
		while(kek(x, y) == x) {
			add(y, y);
			add(2*y, x);
			y = 2 * y + x;
			assert(y <= 1e18);
		}
		y = gcd(x, y);
		assert(y < x);
		x = y;
	}
	assert(0);
}