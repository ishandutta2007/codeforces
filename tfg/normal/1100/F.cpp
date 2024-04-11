#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int me = 20;

struct Gauss {
	int table[me];

	Gauss() {
		for(int i = 0; i < me; i++) {
			table[i] = 0;
		}
	}

	int size() {
		int ans = 0;
		for(int i = 0; i < me; i++) {
			if(table[i]) ans++;
		}
		return ans;
	}

	bool can(int x) {
		for(int i = me-1; i >= 0; i--) {
			x = std::min(x, x ^ table[i]);
		}
		return x == 0;
	}

	void add(int x) {
		for(int i = me-1; i >= 0 && x; i--) {
			if(table[i] == 0) {
				table[i] = x;
				x = 0;
			} else {
				x = std::min(x, x ^ table[i]);
			}
		}
	}

	int best() {
		int x = 0;
		for(int i = me-1; i >= 0; i--) {
			x = std::max(x, x ^ table[i]);
		}
		return x;
	}
};

const int ms = 1001000;

int l[ms], r[ms];
int a[ms];
Gauss ans[ms];
Gauss temp[ms];

void solve(std::vector<int> &qries, int lp, int rp) {
	if(qries.empty()) return;
	std::vector<int> left, right;
	if(rp - lp <= 20) {
		for(auto q : qries) {
			for(int i = l[q]; i < r[q]; i++) {
				ans[q].add(a[i]);
			}
		}
		return;
	}
	int mid = (lp + rp) / 2;
	// solving for suffix
	Gauss wtf;
	for(int i = mid-1; i >= lp; i--) {
		wtf.add(a[i]);
		temp[i] = wtf;
	}
	// solving for prefix
	wtf = Gauss();
	for(int i = mid; i < rp; i++) {
		wtf.add(a[i]);
		temp[i] = wtf;
	}
	for(auto q : qries) {
		if(r[q] <= mid) {
			left.push_back(q);
		} else if(l[q] >= mid) {
			right.push_back(q);
		} else {
			for(int i = 0; i < me; i++) {
				ans[q].add(temp[l[q]].table[i]);
				ans[q].add(temp[r[q] - 1].table[i]);
			}
		}
	}
	qries.clear();
	solve(left, lp, mid);
	solve(right, mid, rp);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int q;
	std::cin >> q;
	std::vector<int> qr;
	for(int i = 0; i < q; i++) {
		std::cin >> l[i] >> r[i];
		l[i]--;
		qr.push_back(i);
	}
	solve(qr, 0, n);
	for(int i = 0; i < q; i++) {
		std::cout << ans[i].best() << '\n';
	}
}