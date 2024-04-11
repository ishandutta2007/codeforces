#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	int x, y;
	int get() { return std::max(x, y); }
};

long long distt(PT a, PT b) {
	long long dx = a.x - b.x;
	long long dy = a.y - b.y;
	return std::max(dx, -dx) + std::max(dy, -dy);
}

bool operator < (PT a, PT b) {
	if(a.get() != b.get()) return a.get() < b.get();
	else if(a.x != b.x) return a.x < b.x;
	else return a.y > b.y;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<PT> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].x >> a[i].y;
	}
	PT pos[2];
	long long dist[2];
	pos[0] = pos[1] = {0, 0};
	dist[0] = dist[1] = 0;
	std::sort(a.begin(), a.end());
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && a[l].get() == a[r].get()) {
			r++;
		}
		PT nxt[2];
		nxt[0] = a[l];
		nxt[1] = a[r-1];
		long long nxtDist[2];
		long long cte = distt(nxt[0], nxt[1]);
		nxtDist[0] = std::min(dist[0] + distt(pos[0], nxt[1]) + cte, dist[1] + distt(pos[1], nxt[1]) + cte);
		nxtDist[1] = std::min(dist[0] + distt(pos[0], nxt[0]) + cte, dist[1] + distt(pos[1], nxt[0]) + cte);
		for(int i = 0; i < 2; i++) {
			pos[i] = nxt[i];
			dist[i] = nxtDist[i];
		}
	}
	std::cout << std::min(dist[0], dist[1]) << std::endl;
}