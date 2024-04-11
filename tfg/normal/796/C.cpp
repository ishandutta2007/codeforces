#include <iostream>
#include <vector>

const int ms = 300300;
const int INF = (int) 1e9 + 20;

int n;

int a[ms];
int tree[ms + ms];
void build() {
	for(int i = n-1; i > 0; i--) {
		tree[i] = std::max(tree[i+i], tree[i+i+1]);
	}
}

void upd(int x, int v) {
	x += n;
	tree[x] = v;
	for(x /= 2; x > 0; x /= 2) {
		tree[x] = std::max(tree[x+x], tree[x+x+1]);
	}
}


int qry(int l, int r) {
	int ans = -INF;
	for(l += n, r += n; l < r; l /= 2, r /= 2) {
		if(l & 1) ans = std::max(ans, tree[l++]);
		if(r & 1) ans = std::max(ans, tree[--r]);
	}
	return ans;
}
std::vector<int> edges[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		tree[i + n] = a[i];
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	build();
	int ans = INF;
	for(int i = 0; i < n; i++) {
		int cur = a[i];
		upd(i, -INF);
		for(int j = 0; j < edges[i].size(); j++) {
			int to = edges[i][j];
			cur = std::max(a[to] + 1, cur);
			upd(to, -INF);
		}
		cur = std::max(qry(0, n) + 2, cur);
		ans = std::min(ans, cur);
		for(int j = 0; j < edges[i].size(); j++) {
			int to = edges[i][j];
			upd(to, a[to]);
		}
		upd(i, a[i]);
	}
	std::cout << ans << '\n';
}