#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Info {
	void build(std::string str) {
		n = (int) str.size();
		a.assign(n + 1, 0);
		bc.assign(n + 1, 0);
		for(int i = 0; i < n; i++) {
			bc[i+1] = bc[i];
			if(str[i] == 'A') {
				a[i+1] = 1 + a[i];
			} else {
				bc[i+1]++;
			}
		}
	}
	int n;
	std::vector<int> a, bc;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string s, t;
	std::cin >> s >> t;
	Info i1, i2;
	i1.build(s);
	i2.build(t);
	int q;
	std::cin >> q;
	while(q--) {
		int l1, r1, l2, r2;
		std::cin >> l1 >> r1 >> l2 >> r2;
		l1--;l2--;
		int bc[2] = {i1.bc[r1] - i1.bc[l1], i2.bc[r2] - i2.bc[l2]};
		int en[2] = {i1.a[r1], i2.a[r2]};
		en[0] = std::min(en[0], r1 - l1);
		en[1] = std::min(en[1], r2 - l2);
		if(bc[0] % 2 != bc[1] % 2 || en[0] < en[1] || bc[0] > bc[1]) {
			std::cout << "0";
			continue;
		}
		bool valid = false;
		if(en[0] == en[1]) {
			if(bc[1] > 0 && bc[0] > 0) {
				valid = true;
			}
			if(bc[1] == 0) {
				valid = true;
			}
		} else {
			if(en[0] % 3 == en[1] % 3) {
				valid = true;
			}
			if(bc[0] < bc[1]) {
				valid = true;
			}
		}
		std::cout << (valid ? '1' : '0');
	}
	std::cout << std::endl;
}