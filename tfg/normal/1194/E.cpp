#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
class FenwickTree {
public:
	void init(std::vector<int> wtf) {
		coord = wtf;
		std::sort(coord.begin(), coord.end());
		coord.resize(std::unique(coord.begin(), coord.end()) - coord.begin());
		n = (int) coord.size();
		bit.assign(n + 1, 0);
	}

	T qry(int x) {
		x = std::upper_bound(coord.begin(), coord.end(), x) - coord.begin();
		T ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}

	void upd(int x, T v) {
		x = std::upper_bound(coord.begin(), coord.end(), x) - coord.begin();
		for(; x <= n; x += x & -x) {
			bit[x] += v;
		}
	}

	void reset() {
		bit.assign(n + 1, 0);
	}
private:
	int n;
	std::vector<T> bit;
	std::vector<int> coord;
};

struct Segment {
	int l, r;
	int pos;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<Segment> hori, vert;
	for(int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2) {
			std::swap(x1, x2);
		}
		if(y1 > y2) {
			std::swap(y1, y2);
		}
		if(x1 == x2) {
			// vertical
			Segment cur;
			cur.l = y1;
			cur.r = y2;
			cur.pos = x1;
			vert.push_back(cur);
		} else {
			Segment cur;
			cur.l = x1;
			cur.r = x2;
			cur.pos = y1;
			hori.push_back(cur);
		}
	}
	std::sort(vert.begin(), vert.end(), [](Segment v1, Segment v2) {
		return v1.pos < v2.pos;
	});
	std::sort(hori.begin(), hori.end(), [](Segment v1, Segment v2) {
		return v1.r > v2.r;
	});
	// init structure
	FenwickTree<int> tree;
	{
		std::vector<int> a;
		for(auto h : hori) {
			a.push_back(h.pos);
		}
		tree.init(a);
	}
	// solve verts
	n = (int) vert.size();
	int m = (int) hori.size();
	long long ans = 0;
	auto f = [](long long x) { return x * (x - 1) / 2; };
	for(int i = 0; i < n; i++) {
		tree.reset();
		int pt = 0;
		for(int j = n-1; j > i; j--) {
			int l = std::max(vert[i].l, vert[j].l);
			int r = std::min(vert[i].r, vert[j].r);
			if(l >= r) {
				continue;
			}
			while(pt < m && hori[pt].r >= vert[j].pos) {
				if(hori[pt].l <= vert[i].pos && vert[i].l <= hori[pt].pos && hori[pt].pos <= vert[i].r) {
					tree.upd(hori[pt].pos, 1);
				}
				pt++;
			}
			//std::cout << "segments " << i << ", " << j << " got " << tree.qry(r) - tree.qry(l - 1) << '\n';
			ans += f(tree.qry(r) - tree.qry(l - 1));
		}
	}
	std::cout << ans << '\n';
}