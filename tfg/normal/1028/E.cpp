#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> b(n);
	int mx = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
		if(b[i] >= b[mx] && b[i] > b[i == 0 ? n - 1 : i - 1]) {
			mx = i;
		}
	}
	bool valid = false;
	for(int i = 0; i < n; i++) {
		valid = valid || b[i] != b[mx];
	}
	if(!valid) {
		if(b[0] == 0) {
			std::cout << "YES\n";
			for(int i = 0; i < n; i++) {
				std::cout << 1 << (i + 1 == n ? '\n' : ' ');
			}
			return 0;
		}
		std::cout << "NO\n";
		return 0;
	}
	std::vector<long long> a(n);
	a[mx] = b[mx];
	long long sum = 2LL * b[mx];
	for(int i = (mx + n - 1) % n; i != mx; i = (i + n - 1) % n) {
		sum += b[i];
		a[i] = sum;
	}
	std::cout << "YES\n";
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
}