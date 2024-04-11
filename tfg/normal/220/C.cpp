#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e9;

struct Tree {
	void init(int _n) {
		n = _n;
		tree.assign(2 * n, INF);
	}

	void upd(int l, int r, int v) {
		//std::cout << "updating " << l << ", " << r << " with " << v << '\n';
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l&1) {
				tree[l] = std::min(tree[l], v);
				l++;
			}
			if(r&1) {
				r--;
				tree[r] = std::min(tree[r], v);
			}
		}
	}

	int qry(int x) {
		int ans = INF;
		for(x += n; x > 0; x /= 2) {
			ans = std::min(ans, tree[x]);
		}
		return ans;
	}

	int n;
	std::vector<int> tree;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n), pos(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i]--;
		pos[a[i]] = i;
	}
	Tree tree1, tree2;
	tree1.init(n);
	tree2.init(n);
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
		b[i]--;
		if(pos[b[i]] >= i) {
			// [0, i+1) have distance pos[b[i]] - i + j
			tree1.upd(0, i+1, pos[b[i]] - i);
			// [i+1, i+n-pos[b[i]]) have distance -j+(i+1)+(n-pos[b[i]]-1)
			tree2.upd(i+1, i+n-pos[b[i]], (i+1)+(n-pos[b[i]]-1));
			// [i+n-pos[b[i]], n) have distance -(i+n-pos[b[i]]) + j
			tree1.upd(i+n-pos[b[i]], n, -(i+n-pos[b[i]]));
		} else {
			//std::cout << b[i] + 1 << " is second case\n";
			// [0, i-pos[i]) have distance i - pos[b[i]] - j
			tree2.upd(0, i-pos[b[i]], i-pos[b[i]]);
			// [i-pos[i], i+1) have distance -(i-pos[b[i]]) + j
			tree1.upd(i-pos[b[i]], i+1, -(i-pos[b[i]]));
			// [i+1, n) have distance -(i+1) + (n-pos[b[i]]-1) + j
			tree1.upd(i+1, n, -(i+1) + (n-pos[b[i]]-1));
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << std::min(tree1.qry(i) + i, tree2.qry(i) - i) << '\n';
	}
}