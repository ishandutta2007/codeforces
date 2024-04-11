#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	std::vector<int> b(m);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	int ans = 0;
	for(int i = 0, j = 0; i < n && j < m; ) {
		if(a[i] > b[j]) i++;
		else i++, j++, ans++;
	}
	std::cout << ans << std::endl;
}