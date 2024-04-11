#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int> > wtf;
	int xr = 0;
	for(int i = 0; i < n; i++) {
		int got;
		std::cin >> got;
		std::vector<int> hmm(1, 1);
		for(int j = 1; j < m; j++) {
			int x;
			std::cin >> x;
			if(x != got && hmm.size() == 1) {
				hmm.push_back(j+1);
			}
		}
		wtf.push_back(hmm);
		xr ^= got;
	}
	if(xr == 0) {
		for(int i = 0; i < n; i++) {
			if(wtf[i].size() == 2) {
				std::swap(wtf[i][0], wtf[i][1]);
				xr = 1;
				break;
			}
		}
	}
	if(xr == 0) {
		std::cout << "NIE\n";
	} else {
		std::cout << "TAK\n";
		for(int i = 0; i < n; i++) {
			std::cout << wtf[i][0] << (i + 1 == n ? '\n' : ' ');
		}
	}
}