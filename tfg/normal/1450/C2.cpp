#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::string> mat(n);
	for(int i = 0; i < n; i++) {
		std::cin >> mat[i];
	}
	int freq[3][2] = {{0, 0}, {0, 0}, {0, 0}};
	int k = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(mat[i][j] == 'O') {
				freq[(i+j)%3][0]++;
				k++;
			} else if(mat[i][j] == 'X') {
				freq[(i+j)%3][1]++;
				k++;
			}
		}
	}
	//std::cout << k/3 << std::endl;
	for(int rep = 0; rep < 2; rep++) {
		for(int s = 0; s < 3; s++) for(int wtf = 0; wtf < 3; wtf++) if(wtf != s) {
			int cost = 0;
			for(int i = 0; i < 3; i++) {
				if(i == wtf) continue;
				int want = i == s ? rep : 1-rep;
				cost += freq[i][1-want];
			}
			//std::cout << "at (" << rep << ", " << s << ") got " << cost << std::endl;
			if(cost <= k / 3) {
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < n; j++) {
						if(mat[i][j] != '.' && (i+j)%3 != wtf) {
							int want = (i+j)%3 == s ? rep : 1-rep;
							int cur = mat[i][j] == 'O' ? 0 : 1;
							if(want != cur) {
								mat[i][j] ^= 'O' ^ 'X';
								cost--;
							}
						}
						std::cout << mat[i][j];
					}
					std::cout << '\n';
				}
				assert(cost == 0);
				return;
			}
		}
	}
	assert(0);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}