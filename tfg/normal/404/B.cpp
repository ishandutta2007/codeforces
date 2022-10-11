#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	double a, d;
	int n;
	std::cin >> a >> d >> n;
	std::cout << std::setprecision(10) << std::fixed;
	for(int i = 1; i <= n; i++) {
		double pos = (double) i * d;
		pos = pos - ((long long)(pos / (4*a))) * (4*a);
		int id = 0;
		while(pos > a) {
			pos -= a;
			id++;
		}
		//std::cout << id << '\n';
		if(id == 0) {
			std::cout << pos << " 0\n";
		} else if(id == 1) {
			std::cout << a << ' ' << pos << '\n';
		} else if(id == 2) {
			std::cout << a - pos << ' ' << a << '\n';
		} else {
			std::cout << 0 << ' ' << a - pos << '\n';
		}
	}
}