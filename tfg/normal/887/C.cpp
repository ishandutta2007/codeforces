#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdlib>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int a[] = {1, 5, 9, 22, 3, 7, 11, 24};
int b[] = {13, 5, 17, 21, 14, 6, 18, 22};
int c[] = {3, 14, 9, 19, 4, 16, 10, 17};

int p[55];

void go(int d[]) {
	for(int r = 0; r < 8; r++) {
		int v = p[d[7]];
		for(int i = 6; i >= 0; i--) {
			p[d[i+1]] = p[d[i]];
		}
		p[d[0]] = v;
		for(int i = 1; i<=25; i++) {
			if(i == 25 && (r == 0 || r == 2)) {
				std::cout << "YES\n";
				exit(0);
			}
			if(p[i] != p[(i-1)/4*4+1]) break;
		}
		//for(int i=1;i<=24;i++)std::cout << p[i];
		//std::cout << std::endl;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n = 24;
	for(int i=1; i<=n; i++) std::cin >> p[i];
	go(a);go(b);go(c);
	std::cout << "NO\n";
}