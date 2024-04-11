#include <iostream>
#include <cstdio>

typedef long long ll;

const int ms = 100100;

int n;
ll tree[ms + ms];

void upd(int pos, ll v) {
	pos += n;
	tree[pos] = v;
	for(pos /= 2; pos > 0; pos /= 2) {
		tree[pos] = std::max(tree[pos + pos], tree[pos + pos + 1]);
	}
}

ll qry(int l, int r) {
	ll ans = -1e18;
	for(l += n, r += n; l < r; l /= 2, r /= 2) {
		if(l & 1) ans = std::max(ans, tree[l++]);
		if(r & 1) ans = std::max(ans, tree[--r]);
	}
	return ans;
}

struct BIT {
	ll bit[ms];

	BIT() {
		for(int i = 0; i < ms; i++) {
			bit[i] = 0;
		}
	}

	void upd(int pos, int v) {
		for(; pos < ms; pos += pos & -pos) {
			bit[pos] += v;
		}
	}

	ll qry(int pos) {
		ll ans = 0;
		for(; pos > 0; pos -= pos & -pos) {
			ans += bit[pos];
		}
		return ans;
	}
};

BIT nums;

void fix(int pos) {
	if(pos < 2 || pos >= n) {
		return;
	}
	ll a = nums.qry(pos - 1) - nums.qry(pos);
	ll b = nums.qry(pos + 1) - nums.qry(pos);
	a = std::max(a, 0LL);
	b = std::max(b, 0LL);
	upd(pos - 1, - (2 * (a + b)));
}

ll abss(ll x) {
	return std::max(x, -x);
}

ll get(int pos) {
	if(pos > n) {
		return 0;
	}
	ll a = nums.qry(pos - 1) - nums.qry(pos);
	return abss(a);
}

int main() {
	std::cin >> n;
	ll tot = 0;
	for(int i = 1; i <= n; i++) {
		int t;
		//std::cin >> t;
		scanf("%i", &t);
		nums.upd(i, t);
		nums.upd(i + 1, -t);
	}
	for(int i = 2; i <= n; i++) {
		fix(i);
		tot += get(i);
	}
	int q;
	std::cin >> q;
	while(q--) {
		int t, l, r, x;
		//std::cin >> t >> l >> r >> x;
		scanf("%i %i %i %i", &t, &l, &r, &x);
		//std::cout << "(" << t << ", " << l << ", " << r << ", " << x << ")\n";
		//std::cout << "tot is " << tot << "\n";
		if(t == 2) {
			tot -= get(l) + get(r + 1);
			nums.upd(l, x);
			nums.upd(r + 1, -x);
			tot += get(l) + get(r + 1);
			for(int i = -1; i <= 1; i++) {
				fix(l + i);
				fix(r + i);
			}
		} else if(t == 1) {
			if(l == r) {
				//std::cout << tot - get(l) - get(l + 1) + abss(nums.qry(l - 1) - nums.qry(l) - x) + abss(nums.qry(l + 1) - nums.qry(l) - x) << '\n';
				printf("%lli\n", tot - get(l) - get(l + 1) + abss(nums.qry(l - 1) - nums.qry(l) - x) + abss(nums.qry(l + 1) - nums.qry(l) - x));
			} else {
				//std::cout << std::max(tot, tot + qry(l - 1, r) + 2 * x) << '\n';
				printf("%lli\n", std::max(tot, tot + qry(l - 1, r) + 2 * x));
			}
		}
		//std::cout << "now it is " << tot << "\n";
	}
}