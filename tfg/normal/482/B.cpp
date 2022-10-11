#include <iostream>
#include <cstdio>
#include <vector>

const int ms = 100100;

int n, m;
int tree[ms + ms];

void upd(int l, int r, int v) {
	for(l += n, r += n; l < r; l /= 2, r /= 2) {
		if(l&1) tree[l++] |= v;
		if(r&1) tree[--r] |= v;
	}
}

int qry(int l, int r) {
	int ans = (1 << 30) - 1;
	for(l += n, r += n; l < r; l /= 2, r /= 2) {
		if(l&1) ans &= tree[l++];
		if(r&1) ans &= tree[--r];
	}
	return ans;
}

int pl[ms], pr[ms], val[ms];

int main() {
	std::cin >> n >> m;
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", pl + i, pr + i, val + i);
		upd(pl[i] - 1, pr[i], val[i]);
	}
	for(int i = 1; i < n; i++) {
		tree[i + i] |= tree[i];
		tree[i + i + 1] |= tree[i];
	}
	for(int i = 0; i < m; i++) {
		if(qry(pl[i] - 1, pr[i]) != val[i]) {
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n";
	for(int i = 0; i < n; i++) {
		printf("%d%c", tree[i + n], i + 1 == n ? '\n' : ' ');
	}
}