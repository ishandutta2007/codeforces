#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

bool qry(long long l, long long r) {
	std::cout << l << ' ' << r << std::endl;
	std::string str;
	std::cin >> str;
	return str == "Yes";
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n;
	int k;
	std::cin >> n >> k;
	long long l = 1, r = n;
	while(1) {
		if(r - l > 100) {
			long long mid = (l + r) / 2;
			if(qry(l, mid)) {
				l = l - k;
				r = mid + k;
			} else {
				l = mid + 1 - k;
				r = r + k;
			}
			l = std::max(l, 1LL);
			r = std::min(r, n);
		} else {
			int v = std::uniform_int_distribution<int>(0, (int)(r - l))(rng);
			if(qry(l + v, l + v)) {
				return 0;
			}
			l -= k;
			r += k;
			l = std::max(l, 1LL);
			r = std::min(r, n);
		}
	}
}