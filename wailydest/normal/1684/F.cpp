#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>

const int N = 200005;
int t, n, m, a[N], val[N], l[N], r[N], inc[N];
std::pair<int, int> pt[N * 2];
std::vector<int> pos[N];
std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > vec;

bool test(int l) {
	for (int i = 0; i <= n; ++i) inc[i] = 0;
	for (int i = 0; i < (int)vec.size(); ++i) {
		int l1 = vec[i].first.second, r1 = std::min(n, vec[i].first.first + l);
		int l2 = vec[i].second.second, r2 = std::min(n, vec[i].second.first + l);
		if (l1 < r1) {
			if (l2 < r2) {
				if (r1 <= l2) {
					++inc[l2];
					--inc[r2];
				} else r1 = std::max(r1, r2);
			}
		} else {
			if (l2 < r2) {
				l1 = l2;
				r1 = r2;
			} else return 0;
		}
		++inc[l1];
		--inc[r1];
	}
	for (int i = 0; i < n; ++i) {
		inc[i + 1] += inc[i];
		if (inc[i] == vec.size()) return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			pos[i].clear();
			scanf("%d", a + i);
			val[i] = a[i];
		}
		std::sort(val, val + n);
		int dif = std::unique(val, val + n) - val;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", l + i, r + i);
			--l[i];
			pt[i << 1].first = l[i];
			pt[i << 1 | 1].first = r[i];
			pt[i << 1].second = pt[i << 1 | 1].second = i;
		}
		std::sort(pt, pt + m * 2);
		std::multiset<int> active;
		vec.clear();
		for (int i = 0, j = 0; i < n; ++i) {
			while (j < m * 2 && pt[j].first == i) {
				if (l[pt[j].second] == i) active.insert(i);
				else active.erase(active.find(l[pt[j].second]));
				++j;
			}
			a[i] = std::lower_bound(val, val + dif, a[i]) - val;
			pos[a[i]].push_back(i);
			if (!active.empty()) {
				int fi = std::lower_bound(pos[a[i]].begin(), pos[a[i]].end(), *active.begin()) - pos[a[i]].begin();
				if (fi != (int)pos[a[i]].size() - 1) 
					vec.push_back(std::make_pair(std::make_pair(pos[a[i]][fi], pos[a[i]][pos[a[i]].size() - 2]), std::make_pair(pos[a[i]][fi + 1], pos[a[i]][pos[a[i]].size() - 1])));
			}
		}
		int l = 0, r = n;
		while (l < r) {
			int m = l + r >> 1;
			if (test(m)) r = m;
			else l = m + 1;
		}
		printf("%d\n", r);
	}
	return 0;
}