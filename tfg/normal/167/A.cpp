#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

typedef long double ld;

int main() {
	int n, a, d;
	std::cin >> n >> a >> d;
	ld nxt = 0;
	std::cout << std::fixed << std::setprecision(20);
	while(n--) {
		int t, v;
		//std::cin >> t >> v;
		scanf("%d %d", &t, &v);
		// s = a * t * t / 2
		ld dt = (ld) v / a;
		ld delta = (ld) a * dt * dt / 2.0;
		if(delta >= d) {
			nxt = std::max(nxt, (ld)t + sqrt(2.0 * (ld) d / a));
		} else {
			delta = d - delta;
			dt += delta / v;
			nxt = std::max(nxt, t + dt);
		}
		printf("%.20f\n", (double)nxt);
	}
}