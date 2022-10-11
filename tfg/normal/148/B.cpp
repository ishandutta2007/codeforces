#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int vp, vd, start, fix, dist;
	std::cin >> vp >> vd >> start >> fix >> dist;
	if(vp >= vd) {
		std::cout << "0\n";
		return 0;
	}
	long double cur = start * vp;
	int ans = 0;
	while(1) {
		long double rel = vd - vp;
		long double tim = cur / rel;
		cur += vp * tim;
		if(cur >= dist - 1e-8) {
			break;
		}
		ans++;
		cur += vp * tim;
		cur += vp * fix;
	}
	std::cout << ans << std::endl;
}