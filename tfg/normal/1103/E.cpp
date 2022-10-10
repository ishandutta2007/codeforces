#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

typedef unsigned long long ll;

const int roots[10] = {1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
const int iroots[10] = {1, 2, 4, 8, 5, 10, 9, 7, 3, 6};

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

struct Number {
	Number(ll x = 0) {
		for(int i = 1; i < 5; i++) {
			v[i] = 0;
		}
		v[0] = x;
	}

	Number operator * (const Number &o) const {
		Number ans(0);
		for(int i = 0; i < 5; i++) {
			if(o.v[i] == 0) continue;
			for(int j = 0; j < 5; j++) {
				if(i+j<5) {
					ans.v[i+j] += o.v[i] * v[j];
				} else {
					ans.v[i+j-5] -= o.v[i] * v[j];
				}
			}
		}
		return ans;
	}

	Number operator + (const Number &o) const {
		Number ans(0);
		for(int i = 0; i < 5; i++) {
			ans.v[i] = v[i] + o.v[i];
		}
		return ans;
	}
	ll v[5];

	void print() {
		std::cout << "(";
		for(int i = 0; i < 5; i++) {
			std::cout << v[i] << (i == 4 ? ')' : ' ');
		}
	}
	ll getVal() {
		//print(); std::cout << std::endl;
		return v[0] - v[4];
		ll x = 0;
		for(int i = 1; i < 5; i++) {
			if(v[i] == v[10-i]) {
				v[i] = v[10-i] = 0;
			}
			if(v[i]) {
				assert(x == 0 || x == v[i]);
				x = v[i];
			}
		}
		print(); std::cout << std::endl;
		return v[0] - v[5] - x;
	}
};

Number f[10];

void FWHT(std::vector<Number> &a, bool inv = false) {
	int n = (int) a.size(), k = 10;
	Number root(0);
	if(inv) {
		root.v[4] = -1;
	} else {
		root.v[1] = 1;
	}
	for(int len = 1; len < n; len *= k) {
		for(int i = 0; i < n; i += k * len) {
			for(int ii = 0; ii < len; ii++) {
				for(int j = 0; j < k; j++) {
					f[j] = a[i + ii + j * len];
				}
				Number in_root(1);
				for(int j = 0; j < k; j++) {
					Number cur_root = 1;
					a[i + ii + j * len] = 0;
					for(int jj = 0; jj < k; jj++) {
						a[i + ii + j * len] = (a[i + ii + j * len] + f[jj] * cur_root);
						cur_root = cur_root * in_root;
					}
					//std::cout << "root for " << j << ": ";in_root.print();std::cout << '\n';
					in_root = in_root * root;
				}
			}
		}
	}
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	/*for(int i = 2; i < 11; i++) {
		int x = 1;
		for(int j = 0; j < 10; j++) {
			std::cout << x << ' ';
			x = x * i % 11;
		}
		std::cout << std::endl;
	}*/
	const int ms = 100000;
	std::vector<Number> a(ms, 0);
	int n;
	std::cin >> n;
	//n = 1;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		a[x].v[0]++;
	}

	/*for(int i = 0; i < ms; i++) {
		a[i].print();
		std::cout << ' ';
	}std::cout << "\n\n";*/
	FWHT(a);
	/*for(int i = 0; i < ms; i++) {
		a[i].print();
		std::cout << ' ';
	}std::cout << "\n\n";
	std::cout << std::endl;*/
	for(auto &i : a) {
		i = fexp(i, n);
	}
	/*for(int i = 0; i < ms; i++) {
		a[i].print();
		std::cout << ' ';
	}std::cout << "\n\n";
	std::cout << std::endl;*/
	FWHT(a, true);
	/*for(int i = 0; i < ms; i++) {
		a[i].print();
		std::cout << ' ';
	}std::cout << "\n\n";
	std::cout << std::endl;*/
	ll r = 57646075230342349LL;

	const int me = 5;
	r = fexp(r, me) % ((1LL) << 58);
	for(int i = 0; i < n; i++) {
		ll x = a[i].getVal();
		//std::cout << "at " << i << " got " << x << '\n';
		x /= 1 << me;
		x *= r;
		x %= 1LL << 58;
		std::cout << x << '\n';
	}
}