#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstdlib>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 330;

int n, t;
std::vector<int> prv;
std::vector<std::pair<int, int>> qries;
int ans[ms];
int a[ms];

int qry(int l, int r) {
	assert((n - l + 1) % 2 != r % 2);
	std::cout << "? " << l << ' ' << r << std::endl;
	/*if(1) {
		if(rng() % 2) {
			for(int i = l; i <= n; i++) {
				ans[i] ^= 1;
			}
		} else {
			for(int i = 1; i <= r; i++) {
				ans[i] ^= 1;
			}
		}
		t = 0;
		for(int i = 1; i <= n; i++) {
			t += ans[i];
		}
		for(int i = 1; i <= n; i++) {
			std::cout << ans[i];
		}
		std::cout << std::endl;
		std::cout << t << '\n';
	} else*/ {
		std::cin >> t;
	}
	assert(t != -1);
	bool left = r % 2 != (prv.back() + t) % 2;
	prv.push_back(t);
	if(left) {
		//std::cout << "recognizing left\n";
		qries.emplace_back(l, n);
		for(int i = l; i <= n; i++) {
			if(a[i] != -1) {
				a[i] ^= 1;
			}
		}
	} else {
		//std::cout << "recognizing right\n";
		qries.emplace_back(1, r);
		for(int i = 1; i <= r; i++) {
			if(a[i] != -1) {
				a[i] ^= 1;
			}
		}
	}
	return t;
}

void solve(int s) {
	a[1] = s;
	for(int i = 2; i <= n; i++) {
		a[i] = -1;
	}
	for(int i = 2; i <= n; i++) {
		while(1) {
			qry(i - 1, i);
			if(qries.back().first == 1 && qries.back().second == i) {
				break;
			}
		}
		int x = (int) prv.size();
		int diff = prv[x-1] - prv[x-2];
		//std::cout << "for position " << i << " got diff " << diff << "\n";
		for(int j = 1; j < i; j++) {
			if(a[j] == 0) {
				diff++;
			} else {
				diff--;
			}
		}
		//std::cout << "for position " << i << " got diff " << diff << "\n";
		if(diff == -1) {
			a[i] = 0;
		} else if(diff == 1) {
			a[i] = 1;
		} else {
			//std::cout << "returning on first\n";
			return;
		}
	}
	for(auto r : qries) {
		for(int i = r.first; i <= r.second; i++) {
			a[i] ^= 1;
		}
	}
	std::cout << "! ";
	for(int i = 1; i <= n; i++) {
		std::cout << a[i];
	}
	std::cout << std::endl;
	exit(0);
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> t;
	for(int i = 1; i <= n; i++) {
		ans[i] = rng() % 2;
		a[i] = -1;
	}
	//ans[3] = ans[4] = 1;
	if(0) {
		t = 0;
		for(int i = 1; i <= n; i++) {
			t += ans[i];
			std::cout << ans[i];
		}
		std::cout << std::endl;
	}
	prv.push_back(t);
	if(n == 1) {
		std::cout << "! " << t << std::endl;
		return 0;
	}
	if(n % 2 == 1) {
		while(1) {
			qry(2, n);
			if(qries.back().first == 2 && qries.back().second == n) {
				break;
			}
		}
		int x = (int) prv.size();
		int diff = prv[x-1] - prv[x-2];
		int zero = 0;
		//std::cout << "diff is " << diff << "\n";
		while(zero - (n - 1) + zero != diff) {
			zero++;
		}
		int one = n - 1 - zero;
		//std::cout << "got (" << zero << ", " << one << ")\n";
		a[1] = prv[x-2] - one;
		assert(a[1] == 0 || a[1] == 1);
		solve(a[1]);
		assert(0);
	}
	for(int i = 1; i <= n; i++) {
		while(1) {
			qry(i, i);
			if(qries.back().first == 1 && qries.back().second == i) {
				break;
			}
		}
		int x = (int) prv.size();
		int diff = prv[x-1] - prv[x-2];
		//std::cout << "for position " << i << " got diff " << diff << "\n";
		for(int j = 1; j < i; j++) {
			if(a[j] == 0) {
				diff++;
			} else {
				diff--;
			}
		}
		//std::cout << "for position " << i << " got diff " << diff << "\n";
		if(diff == -1) {
			a[i] = 0;
		} else {
			assert(diff == 1);
			a[i] = 1;
		}
	}
	for(auto r : qries) {
		for(int i = r.first; i <= r.second; i++) {
			a[i] ^= 1;
		}
	}
	std::cout << "! ";
	for(int i = 1; i <= n; i++) {
		std::cout << a[i];
	}
	std::cout << std::endl;
}