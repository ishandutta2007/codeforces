#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);
	int n, t, r;
	std::cin >> n >> t >> r;
	std::vector<int> field(t + 350, 0);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int pos;
		std::cin >> pos;
		pos += t;
		int got = 0;
		for(int j = 0; j < t; j++) {
			got += field[pos - j - 1];
		}
		for(int j = 0; j < t && got < r; j++) {
			if(field[pos - j - 1] == 0) {
				field[pos - j - 1] = 1;
				got++;
				ans++;
			}
		}
		if(got < r) {
			std::cout << "-1\n";
			return 0;
		}
	}
	std::cout << ans << std::endl;
}