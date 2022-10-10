#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>

const int ms = 100100;

int n;
bool know[ms];
int val[ms];

int qry(int x) {
	x = x % n;
	if(know[x]) {
		return val[x];
	}
	std::cout << "? " << x + 1 << std::endl;
	std::cin >> val[x];
	know[x] = true;
	if(know[(x + n / 2) % n] && val[x] == val[(x + n / 2) % n]) {
		std::cout << "! " << x + 1 << std::endl;
		exit(0);
	}
	return val[x];
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	if(n / 2 % 2 == 1) {
		std::cout << "! -1" << std::endl;
		return 0;
	}
	qry(0);
	qry(n / 2);
	int l = 0, r = n / 2;
	while(r - l > 2) {
		int mid = (l + r) / 2;
		if((qry(l+n/2) - qry(l) > 0) != (qry(mid+n/2) - qry(mid) > 0)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	for(int i = l; i <= r; i++) {
		qry(i);
		qry(i + n / 2);
	}
	std::cout << "! -1" << std::endl;
	assert(0);
}