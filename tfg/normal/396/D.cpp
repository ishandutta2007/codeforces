#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

#define add(x, y) (x + y >= MOD ? x + y - MOD : x + y)

typedef long long ll;

const int MOD = 1e9 + 7;
const int ms = 1e6 + 10;

struct FenwickTree {
	std::vector<int> bit;

	void init(int n) {
		bit.assign(n + 1, 0);
	}

	void upd(int x, int v) {
		x++;
		for(; x < bit.size(); x += x & -x) {
			bit[x] += v;
		}
	}

	int qry(int x) {
		int ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}

	int qry(int l, int r) {
		return qry(r) - qry(l);
	}
};

int fat[ms];

ll fexp(ll x, ll e = MOD - 2) {
	ll ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}

std::vector<int> p;

ll solve1(int n) {
	FenwickTree bit;
	bit.init(n);
	ll ans = 0;
	ll invs = 0;
	ll tinvs = 0;
	for(int i = 0; i < n; i++) {
		//std::cout << "on " << i << " answer is " << ans << std::endl;
		int val = p[i];
		ll l = bit.qry(0, val);
		ll g = i - l;
		ll la = (val - l);
		invs = (invs + g);
		//std::cout << "got " << bit.qry(val, n).sum << " inversions\n";
		//std::cout << "tinvs is " << tinvs << std::endl;
		ans = (ans + 
			  ((ll) la * (la - 1) / 2 % MOD) * fat[n - i - 1] % MOD +
			  (ll) tinvs * (val - l) % MOD * fat[n - i - 1] % MOD
			  ) % MOD;
		//std::cout << tree.qry(0, val).sum << " is the inversions from lower to back\n";
		//std::cout << "(" << (val - bit.qry(0, val).sum) << ", " << bit.qry(val, n).sum << ", " << fat[n - i - 1] << ")\n";
		ll mean = (ll) (n - i - 2) * (n - i - 1) / 2 % MOD;
		mean = mean * fexp(2) % MOD;
		//std::cout << "ori mean is " << mean << std::endl;
		mean = mean * fat[n - i - 1] % MOD;
		//std::cout << "mean is " << mean << " adding " << mean * (val - bit.qry(0, val).sum) << std::endl;
		ans = (ans + mean * (val - l)) % MOD;
		tinvs = (tinvs +
			   (val - l)
			   )% MOD;
		bit.upd(val, 1);
	}
	//std::cout << "in the end, (" << tinvs << ", " << invs << ")" << std::endl;
	ans = (ans + invs) % MOD;
	return ans;
}

ll solve2(int n) {
	return 0;
	/*std::vector<int> cur(n);
	for(int i = 0; i < n; i++) {
		cur[i] = i;
	}
	ll ans = 0;
	do {
		SegmentTree<Node, int, LazyContext> bit;
		bit.init(std::vector<int>(n, 0));
		int cur_ans = 0;
		for(int i = 0; i < n; i++) {
			cur_ans += bit.qry(cur[i], n).sum;
			bit.upd(cur[i], 1);
			std::cout << cur[i] << (i + 1 == n ? '\n' : ' ');
		}
		std::cout << "got " << cur_ans << std::endl;
		ans += cur_ans;
	} while(std::next_permutation(cur.begin(), cur.end()) && cur <= p);
	return ans;*/
}

int main() {
	srand(time(0));
	fat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = (ll) fat[i - 1] * i % MOD;
	}
	int n;
	std::cin >> n;
	p.resize(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		//p[i] = i + 1;
		p[i]--;
	}
	//std::random_shuffle(p.begin(), p.end());
	for(int i = 0; i < n; i++) {
		//std::cout << p[i] << (i + 1 == n ? '\n' : ' ');
	}
	std::cout << solve1(n) << std::endl;
	//std::cout << solve2(n) << std::endl;
}