#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 110000;
const int bs = 200;
const int MOD = 998244353;

void add(int &a, int b) {
	a = a + b < MOD ? a + b : a + b - MOD;
}

int *pivot;

bool comp(int x1, int x2) {
	return pivot[x1] < pivot[x2];
}

int tmp[2][bs];

struct Bucket {
	Bucket() {
		dirty = size = 0;
	}

	void push_back(int x) {
		p[size] = size;
		lazy[size] = 0;
		dp[size] = x;
		values[size++] = 0;
	}

	void clean() {
		for(int i = size-2; i >= 0; i--) {
			add(lazy[i], lazy[i+1]);
		}
		for(int i = 0; i < size; i++) {
			add(dp[p[i]], lazy[i]);
			lazy[i] = 0;
		}
		if(dirty) {
			for(int i = 0; i < size; i++) {
				values[i] += dirty;
			}
			dirty = 0;
		}
	}

	void remake() {
		pt = 0;
		s = 0;
		for(int i = 0; i < size; i++) {
			if(i + 1 == size || values[p[i]] != values[p[i+1]]) {
				uni[s++] = i;
			}
		}
	}

	int getID(int x) {
		if(x < values[p[0]] + dirty) {
			return -1;
		}
		while(pt >= 0 && x < values[p[uni[pt]]] + dirty) {
			pt--;
		}
		while(pt + 1 < s && x >= values[p[uni[pt+1]]] + dirty) {
			pt++;
		}
		return uni[pt];
	}

	void upd(int x, int l, int r, int val) {
		if(l == 0 && r == size) {
			// lazy update
			int id = getID(x);
			if(id != -1) {
				add(lazy[id], val);
			}
		} else {
			for(int i = l; i < r; i++) {
				if(values[i] + dirty <= x) {
					//std::cout << "adding to pos " << i << ", " << values[i] << "\n";
					add(dp[i], val);
				} else {
					//std::cout << "value of " << i << " is " << values[i] << '\n';
				}
			}
		}
	}

	void upd2(int l, int r, int val) {
		//std::cout << "2 [" << l << ", " << r << ")" << std::endl;
		if(l == 0 && r == size) {
			// lazy update
			dirty += val;
		} else {
			for(int i = l; i < r; i++) {
				values[i] += val;
			}
			clean();
			pivot = values;
			int s0 = 0, s1 = 0;
			for(int i = 0; i < size; i++) {
				if(l <= p[i] && p[i] < r) {
					tmp[0][s0++] = p[i];
				} else {
					tmp[1][s1++] = p[i];
				}
			}
			std::merge(tmp[0], tmp[0] + s0, tmp[1], tmp[1] + s1, p, comp);
			remake();
		}
	}

	int values[bs], p[bs], lazy[bs], dp[bs], uni[bs];
	int dirty;
	int size, s, pt;
};

Bucket b[ms / bs + 2];
std::vector<int> pos[ms];
int a[ms];
int pt[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		pos[i].push_back(-1);
	}
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		pos[a[i]].push_back(i);
		b[i / bs].push_back(i == 0 ? 1 : 0);
	}
	b[n/bs].push_back(0);
	for(int i = 0; i <= n; i++) {
		if(i % bs == 0) {
			b[i/bs].remake();
		}
	}
	for(int i = 1; i <= n; i++) {
		pos[i].push_back(n);
		pos[i].push_back(n);
	}
	auto upd2 = [&](int l, int r, int val) {
		if(l >= r) return;
		int bl = l / bs, br = (r-1) / bs;
		if(bl == br) {
			b[bl].upd2(l - bl * bs, r - bl * bs, val);
			return;
		}
		b[bl].upd2(l - bl * bs, bs, val);
		for(int i = bl + 1; i < br; i++) {
			b[i].upd2(0, bs, val);
		}
		b[br].upd2(0, r - br * bs, val);
	};
	auto upd = [&](int l, int r, int val) {
		if(l >= r) return;
		int bl = l / bs, br = (r-1) / bs;
		if(bl == br) {
			b[bl].upd(k, l - bl * bs, r - bl * bs, val);
			return;
		}
		b[bl].upd(k, l - bl * bs, bs, val);
		for(int i = bl + 1; i < br; i++) {
			b[i].upd(k, 0, bs, val);
		}
		b[br].upd(k, 0, r - br * bs, val);
	};
	//std::cout << "got here!" << std::endl;
	for(int i = 1; i <= n; i++) {
		upd2(pos[i][1]+1, pos[i][2]+1, 1);
	}
	//std::cout << "2got here!" << std::endl;
	for(int i = 0; i < n; i++) {
		b[i/bs].clean();
		int dp = b[i/bs].dp[i%bs];
		//std::cout << "dp for " << i << " is " << dp << std::endl;
		upd(i+1, n+1, dp);
		{
			// make transition
			int v = a[i];
			upd2(pos[v][pt[v]+1]+1, pos[v][pt[v]+2]+1, -1);
			pt[v]++;
			//std::cout << "updating [" << pos[v][pt[v]+1] << ", " << pos[v][pt[v]+2] << ")" << std::endl;
			upd2(pos[v][pt[v]+1]+1, pos[v][pt[v]+2]+1, 1);
		}
	}
	//std::cout << "3got here!" << std::endl;
	b[n/bs].clean();
	std::cout << b[n/bs].dp[n%bs] << '\n';
}