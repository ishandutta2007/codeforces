#include <iostream>
#include <set>
#include <vector>
#include <cstdio>

template <class Info = int>
class ColorUpdate {
public:
	struct Range {
		Range(int l = 0) { this->l = l; }
		Range(int l, int r, Info v) {
			this->l = l;
			this->r = r;
			this->v = v;
		}
		int l, r;
		Info v;

		bool operator < (const Range &b) const { return l < b.l; }
	};

	std::vector<Range> upd(int l, int r, Info v) {
		std::vector<Range> ans;
		if(l >= r) return ans;
		auto it = ranges.lower_bound(l);
		if(it != ranges.begin()) {
			it--;
			if(it->r > l) {
				auto cur = *it;
				ranges.erase(it);
				ranges.insert(Range(cur.l, l, cur.v));
				ranges.insert(Range(l, cur.r, cur.v));
			}
		}
		it = ranges.lower_bound(r);
		if(it != ranges.begin()) {
			it--;
			if(it->r > r) {
				auto cur = *it;
				ranges.erase(it);
				ranges.insert(Range(cur.l, r, cur.v));
				ranges.insert(Range(r, cur.r, cur.v));
			}
		}
		for(it = ranges.lower_bound(l); it != ranges.end() && it->l < r; it++) {
			ans.push_back(*it);
		}
		ranges.erase(ranges.lower_bound(l), ranges.lower_bound(r));
		ranges.insert(Range(l, r, v));
		return ans;
	}
private:
	std::set<Range> ranges;
};

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	std::vector<std::vector<int>> pos(q + 1);
	int z = 0;
	for(int i = 0; i < n; i++) {
		//std::cin >> a[i];
		scanf("%d", &a[i]);
		if(a[i] == 0) {
			z++;
		}
		pos[a[i]].push_back(i);
	}
	ColorUpdate<int> tree;
	tree.upd(0, n, 1);
	int rest = n - pos[0].size() - pos[1].size();
	for(int i = 2; i <= q; i++) {
		if(pos[i].size() == 0) {
			if(pos[0].size()) {
				tree.upd(pos[0][0], pos[0][0] + 1, i);
				continue;
			} else if(rest > 0) {
				continue;
			} else {
				std::cout << "NO\n";
				return 0;
			}
		}
		rest -= pos[i].size();
		tree.upd(pos[i][0], pos[i].back() + 1, i);
	}
	std::vector<int> b(n, -1);
	auto v = tree.upd(0, n, -1);
	for(auto p : v) {
		for(int i = p.l; i < p.r; i++) {
			b[i] = p.v;
		}
	}
	bool valid = true;
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			valid = valid && b[i] > 0;
		} else {
			valid = valid && a[i] == b[i];
		}
	}
	if(valid) {
		std::cout << "YES\n";
		for(int i = 0; i < n; i++) {
			printf("%d%c", b[i], i + 1 == n ? '\n' : ' ');
		}
	} else {
		std::cout << "NO\n";
	}
}