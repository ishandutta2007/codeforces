#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <bitset>

const int ms = 10010;

int n, q;
std::map<int, int> shifts[ms + ms + ms + ms];
std::bitset<ms> tree[ms + ms + ms + ms];

void upd(int pos, int x) {
	while(x <= n && shifts[pos][x] == 2) {
		shifts[pos][x] = 1;
		x += x;
	}
	if(x <= n) {
		shifts[pos][x]++;
	}
}

void upd(int l, int r, int x) {
	for(l += n, r += n; l < r; l /= 2, r /= 2) {
		if(l&1) upd(l++, x);
		if(r&1) upd(--r, x);
	}
}

int main() {
	std::cin >> n >> q;
	int orin = n;
	n = 1;
	while(n < orin) n += n;
	while(q--) {
		int l, r, x;
		//std::cin >> l >> r >> x;
		scanf("%d %d %d", &l, &r, &x);
		upd(l - 1, r, x);
	}
	for(int i = n + n - 1; i > 0; i--) {
		if(i < n) {
			tree[i] = tree[i + i] | tree[i + i + 1];
		}
		tree[i][0] = true;
		for(auto v : shifts[i]) {
			while(v.second--) {
				tree[i] |= tree[i] << v.first;
			}
		}
	}
	std::vector<int> ans;
	for(int i = 1; i <= orin; i++) {
		if(tree[1][i]) {
			ans.push_back(i);
		}
	}
	std::cout << ans.size() << std::endl;
	for(int i = 0; i < ans.size(); i++) {
		printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
	}
}