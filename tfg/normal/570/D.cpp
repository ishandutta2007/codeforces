#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

struct FenwickTree {
	int n;
	std::vector<int> bit;

	void init(int n) {
		this->n = n;
		bit.assign(n + 1, 0);
	}

	int qry(int x) {
		int ans = 0;
		for(; x > 0; x -= x & -x) {
			ans ^= bit[x];
		}
		return ans;
	}

	int qry(int l, int r) {
		return qry(r) ^ qry(l - 1);
	}

	void upd(int x, int v) {
		for(; x <= n; x += x & -x) {
			bit[x] ^= v;
		}
	}
};

const int ms = 500500;

std::vector<int> edges[ms];
std::vector<int> pos[ms];
int cnt[ms];
FenwickTree trees[ms];
char str[ms];

int st[ms], en[ms], c = 0;
int p[ms], he[ms];
void dfs(int on = 0, int h = 0) {
	//std::cout << "in " << on << std::endl;
	he[on] = h;
	p[c] = on;
	pos[h].push_back(c);
	st[on] = c++;
	for(auto to : edges[on]) {
		dfs(to, h + 1);
	}
	en[on] = c;
	//std::cout << "out " << on << std::endl;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i < n; i++) {
		int u;
		scanf("%d", &u);
		edges[u - 1].push_back(i);
	}
	dfs();
	for(int i = 0; i < n; i++) {
		trees[i].init(pos[i].size());
	}
	scanf(" %s", str);
	for(int i = 0; i < n; i++) {
		trees[he[p[i]]].upd(++cnt[he[p[i]]], 1 << (str[p[i]] - 'a'));
	}
	while(m--) {
		int v, h;
		scanf("%d %d", &v, &h);
		v--;h--;
		int l = std::lower_bound(pos[h].begin(), pos[h].end(), st[v]) - pos[h].begin();
		int r = std::lower_bound(pos[h].begin(), pos[h].end(), en[v]) - pos[h].begin();
		int val = trees[h].qry(l + 1, r);
		if((val - (val & -val)) == 0) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
}