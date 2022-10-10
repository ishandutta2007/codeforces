#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cstring>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int m;

struct Point {
	int id, pos, s;

	int dist(Point o) {
		int d = int(((long long) pos - o.pos + m) % m);
		return std::min(d, m - d);
	}

	bool operator < (Point o) const {
		return pos != o.pos ? pos < o.pos : s * id < o.s * o.id;
	}
};

const int ms = 800400;
const int me = 21;

int to[me][ms];
int end[ms];
long long cost[me][ms];
long long endCost[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> m >> n;
	std::vector<Point> a;
	for(int i = 0; i < n; i++) {
		Point cur;
		std::cin >> cur.pos;
		cur.id = i+1;
		cur.s = 1;
		a.push_back(cur);
		cur.pos += m;
		a.push_back(cur);
	}
	for(int i = 0; i < n; i++) {
		Point cur;
		std::cin >> cur.pos;
		cur.id = i+1;
		cur.s = -1;
		a.push_back(cur);
		cur.pos += m;
		a.push_back(cur);
	}
	n += n;
	std::sort(a.begin(), a.end());
	//for(auto ha : a) std::cout << ha.id * ha.s << ' ';std::cout << std::endl;
	memset(to, 0x3f, sizeof to);
	memset(end, 0x3f, sizeof end);
	for(int i = 2*n-2; i >= 0; i--) {
		if(a[i].s != a[i+1].s) {
			to[0][i] = i+2;
		} else if(end[i+1] < 2*n) {
			to[0][i] = end[i+1]+1;
			cost[0][i] = endCost[i+1];
		}
		if(to[0][i] <= 2*n) {
			cost[0][i] += a[to[0][i] - 1].pos - a[i].pos;
			end[i] = to[0][i];
			endCost[i] = cost[0][i];
			if(end[i] <= 2*n && a[end[i]].s == a[i].s && end[end[i]] <= 2 * n) {
				endCost[i] += endCost[end[i]];
				end[i] = end[end[i]];
			}
		}
		//std::cout << "(" << 0 << ", " << i << ") got (" << to[0][i] << ", " << cost[0][i] << ") and end " << end[i] << "\n";
	}
	for(int i = 1; i < me; i++) {
		for(int j = 0; j < 2*n; j++) {
			int &on = to[i][j];
			on = j;
			if(on <= 2*n && to[i-1][on] <= 2*n) {
				cost[i][j] += cost[i-1][on];
				on = to[i-1][on];
			} else {
				on = 0x3f3f3f3f;
			}
			if(on <= 2*n && to[i-1][on] <= 2*n) {
				cost[i][j] += cost[i-1][on];
				on = to[i-1][on];
			} else {
				on = 0x3f3f3f3f;
			}
			//std::cout << "(" << i << ", " << j << ") got (" << to[i][j] << ", " << cost[i][j] << ")\n";
		}
	}
	long long ans = 1e18;
	int pos = -1;
	for(int i = 0; i < n; i++) {
		int on = i;
		long long curCost = 0;
		for(int j = me-1; j >= 0; j--) {
			if(to[j][on] <= i + n) {
				curCost += cost[j][on];
				on = to[j][on];
			}
		}
		assert(on == i + n);
		if(curCost < ans || pos == -1) {
			ans = curCost;
			pos = i;
		}
	}
	//std::cout << "ans from pos " << pos << '\n';
	assert(pos != -1);
	std::vector<int> ha;
	n /= 2;
	for(int i = 0; i < 2*n; i++) {
		if(a[pos + i].s == -1) {
			ha.push_back(a[pos+i].id);
		}
	}
	std::vector<int> hmm(n, -1);
	for(int i = 0, j = 0; i < 2*n; i++) {
		if(a[pos + i].s == 1) {
			hmm[a[pos+i].id-1] = ha[j++];
		}
	}
	std::cout << ans << '\n';
	for(int i = 0; i < n; i++) {
		std::cout << hmm[i] << (i+1==n?'\n':' ');
	}
}