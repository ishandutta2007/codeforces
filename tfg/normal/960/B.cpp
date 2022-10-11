#include <iostream>
#include <algorithm>

int abss(int x) {return std::max(x, -x);}

int a[100100];

int main() {
	int n, k1, k2;
	std::cin >> n >> k1 >> k2;
	int k = k1 + k2;
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		a[i] = abss(a[i] - t);
	}
	while(k--) {
		int pos = 0;
		for(int i = 1; i < n; i++) {
			if(a[pos] < a[i]) pos = i;
		}
		a[pos] = abss(a[pos] - 1);
	}
	for(int i = 0; i < n; i++) {
		ans += a[i] * (long long) a[i];
	}
	std::cout << ans << '\n';
}