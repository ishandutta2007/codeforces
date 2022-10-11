#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> w(n, 0);
	std::vector<int> f(n, m);
	for(int i = 0; i < n; i++) {
		std::cin >> w[i];
	}
	std::vector<int> book(m, 0);
	for(int i = 0; i < m; i++) {
		int x;
		std::cin >> x;
		x--;
		f[x] = std::min(f[x], i);
		book[i] = x;
	}
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	std::sort(p.begin(), p.end(), [&](int a, int b) {
		return f[a] > f[b];
	});
	long long ans = 0;
	for(int i = 0; i < m; i++) {
		int j = n-1;
		while(p[j] != book[i]) {
			ans += w[p[j--]];
		}
		for(int k = j; k + 1 < n; k++) {
			p[k] = p[k+1];
		}
		p[n-1] = book[i];
	}
	std::cout << ans << '\n';
}