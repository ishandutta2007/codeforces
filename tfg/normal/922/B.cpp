#include <iostream>

typedef long long ll;

int main() {
	int n;
	std::cin >> n;
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			int k = i ^ j;
			if(k < i + j && k >= j && k <= n) {
				ans++;
			}
		}
	}
	std::cout << ans << '\n';
}