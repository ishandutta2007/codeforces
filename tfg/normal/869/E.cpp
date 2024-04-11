#include <iostream>
#include <vector>
#include <map>

typedef long long ll;

const int ms = 2510;

int n, m, q;

ll bit[ms][ms];
std::map<std::vector<int>, ll> val;

void upd(int r, int c, ll v) {
	for(int x = r; x < ms; x += x & -x) {
		for(int y = c; y < ms; y += y & -y) {
			bit[x][y] += v;
		}
	}
}

void upd(int r1, int r2, int c1, int c2, ll v) {
	upd(r1, c1, v);
	upd(r1, c2 + 1, -v);
	upd(r2 + 1, c1, -v);
	upd(r2 + 1, c2 + 1, v);
}

ll qry(int r, int c) {
	ll ans = 0;
	for(int x = r; x > 0; x -= x & -x) {
		for(int y = c; y > 0; y -= y & -y) {
			ans += bit[x][y];
		}
	}
	return ans;
}

int main() {
	std::cin >> n >> m >> q;
	while(q--) {
		int t, r1, c1, r2, c2;
		std::cin >> t >> r1 >> c1 >> r2 >> c2;
		if(t == 1) {
			upd(r1, r2, c1, c2, 1e10 + q);
			val[{r1, r2, c1, c2}] = 1e10 + q;
		} else if(t == 2) {
			upd(r1, r2, c1, c2, -val[{r1, r2, c1, c2}]);
		} else {
			if(qry(r1, c1) == qry(r2, c2)) {
				std::cout << "Yes\n";
			} else {
				std::cout << "No\n";
			}
		}
	}
}