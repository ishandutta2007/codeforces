#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int last = 0;
	int size = 0;
	int ans = 0;
	while(n--) {
		int nxt;
		std::cin >> nxt;
		if(nxt >= last) {
			last = nxt;
			size++;
			ans = std::max(ans, size);
		} else {
			size = 1;
			last = nxt;
		}
	}
	std::cout << ans << '\n';
}