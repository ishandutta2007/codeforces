#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>
#include <queue>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 250500;

std::queue<int> q;
bool got[ms];
long long p[ms], r[ms], dist[ms], mass[ms];

template<class T = long long>
struct FenwickTree {
public:
	FenwickTree(std::vector<T> pts) {
		std::sort(pts.begin(), pts.end());
		pts.resize(std::unique(pts.begin(), pts.end()) - pts.begin());
		ord = pts;
		fw.resize(ord.size() + 1);
	}

	void upd(T x, T y, int v) {
		for(int xx = std::upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx < fw.size(); xx += xx & -xx) {
			fw[xx].push_back({y, v});
		}
	}

	void qry(T x, T y) {
		for(int xx = std::upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx > 0; xx -= xx & -xx) {
			while(!fw[xx].empty() && fw[xx].back().first <= y) {
				int on = fw[xx].back().second;
				fw[xx].pop_back();
				if(!got[on]) {
					got[on] = true;
					q.push(on);
				}
			}
		}
	}
private:
	std::vector<T> ord;
	std::vector<std::vector<std::pair<T, int>>> fw;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long bx, by, n;
	std::cin >> bx >> by >> p[0] >> r[0] >> n;
	r[0] *= r[0];
	int ans = -1;
	q.push(0);
	std::vector<long long> pts;
	for(int i = 1; i <= n; i++) {
		long long x, y;
		std::cin >> x >> y >> mass[i] >> p[i] >> r[i];
		r[i] *= r[i];
		x -= bx; y -= by;
		dist[i] = x * x + y * y;
		pts.push_back(mass[i]);
	}
	FenwickTree<long long> tree(pts);
	std::vector<int> wtf((int) n);
	for(int i = 0; i < n; i++) {
		wtf[i] = i + 1;
	}
	std::sort(wtf.begin(), wtf.end(), [&](int a, int b) { return dist[a] > dist[b]; });
	for(auto i : wtf) {
		tree.upd(mass[i], dist[i], i);
	}
	while(!q.empty()) {
		long long curR = r[q.front()], curP = p[q.front()];
		q.pop();
		ans++;
		tree.qry(curP, curR);
	}
	std::cout << ans << '\n';
}