#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 505500;
const int bs = 7030;
const int INF = 1e9 + 10;

int p1[bs], p2[bs];

struct Bucket {
	Bucket() {
		size = 0;
		lazy = 0;
	}

	void push_back(int v) {
		a[size++] = v;
	}

	void lazyUpdate(int v) {
		lazy = std::min(INF, lazy + v);
	}

	void rangeUpdate(int l, int r, int x) {
		if(l == 0 && r == size) {
			lazyUpdate(x);
			return;
		}
		int s1 = 0, s2 = 0;
		for(int i = 0; i < size; i++) {
			if(p[i] < l || p[i] >= r) {
				p1[s1++] = p[i];
			} else {
				p2[s2++] = p[i];
			}
		}
		for(int i = l; i < r; i++) {
			a[i] = std::min(a[i] + x, INF);
		}
		std::merge(p1, p1 + s1, p2, p2 + s2, p, [&](int v1, int v2) { return a[v1] != a[v2] ? a[v1] < a[v2] : v1 < v2; });
	}

	void init() {
		for(int i = 0; i < size; i++) {
			p[i] = i;
		}
		std::sort(p, p + size, [&](int v1, int v2) { return a[v1] != a[v2] ? a[v1] < a[v2] : v1 < v2; });
	}

	int qrymax(int v) {
		int l = 0, r = size - 1;
		while(l != r) {
			int mid = (l + r + 1) / 2;
			if(a[p[mid]] + lazy > v) {
				r = mid - 1;
			} else {
				l = mid;
			}
		}
		if(a[p[l]] + lazy == v) {
			return p[l];
		} else {
			return -1;
		}
	}

	int qrymin(int v) {
		int l = 0, r = size - 1;
		while(l != r) {
			int mid = (l + r) / 2;
			if(a[p[mid]] + lazy >= v) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		if(a[p[l]] + lazy == v) {
			return p[l];
		} else {
			return -1;
		}
	}

	int size, lazy;
	int a[bs], p[bs];
};

Bucket bu[ms / bs + 10];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		bu[i / bs].push_back(x);
	}
	for(int i = 0; i < n; i += bs) {
		bu[i / bs].init();
	}
	while(m--) {
		int t;
		std::cin >> t;
		if(t == 1) {
			int l, r, x;
			std::cin >> l >> r >> x;
			l--;r--;
			for(int i = l / bs; i <= r / bs; i++) {
				int ll = std::max(l, i * bs);
				int rr = std::min(r, i * bs + bs - 1) + 1;
				ll -= i * bs;
				rr -= i * bs;
				//std::cout << "making update in bucket " << i << " range is [" << ll << ", " << rr << ")" << std::endl;
				bu[i].rangeUpdate(ll, rr, x);
			}
		} else {
			int l = 0, r = n - 1, x;
			std::cin >> x;
			int mn = n, mx = -1;
			if(r - l <= 3 * bs) {
				for(int i = l; i <= r; i++) {
					if(bu[i / bs].a[i % bs] + bu[i / bs].lazy == x) {
						mn = std::min(mn, i);
						mx = std::max(mx, i);
					}
				}
			} else {
				for(int i = l; i / bs == l / bs; i++) {
					if(bu[i / bs].a[i % bs] + bu[i / bs].lazy == x) {
						mn = std::min(mn, i);
						mx = std::max(mx, i);
					}
				}
				for(int i = l / bs + 1; i < r / bs; i++) {
					if(mn == n) {
						int id = bu[i].qrymin(x);
						if(id != -1) {
							id += i * bs;
							mn = std::min(mn, id);
							mx = std::max(mx, id);
						}
					}
					if(mn != n) {
						int id = bu[i].qrymax(x);
						if(id != -1) {
							id += i * bs;
							mn = std::min(mn, id);
							mx = std::max(mx, id);
						}
					}
				}
				for(int i = r / bs * bs; i <= r; i++) {
					if(bu[i / bs].a[i % bs] + bu[i / bs].lazy == x) {
						mn = std::min(mn, i);
						mx = std::max(mx, i);
					}
				}
			}
			if(mx >= mn) {
				std::cout << mx - mn << '\n';
			} else {
				std::cout << "-1\n";
			}
		}
	}
}