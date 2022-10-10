#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

std::vector<std::pair<int, int>> tree[ms + ms];

std::vector<std::pair<int, int>> compress(std::vector<std::pair<int, int>> &a) {
	std::vector<std::pair<int, int>> ans;
	std::sort(a.begin(), a.end());
	for(auto p : a) {
		if(!ans.empty() && ans.back().first == p.first) continue;
		while(!ans.empty() && ans.back().second >= p.second) {
			ans.pop_back();
		}
		ans.push_back(p);
	}
	return ans;
}

std::vector<std::pair<int, int>> merge(std::vector<std::pair<int, int>> &a, std::vector<std::pair<int, int>> &b) {
	int n = (int) a.size(), m = (int) b.size();
	std::vector<std::pair<int, int>> ans;
	int i = 0, j = 0;
	while(i < n && j < m) {
		int second = std::max(a[i].second, b[j].second);
		if(a[i].first == b[j].first) {
			ans.emplace_back(a[i].first, second);
			i++;
			j++;
		} else if(a[i].first < b[j].first) {
			ans.emplace_back(a[i].first, second);
			i++;
		} else {
			ans.emplace_back(b[j].first, second);
			j++;
		}
	}
	return ans;
}

bool qry(std::vector<std::pair<int, int>> &a, int x, int y) {
	int id = std::lower_bound(a.begin(), a.end(), std::pair<int, int>(x, -1)) - a.begin();
	if(id < (int) a.size() && a[id].second <= y) return true;
	else return false;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	while(k--) {
		int l, r, p;
		std::cin >> l >> r >> p;
		p--;
		tree[p + n].emplace_back(l, r);
	}
	for(int i = 0; i < n; i++) {
		tree[i+n] = compress(tree[i+n]);
	}
	for(int i = n-1; i > 0; i--) {
		tree[i] = merge(tree[i+i], tree[i+i+1]);
	}
	while(m--) {
		int l, r, x, y;
		std::cin >> l >> r >> x >> y;
		l--;
		bool valid = true;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) {
				if(!qry(tree[l++], x, y)) {
					valid = false;
				}
			}
			if(r & 1) {
				if(!qry(tree[--r], x, y)) {
					valid = false;
				}
			}
		}
		std::cout << (valid ? "yes" : "no") << std::endl;
	}
}