#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::string a, b;
	std::cin >> a >> b;
	int freq[4] = {0, 0, 0, 0};
	for(int i = 0; i < n; i++) {
		int mask = 0;
		mask |= a[i] - '0';
		mask <<= 1;
		mask |= b[i] - '0';
		freq[mask]++;
	}
	long long ans = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = i + 1; j < 4; j++) {
			int ii = (i & 1) | (j & 2);
			int jj = (j & 1) | (i & 2);
			if((std::min(i, ii) == 0 && std::max(i, ii) > 0) || (std::min(j, jj) == 0 && std::max(j, jj) > 0)) {
				ans += (long long) freq[i] * freq[j];
				// std::cout << "swapping " << i << ", " << j << " other is " << ii << ", " << jj << std::endl;
			}
		}
	}
	std::cout << ans << std::endl;
}