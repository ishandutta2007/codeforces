#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1010;
const int dx[8] = {2, 1, 1, 2, -2, -1, -1, -2};
const int dy[8] = {1, 2, -2, -1, 1, 2, -2, -1};

int n, m;
int x[2], y[2];
int dist[3][ms][ms];
std::pair<int, int> from[3][ms][ms];

void bfs(int x0, int y0, int w) {
	dist[w][x0][y0] = 0;
	std::queue<std::pair<int, int> > q;
	q.push({x0, y0});
	from[w][x0][y0] = {-1, -1};
	//std::cout << "starting bfs from " << w << std::endl;
	while(!q.empty()) {
		auto prv = q.front();
		q.pop();
		int xx = prv.first, yy = prv.second;
		//std::cout << "visiting " << xx << ", " << yy << " dist " << dist[w][xx][yy] << std::endl;
		for(int k = 0; k < 8; k++) {
			int tox = xx + dx[k], toy = yy + dy[k];
			if(tox < 0 || toy < 0 || tox >= n || toy >= m || dist[w][tox][toy] != -1) {
				continue;
			}
			dist[w][tox][toy] = 1 + dist[w][xx][yy];
			from[w][tox][toy] = prv;
			q.push({tox, toy});
		}
	}
	//std::cout << "ending bfs" << std::endl;
}

std::vector< std::pair<int, int> > getPath(int w, int xx, int yy) {
	//std::cout << "starting path " << w << ", " << xx << ", " << yy << std::endl;
	assert(dist[w][xx][yy] != -1);
	std::vector< std::pair<int, int> > ans;
	while(from[w][xx][yy].first != -1) {
		auto wat = from[w][xx][yy];
		ans.emplace_back(xx, yy);
		//std::cout << "(" << xx << ", " << yy << ")" << std::endl;
		xx = wat.first;
		yy = wat.second;
	}
	std::reverse(ans.begin(), ans.end());
	return ans;
}

void WhiteDirect() {
	auto ans = getPath(0, n/2-1, m/2-1);
	std::cout << "WHITE" << std::endl;
	int id = 0;
	bool me = true;
	while(id < (int) ans.size()) {
		if(me) {
			std::cout << ans[id].first + 1 << ' ' << ans[id].second + 1 << std::endl;
			id++;
			if(ans[id].first == n/2-1 && ans[id].second == m/2-1) {
				//return;
			}
		} else {
			int t1, t2;
			std::cin >> t1 >> t2;
		}
		me = !me;
	}
}

void WhiteIndirect() {
	auto ans = getPath(0, n/2, m/2-1);
	std::cout << "WHITE" << std::endl;
	int id = 0;
	bool me = true;
	while(id < (int) ans.size()) {
		if(me) {
			std::cout << ans[id].first + 1 << ' ' << ans[id].second + 1 << std::endl;
			id++;
			if(ans[id].first == n/2-1 && ans[id].second == m/2-1) {
				//return;
			}
		} else {
			int t1, t2;
			std::cin >> t1 >> t2;
		}
		me = !me;
	}
	int xx = x[0], yy = y[0];
	if((int) ans.size() > 0) {
		xx = ans.back().first, yy = ans.back().second;
	}
	bfs(xx, yy, 2);
	ans = getPath(2, n/2-1, m/2-1);
	id = 0;
	while(id < (int) ans.size()) {
		if(me) {
			std::cout << ans[id].first + 1 << ' ' << ans[id].second + 1 << std::endl;
			if(ans[id].first == n/2-1 && ans[id].second == m/2-1) {
				//return;
			}
			id++;
		} else {
			int t1, t2;
			std::cin >> t1 >> t2;
		}
		me = !me;
	}
}

void BlackDirect() {
	auto ans = getPath(1, n/2, m/2-1);
	std::cout << "BLACK" << std::endl;
	int id = 0;
	bool me = false;
	while(id < (int) ans.size()) {
		if(me) {
			std::cout << ans[id].first + 1 << ' ' << ans[id].second + 1 << std::endl;
			if(ans[id].first == n/2 && ans[id].second == m/2-1) {
				//return;
			}
			id++;
		} else {
			int t1, t2;
			std::cin >> t1 >> t2;
		}
		me = !me;
	}
}

void BlackIndirect() {
	auto ans = getPath(1, n/2-1, m/2-1);
	std::cout << "BLACK" << std::endl;
	int id = 0;
	bool me = false;
	while(id < (int) ans.size()) {
		if(me) {
			std::cout << ans[id].first + 1 << ' ' << ans[id].second + 1 << std::endl;
			if(ans[id].first == n/2 && ans[id].second == m/2-1) {
				//return;
			}
			id++;
		} else {
			int t1, t2;
			std::cin >> t1 >> t2;
		}
		me = !me;
	}
	int xx = x[1], yy = y[1];
	if((int) ans.size() > 0) {
		xx = ans.back().first, yy = ans.back().second;
	}
	bfs(xx, yy, 2);
	ans = getPath(2, n/2, m/2-1);
	id = 0;
	while(id < (int) ans.size()) {
		if(me) {
			std::cout << ans[id].first + 1 << ' ' << ans[id].second + 1 << std::endl;
			if(ans[id].first == n/2 && ans[id].second == m/2-1) {
				//return;
			}
			id++;
		} else {
			int t1, t2;
			std::cin >> t1 >> t2;
		}
		me = !me;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> m;
	std::cin >> x[0] >> y[0] >> x[1] >> y[1];
	x[0]--;y[0]--;x[1]--;y[1]--;
	memset(dist, -1, sizeof dist);
	bfs(x[0], y[0], 0);
	bfs(x[1], y[1], 1);
	if((x[0]+y[0]+x[1]+y[1]) % 2 == 1) {
		// white attacks
		if(dist[0][n/2-1][m/2-1] <= dist[1][n/2][m/2-1]) {
			// white direct
			WhiteDirect();
		} else if(dist[0][n/2][m/2-1] <= 1 + dist[1][n/2][m/2-1]) {
			// white indirect
			WhiteIndirect();
		} else {
			// white loses
			// black direct
			BlackDirect();
		}
	} else {
		// black attacks
		if(dist[1][n/2][m/2-1] <= dist[0][n/2-1][m/2-1] - 1) {
			// black direct
			BlackDirect();
		} else if(dist[1][n/2-1][m/2-1] <= dist[0][n/2-1][m/2-1]){
			// black indirect
			BlackIndirect();
		} else {
			// black loses
			// white direct
			WhiteDirect();
		}
	}
}