#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int a[200200][2];
int nxt[200200];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	if(n == 3) {
		std::cout << "1 2 3\n";
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 2; j++) {
			std::cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		int u = a[i][0], v = a[i][1];
		if(a[u][0] == v || a[u][1] == v) {
			nxt[i] = u;
		} else {
			nxt[i] = v;
		}
	}
	for(int i = 1, j = 1; i <= n; i++, j = nxt[j]) {
		std::cout << j << (i == n ? '\n' : ' ');
	}
}