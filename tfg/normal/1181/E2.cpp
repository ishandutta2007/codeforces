#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Area {
	int x[2];
	int y[2];
	int id;
};

struct Comp1 {
	bool operator()(Area a1, Area a2) {
		return a1.x[0] != a2.x[0] ? a1.x[0] < a2.x[0] : a1.id < a2.id;
	}
};

struct Comp12 {
	bool operator()(Area a1, Area a2) {
		return a1.x[1] != a2.x[1] ? a1.x[1] > a2.x[1] : a1.id < a2.id;
	}
};

struct Comp2 {
	bool operator()(Area a1, Area a2) {
		return a1.y[0] != a2.y[0] ? a1.y[0] < a2.y[0] : a1.id < a2.id;
	}
};

struct Comp22 {
	bool operator()(Area a1, Area a2) {
		return a1.y[1] != a2.y[1] ? a1.y[1] > a2.y[1] : a1.id < a2.id;
	}
};

typedef std::set<Area, Comp1> setx1;
typedef std::set<Area, Comp12> setx2;
typedef std::set<Area, Comp2> sety1;
typedef std::set<Area, Comp22> sety2;

bool solve(setx1 &x1, setx2 &x2, sety1 &y1, sety2 &y2) {
	int n = x1.size();
	if(n == 1) {
		return true;
	}
	auto itxl = x1.begin();
	auto itxr = x2.begin();
	auto ityl = y1.begin();
	auto ityr = y2.begin();
	const int INF = 1e9;
	int xpt[2] = {0, INF};
	int ypt[2] = {0, INF};
	for(int i = 0; i < n; i++) {
		if(i) {
			std::vector<Area> ha;
			if(xpt[0] <= itxl->x[0]) {
				auto it = x1.begin();
				for(int j = 0; j < i; j++) {
					ha.push_back(*it);
					it++;
				}
			} else if(xpt[1] >= itxr->x[1]) {
				auto it = x2.begin();
				for(int j = 0; j < i; j++) {
					ha.push_back(*it);
					it++;
				}
			} else if(ypt[0] <= ityl->y[0]) {
				auto it = y1.begin();
				for(int j = 0; j < i; j++) {
					ha.push_back(*it);
					it++;
				}
			} else if(ypt[1] >= ityr->y[1]) {
				auto it = y2.begin();
				for(int j = 0; j < i; j++) {
					ha.push_back(*it);
					it++;
				}
			}
			if(!ha.empty()) {
				setx1 xx1;
				setx2 xx2;
				sety1 yy1;
				sety2 yy2;
				for(auto cur : ha) {
					xx1.insert(cur);
					xx2.insert(cur);
					yy1.insert(cur);
					yy2.insert(cur);
					x1.erase(cur);
					x2.erase(cur);
					y1.erase(cur);
					y2.erase(cur);
				}
				ha.clear();
				return solve(x1, x2, y1, y2) && solve(xx1, xx2, yy1, yy2);
			}
		}
		xpt[0] = std::max(xpt[0], itxl->x[1]);
		xpt[1] = std::min(xpt[1], itxr->x[0]);
		ypt[0] = std::max(ypt[0], ityl->y[1]);
		ypt[1] = std::min(ypt[1], ityr->y[0]);
		itxl++;
		itxr++;
		ityl++;
		ityr++;
	}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	setx1 x1;
	setx2 x2;
	sety1 y1;
	sety2 y2;
	for(int i = 0; i < n; i++) {
		Area cur;
		cur.id = i;
		std::cin >> cur.x[0] >> cur.y[0] >> cur.x[1] >> cur.y[1];
		x1.insert(cur);
		x2.insert(cur);
		y1.insert(cur);
		y2.insert(cur);
	}
	std::cout << (solve(x1, x2, y1, y2) ? "YES\n" : "NO\n");
}