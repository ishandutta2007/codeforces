#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Robot {
	int x, r, q;
};

bool operator < (Robot a, Robot b) { return a.q < b.q; }

template <class T>
class FenwickTree {
public:
	void init(int s) {
		this->n = s;
		bit.assign(n + 1, 0);
		tot = 0;
	}

	T qry(int x) {
		x = std::min(x, (int)bit.size() - 1);
		T ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}

	void upd(int x, T v) {
		tot += v;
		for(; x <= n; x += x & -x) {
			bit[x] += v;
		}
	}
	int tot;
private:
	int n;
	std::vector<T> bit;
};

int n;

const int ms = 100100;

int centers[ms];
std::vector<int> rp[2 * ms], lp[2 * ms];
FenwickTree<int> trees[2 * ms][2];

void pre(std::vector<Robot> &robo) {
	for(int i = 0; i < n; i++) {
		centers[i] = robo[i].x;
	}
	std::sort(centers, centers + n);
	for(int i = 0; i < n; i++) {
		int pos = std::lower_bound(centers, centers + n, robo[i].x) - centers;
		rp[pos + n].push_back(robo[i].x + robo[i].r);
		lp[pos + n].push_back(robo[i].x - robo[i].r);
	}
	for(int i = n; i < 2 * n; i++) {
		std::sort(rp[i].begin(), rp[i].end());
		std::sort(lp[i].begin(), lp[i].end());
		trees[i][0].init((int)rp[i].size());
		trees[i][1].init((int)rp[i].size());
	}
	//std::cout << "ended first" << std::endl;
	for(int i = n - 1; i > 0; i--) {
		rp[i].resize(rp[i+i].size() + rp[i+i+1].size());
		std::merge(rp[i+i].begin(), rp[i+i].end(), rp[i+i+1].begin(), rp[i+i+1].end(), rp[i].begin());
		lp[i].resize(lp[i+i].size() + lp[i+i+1].size());
		std::merge(lp[i+i].begin(), lp[i+i].end(), lp[i+i+1].begin(), lp[i+i+1].end(), lp[i].begin());
		trees[i][0].init((int)rp[i].size());
		trees[i][1].init((int)rp[i].size());
	}
}

void add(Robot robo, int v) {
	int x = robo.x;
	x = std::lower_bound(centers, centers + n, x) - centers;
	for(x += n; x > 0; x /= 2) {
		int pos;
		pos = std::upper_bound(rp[x].begin(), rp[x].end(), robo.x + robo.r) - rp[x].begin();
		trees[x][0].upd(pos, v);
		pos = std::upper_bound(lp[x].begin(), lp[x].end(), robo.x - robo.r) - lp[x].begin();
		trees[x][1].upd(pos, v);
	}
}

int qry1(int l, int r) {
	//std::cout << "starting qry1 on [" << l << ", " << r << ")" << std::endl;
	int pos = r;
	l = std::lower_bound(centers, centers + n, l) - centers;
	r = std::lower_bound(centers, centers + n, r) - centers;
	int ans = 0;
	for(l += n, r += n; l < r; l /= 2, r /= 2) {
		//std::cout << "(" << l << ", " << r << ")" << std::endl;
		if(l & 1) {
			int x = std::lower_bound(rp[l].begin(), rp[l].end(), pos) - rp[l].begin();
			ans -= trees[l][0].qry(x);
			ans += trees[l][0].tot;
			l++;
		}
		if(r & 1) {
			r--;
			std::swap(l, r);
			int x = std::lower_bound(rp[l].begin(), rp[l].end(), pos) - rp[l].begin();
			ans -= trees[l][0].qry(x);
			ans += trees[l][0].tot;
			std::swap(l, r);
		}
	}
	return ans;
}

int qry2(int l, int r) {
	int pos = l;
	l = std::lower_bound(centers, centers + n, l) - centers;
	r = std::lower_bound(centers, centers + n, r) - centers;
	int ans = 0;
	for(l += n, r += n; l < r; l /= 2, r /= 2) {
		if(l & 1) {
			int x = std::upper_bound(lp[l].begin(), lp[l].end(), pos) - lp[l].begin();
			ans += trees[l][1].qry(x);
			l++;
		}
		if(r & 1) {
			r--;
			std::swap(l, r);
			int x = std::upper_bound(lp[l].begin(), lp[l].end(), pos) - lp[l].begin();
			ans += trees[l][1].qry(x);
			std::swap(l, r);
		}
	}
	return ans;
}

int solve(Robot robo) {
	return qry1(robo.x - robo.r, robo.x) + qry2(robo.x, robo.x + robo.r + 1);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int k;
	std::cin >> n >> k;
	std::vector<Robot> robo(n);
	for(int i = 0; i < n; i++) {
		std::cin >> robo[i].x >> robo[i].r >> robo[i].q;
	}
	std::sort(robo.begin(), robo.end());
	//std::cout << "starting pre" << std::endl;;
	pre(robo);
	long long ans = 0;
	//std::cout << "starting sweep line" << std::endl;
	for(int l = 0, r = 0; r < n; r++) {
		//std::cout << "adding robot (" << robo[r].x << ", " << robo[r].r << ", " << robo[r].q << ")" << std::endl;
		while(robo[r].q - robo[l].q > k) {
			add(robo[l++], -1);
		}
		ans += solve(robo[r]);
		add(robo[r], 1);
	}
	std::cout << ans << '\n';
}