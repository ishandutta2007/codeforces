#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cstring>
#include <queue>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;
const int me = 19;

std::vector<int> tree[ms + ms];
int left[ms], right[ms];
int a[ms];

class SegmentTree {
public:
	void init(std::vector<int> &base) {
		n = base.size();
		tree.resize(2 * n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = base[i];
		}
		for(int i = n - 1; i > 0; i--) {
			tree[i] = std::min(tree[i+i], tree[i+i+1]);
		}
	}
	
	int qry(int l, int r, int off) {
		int ans = (int) 1e9;
		//std::cout << "1: [" << l << ", " << r << ")" << std::endl;
		if(l >= n) {
			return qry(l - n, r - n, off) + n * off;
		}
		if(l < 0) {
			return qry(l + n, r + n, off) - n * off;
		}
		//std::cout << "2: [" << l << ", " << r << ")" << std::endl;
		if(r > n) {
			return std::min(qry(l, n, off), qry(0, r - n, off) + n * off);
		}
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) ans = std::min(ans, tree[l++]);
			if(r & 1) ans = std::min(tree[--r], ans);
		}
		return ans;
	}
private:
	int n;
	std::vector<int> tree;
};

std::pair<int, int> sparse[me][ms];
std::pair<int, int> on[ms];
int ans[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	auto normalize = [&](std::pair<int, int> p) {
		return p;
		while(p.first < 0) {
			p.first += n;
			p.second += n;
		}
		while(p.first >= n) {
			p.first -= n;
			p.second -= n;
		}
		return p;
	};
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		sparse[0][i] = {i - a[i], i + a[i] + 1};
		on[i] = {i, i + 1};
	}
	SegmentTree tree1, tree2;
	std::vector<int> base1(n), base2(n);
	auto getQry = [&](int l, int r) {
		return std::pair<int, int>(tree1.qry(l, r, 1), -tree2.qry(l, r, -1));
	};
	for(int j = 0; j + 1 < me; j++) {
		for(int i = 0; i < n; i++) {
			sparse[j][i] = normalize(sparse[j][i]);
			base1[i] = sparse[j][i].first;
			base2[i] = -sparse[j][i].second;
		}
		tree1.init(base1);
		tree2.init(base2);
		for(int i = 0; i < n; i++) {
			sparse[j+1][i] = getQry(sparse[j][i].first, sparse[j][i].second);
			sparse[j+1][i] = normalize(sparse[j+1][i]);
			if(sparse[j+1][i].second - sparse[j+1][i].first >= n) {
				sparse[j+1][i] = {0, n};
			}
		}
	}
	for(int j = me - 1; j >= 0; j--) {
		for(int i = 0; i < n; i++) {
			base1[i] = sparse[j][i].first;
			base2[i] = -sparse[j][i].second;
		}
		tree1.init(base1);
		tree2.init(base2);
		for(int i = 0; i < n; i++) {
			auto it = getQry(on[i].first, on[i].second);
			it = normalize(it);
			if(it.second - it.first < n) {
				on[i] = it;
				ans[i] += 1 << j;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(n != 1) ans[i]++;
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}