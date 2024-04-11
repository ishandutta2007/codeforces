#include <iostream>
#include <vector>
#include <queue>

const int ms = 100100;

int par[ms];
int pos[ms];
bool got[ms];

int getPar(int x) {
	if(par[x] == x) {
		return x;
	} else {
		return par[x] = getPar(par[x]);
	}
}

void makeUnion(int a, int b, int newPos) {
	a = getPar(a);
	b = getPar(b);
	par[b] = a;
	pos[a] = newPos;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		pos[i] = par[i] = i;
	}
	int ans = n;
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		if(!got[pos[getPar(u)]]) {
			ans--;
			int newPos = pos[getPar(v)];
			int oldPos = pos[getPar(u)];
			got[oldPos] = true;
			makeUnion(u, v, newPos);
		} else if(!got[pos[getPar(v)]]) {
			ans--;
			int newPos = pos[getPar(u)];
			int oldPos = pos[getPar(v)];
			got[oldPos] = true;
			makeUnion(u, v, newPos);
		}
	}
	std::cout << ans << std::endl;
}