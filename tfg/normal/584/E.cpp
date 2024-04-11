#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int, int> ii;

int p[2][2020];
int dist[2020];

int main() {
	int n;
	std::cin >> n;
	for(int j = 0; j < 2; j++) {
		for(int i = 1; i <= n; i++) {
			std::cin >> p[j][i];
		}
	}
	long long cost = 0;
	std::vector<ii> ans;
	for(int i = 1; i < n; i++) {
		for(int j = i; j <= n; j++) {
			dist[p[0][j]] = j;
		}
		for(int j = i; j <= n; j++) {
			dist[p[1][j]] -= j; 
		}
		int on = i + dist[p[1][i]];
		/*std::cout << "for " << i << ", " << on << "\n";
		for(int j = 1; j <= n; j++) {
			std::cout << dist[j] << ' ';
		}
		std::cout << '\n';*/
		cost += dist[p[1][i]];
		for(int d = dist[p[1][i]] - 1; d >= 0; d--) {
			//std::cout << "testing swap between " << d + i << " and " << on << ", got " << dist[p[0][d + i]] + d + i << '\n';
			if(on <= -dist[p[0][d + i]] + d + i) {
				std::swap(p[0][on], p[0][d + i]);
				ans.push_back(ii(d + i, on));
				on = d + i;
			}
		}
	}
	std::cout << cost << '\n';
	std::cout << ans.size() << '\n';
	for(auto a : ans) {
		std::cout << a.first << ' ' << a.second << '\n';
	}
}