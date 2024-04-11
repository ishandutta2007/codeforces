#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long sum(int A, int B, int id) {
	return (long long) A * id + (long long) id * (id - 1) / 2 * B;
}
bool solve(int l, int r, int A, int B, int m, int t) {
	long long freq = sum(A, B, r) - sum(A, B, l - 1);
	//std::cout << "(" << m << ", " << t << "), for [" << l << ", " << r << "] got freq " << freq << std::endl;
	if((long long) m * t < freq || t < A + (long long) B * (r - 1)) {
		return false;
	} else {
		return true;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int A, B, q;
	std::cin >> A >> B >> q;
	while(q--) {
		int l, t, m;
		std::cin >> l >> t >> m;
		if(!solve(l, l, A, B, m, t)) {
			std::cout << "-1\n";
			continue;
		}
		int r = l + t;
		int ori = l;
		while(l != r) {
			int mid = (l + r + 1) / 2;
			if(solve(ori, mid, A, B, m, t)) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		std::cout << l << '\n';
	}
}