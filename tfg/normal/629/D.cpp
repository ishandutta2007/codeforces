#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip>
#include <cmath>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

long long bit[ms];

void upd(int x, long long v) {
	for(; x < ms; x += x & -x) {
		bit[x] = std::max(bit[x], v);
	}
}

long long qry(int x) {
	long long ans = 0;
	for(; x > 0; x -= x & -x) {
		ans = std::max(bit[x], ans);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<long long> coord(n);
	for(int i = 0; i < n; i++) {
		int r, h;
		std::cin >> r >> h;
		long long area = (long long) r * r * h;
		coord[i] = area;
	}
	auto a = coord;
	std::sort(coord.begin(), coord.end());
	//std::reverse(a.begin(), a.end());
	for(int i = 0; i < n; i++) {
		long long area = a[i];
		int id = std::upper_bound(coord.begin(), coord.end(), area) - coord.begin();
		//std::cout << id << std::endl;
		long long got = area + qry(id-1);
		upd(id, got);
	}
	std::cout << std::fixed << std::setprecision(10) << qry(n) * acos(-1) << '\n';
}