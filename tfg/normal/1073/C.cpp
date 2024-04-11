#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int n;
std::string str;
int x[ms], y[ms];
int toX, toY;

bool check(int m) {
	for(int i = 0; i + m <= n; i++) {
		int posX = x[n] - (x[i + m] - x[i]);
		int posY = y[n] - (y[i + m] - y[i]);
		int dist = abs(posX - toX) + abs(posY - toY);
		if(dist <= m) {
			return true;
		}
	}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> str;
	for(int i = 0; i < n; i++) {
		x[i+1] = x[i];
		y[i+1] = y[i];
		if(str[i] == 'U') {
			y[i+1]++;
		} else if(str[i] == 'D') {
			y[i+1]--;
		} else if(str[i] == 'R') {
			x[i+1]++;
		} else {
			x[i+1]--;
		}
	}
	std::cin >> toX >> toY;
	if(toX == x[n] && toY == y[n]) {
		std::cout << "0\n";
		return 0;
	}
	if((abs(toX) + abs(toY)) % 2 != n % 2 || (abs(toX) + abs(toY)) > n) {
		std::cout << "-1\n";
		return 0;
	}
	if(!check(n)) {
		std::cout << "-1\n";
		return 0;
	}
	int l = 1, r = n;
	while(l != r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l << '\n';
}