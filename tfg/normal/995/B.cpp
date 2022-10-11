#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

const int ms = 202;

int a[ms];
std::vector<int> pos[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < 2 * n; i++) {
		std::cin >> a[i];
		a[i]--;
		pos[a[i]].push_back(i);
	}
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	std::sort(p.begin(), p.end(), [&](int f, int s) {
		return pos[f][0] < pos[s][0];
	});
	std::vector<int> inv(n);
	for(int i = 0; i < n; i++) {
		inv[p[i]] = i;
	}
	int ans = 0;
	for(int i = 0; i < 2 * n; i++) {
		a[i] = inv[a[i]];
	}
	for(int i = 0; i < 2 * n; i++) {
		for(int j = i + 1; j < 2 * n; j++) {
			ans += a[i] > a[j] ? 1 : 0;
		}
	}
	std::cout << ans << std::endl;
}