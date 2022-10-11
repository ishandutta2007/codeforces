#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<long long> a(n + 1);
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] += a[i - 1];
	}
	int on = 0;
	while(m--) {
		long long wut;
		std::cin >> wut;
		while(a[on] < wut) {
			on++;
		}
		std::cout << on << ' ' << wut - a[on - 1] << std::endl;
	}
}