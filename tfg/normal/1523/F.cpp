#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int dist(std::pair<int, int> a, std::pair<int, int> b) { return std::abs(a.first - b.first) + std::abs(a.second - b.second); }

const int me = 14;
const int ms = 103;

// maskDP[mask][number of things gotten] = min time to get to this state
int distDP[1 << me][ms+me];
int maskDP[1 << me][ms];
// posDP[index][mask] = max answer to get to this state
int posDP[ms][1 << me];

struct Event {
	std::pair<int, int> pos;
	int t;
};

int32_t main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> towers(n);
	std::vector<Event> a(m);
	for(int i = 0; i < n; i++) {
		std::cin >> towers[i].first >> towers[i].second;
	}
	for(int i = 0; i < m; i++) {
		std::cin >> a[i].pos.first >> a[i].pos.second >> a[i].t;
	}
	std::sort(a.begin(), a.end(), [](auto v1, auto v2) { return v1.t < v2.t; });
	// initialize
	memset(maskDP, 0x3f, sizeof maskDP);
	memset(posDP, -1, sizeof posDP);
	memset(distDP, 0x3f, sizeof distDP);
	for(int i = 0; i < n; i++) {
		maskDP[1 << i][0] = 0;
	}
	for(int i = 0; i < m; i++) {
		posDP[i][0] = 1;
	}
	for(int mask = 0; mask < (1 << n); mask++) {
		for(int i = 0; i < n; i++) if((1 << i) & mask) {
			for(int j = 0; j < n; j++) {
				distDP[mask][j] = std::min(distDP[mask][j], dist(towers[i], towers[j]));
			}
			for(int j = 0; j < m; j++) {
				distDP[mask][n+j] = std::min(distDP[mask][n+j], dist(towers[i], a[j].pos));
			}
		}
	}
	// calculate
	int ans = 0;
	int lastT = 0;
	for(int i = 0; i < m; i++) {
		int curT = a[i].t;
		// propagate maskDP
		for(int mask = 1; mask < (1 << n); mask++) for(int j = ms-2; j >= 0; j--) {
			maskDP[mask][j] = std::min(maskDP[mask][j], maskDP[mask][j+1]);
		}
		for(int mask = 1; mask < (1 << n); mask++) for(int curAns = 0; curAns <= i; curAns++) {
			assert(maskDP[mask][curAns] <= maskDP[mask][curAns+1]);
			if(lastT <= maskDP[mask][curAns] && maskDP[mask][curAns] < curT) {
				for(int other = 0; other < n; other++) {
					maskDP[mask|(1<<other)][curAns] = std::min(maskDP[mask|(1<<other)][curAns], maskDP[mask][curAns] + distDP[mask][other]);
				}
			}
		}
		// calculate posDP

		// consider coming from before
		for(int j = 0; j < i; j++) if(dist(a[i].pos, a[j].pos) <= curT - a[j].t) for(int mask = 0; mask < (1 << n); mask++) {
			if(posDP[j][mask] > 0) {
				posDP[i][mask] = std::max(posDP[i][mask], posDP[j][mask] + 1);
			}
		}
		// consider coming from tower
		for(int mask = 0; mask < (1 << n); mask++) {
			// having fixed the mask, propagate from maskDP
			for(int j = std::max(0, posDP[i][mask]); j <= i; j++) {
				if(maskDP[mask][j] + distDP[mask][n+i] <= curT) {
					posDP[i][mask] = j+1;
				}
			}
			ans = std::max(ans, posDP[i][mask]);
			// throw into maskDP
			if(posDP[i][mask] > 0) {
				maskDP[mask][posDP[i][mask]] = std::min(maskDP[mask][posDP[i][mask]], curT);
				// consider going directly there
				for(int other = 0; other < n; other++) {
					maskDP[mask|(1 << other)][posDP[i][mask]] = std::min(maskDP[mask|(1 << other)][posDP[i][mask]], curT + dist(a[i].pos, towers[other]));
				}
			}
			//std::cout << "posDP(" << i << ", " << mask << ") = " << posDP[i][mask] << '\n';
		}
		lastT = curT;
	}
	std::cout << ans << '\n';
}