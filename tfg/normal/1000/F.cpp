#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <utility>

typedef std::pair<int, int> ii;

const int ms = 500500;
int n;
std::vector<ii> tree[ms + ms];
int id[ms];

std::vector<ii> range(ms, ii(0, 0));

void add(int l, int r, ii v) {
	//std::cout << "adding " << l << ", " << r << std::endl;
	for(l += n, r += n; l < r; l /= 2, r /= 2) {
		if(l & 1) {
			tree[l++].push_back(v);
		}
		if(r & 1) {
			tree[--r].push_back(v);
		}
	}
}

void rem(int l, int r, int v) {
	return;
}

int qry(int l, int r) {
	//std::cout << "query " << l << ", " << r << std::endl;
	for(l += n; l > 0; l /= 2) {
		while(!tree[l].empty() && (tree[l].back().second != id[tree[l].back().first])) {
			tree[l].pop_back();
		}
		if(!tree[l].empty()) {
			return tree[l].back().first;
		}
	}
	return 0;
}

struct Info {
	int l, r, idx;

	void read(int id) { scanf("%d %d", &l, &r); l--, idx = id; }
};

std::vector<Info> qries[ms];

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<int> last(ms, -1);
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		//std::cin >> a[i];
		scanf("%d", &a[i]);
	}
	int m;
	std::cin >> m;
	std::vector<int> ans(m);
	for(int i = 0; i < m; i++) {
		Info cur;
		cur.read(i);
		qries[cur.r - 1].push_back(cur);
	}
	for(int i = 0; i < n; i++) {
		range[a[i]] = ii(last[a[i]] + 1, i + 1);
		last[a[i]] = i;
		add(range[a[i]].first, range[a[i]].second, ii(a[i], i));
		id[a[i]] = i;
		for(auto q : qries[i]) {
			ans[q.idx] = qry(q.l, q.r);
		}
	}
	for(int i = 0; i < m; i++) {
		printf("%d\n", ans[i]);
	}
}