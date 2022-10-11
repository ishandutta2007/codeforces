#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	std::sort(a.begin(), a.end());
	if(k == 0) {
		if(a[0] > 1) {
			std::cout << 1 << std::endl;
		} else {
			std::cout << -1 << std::endl;
		}
		return 0;
	}
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && a[l] == a[r]) r++;
		if(r == k) {
			std::cout << a[l] << std::endl;
			return 0;
		}
	}
	std::cout << "-1\n";
}