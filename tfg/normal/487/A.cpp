#include <iostream>

int main() {
	int hp[2], atk[2], def[2];
	int cost[3];
	for(int i = 0; i < 2; i++) {
		std::cin >> hp[i] >> atk[i] >> def[i];
	}
	for(int i = 0; i < 3; i++) {
		std::cin >> cost[i];
	}
	int ans = 1e9;
	for(int d = def[0]; d <= std::max(def[0], atk[1]); d++) {
		for(int a = std::max(atk[0], def[1] + 1); a <= 200; a++) {
			int rate = a - def[1];
			int kill = (hp[1] + rate - 1) / rate;
			//std::cout << "with a == " << a << ", can kill in " << kill << std::endl;
			// ceil(hp[0] / rate) < kill
			// rate = ceil(hp[0] / kill)
			// rate = atk[1] - d
			// d = atk[1] - rate
			int orate = std::max(0, atk[1] - d);
			int h = std::max(hp[0], kill * orate + 1);
			int cur_cost = cost[0] * (h - hp[0]) + cost[1] * (a - atk[0]) + cost[2] * (d - def[0]);
			ans = std::min(ans, cur_cost);
			if(kill == 1) break;
		}
	}
	std::cout << ans << std::endl;
}