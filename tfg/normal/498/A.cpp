#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int x1, y1;
	int x2, y2;
	std::cin >> x1 >> y1;
	std::cin >> x2 >> y2;
	int n;
	std::cin >> n;
	int ans = 0;
	while(n--) {
		long long a, b, c;
		std::cin >> a >> b >> c;
		if(a * x1 + b * y1 + c > 0 && a * x2 + b * y2 + c < 0) {
			ans++;
		} else if(a * x1 + b * y1 + c < 0 && a * x2 + b * y2 + c > 0) {
			ans++;
		}
	}
	std::cout << ans << std::endl;
}