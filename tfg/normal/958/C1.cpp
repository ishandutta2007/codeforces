#include <iostream>
#include <set>

const int ms = 100100;

long long a[ms], b[ms];

int main() {
	int n, p;
	std::cin >> n >> p;
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		b[i] = (a[i] + b[i - 1]) % p;
	}
	long long ans = 0;
	for(int i = 1; i < n; i++) {
		ans = std::max(ans, b[i] + (b[n] - b[i] + p) % p);
	}
	std::cout << ans << std::endl;
}