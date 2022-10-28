#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int F = 10;

int pow_f[F][N * 32];
int factor[F];
int val[F];
int MOD;

int add(int a, int b) {
	return (a += b) < MOD ? a : a - MOD;
}

int sub(int a, int b) {
	return (a -= b) < 0 ? a + MOD : a;
}

int mul(int a, int b) {
	return 1LL * a * b % MOD;
}

tuple<int, int, int> gcd(int a, int b) {
	if (!b) {
		return {1, 0, a};
	} else {
		auto [x, y, g] = gcd(b, a % b);
		return {y, x - (a / b) * y, g};
	}
}

int mod_inv(int a) {
	return (get<0>(gcd(a, MOD)) % MOD + MOD) % MOD;
}

struct segment_tree {

	struct node {
		int val[F] = {};
		int lazy[F] = {};

		node(int a = 0) {
			val[0] = a;
			lazy[0] = 1;
		}

		void apply(int l, int r, const int* a) {
			val[0] = mul(val[0], a[0]);
			lazy[0] = mul(lazy[0], a[0]);
			for (int i = 1; i < F && factor[i] != -1; ++i) {
				val[i] += a[i];
				lazy[i] += a[i];
			}
		}

		void apply(int l, int r, int a) {
			for (int i = 1; i < F && factor[i] != -1; ++i) {
				while (a % factor[i] == 0) {
					a /= factor[i];
					--val[i];
				}
			}
			val[0] = mul(val[0], mod_inv(a));
		}
	};

	int evaluate(const node& a) {
		int res = a.val[0];
		for (int i = 1; i < F && factor[i] != -1; ++i) {
			res = mul(res, pow_f[i][a.val[i]]);
		}
		return res;
	}

	node combine(const node& a, const node& b) {
		return node(add(evaluate(a), evaluate(b)));
	}

	void push(int v, int l, int r) {
		int m = (l + r) / 2;
		tree[v * 2].apply(l, m, tree[v].lazy);
		tree[v * 2 + 1].apply(m + 1, r, tree[v].lazy);
		memset(tree[v].lazy, 0, sizeof tree[v].lazy);
		tree[v].lazy[0] = 1;
	}

	void pull(int v) {
		tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
	}

	node tree[N * 4];
	int n;

	void build(int v, int l, int r) {
		if (l == r) {
			tree[v] = node(1);
		} else {
			int m = (l + r) / 2;
			build(v * 2, l, m);
			build(v * 2 + 1, m + 1, r);
			pull(v);
		}
	}

	template <class... T>
	void update(int v, int l, int r, int a, int b, const T&... val) {
		if (b < l || r < a) {
			return;
		} else if (a <= l && r <= b) {
			tree[v].apply(l, r, val...);
		} else {
			push(v, l, r);
			int m = (l + r) / 2;
			update(v * 2, l, m, a, b, val...);
			update(v * 2 + 1, m + 1, r, a, b, val...);
			pull(v);
		}
	}

	node query(int v, int l, int r, int a, int b) {
		if (b < l || r < a) {
			return 0;
		} else if (a <= l && r <= b) {
			return evaluate(tree[v]);
		}

		push(v, l, r);
		int m = (l + r) / 2;
		return combine(query(v * 2, l, m, a, b), query(v * 2 + 1, m + 1, r, a, b));
	}

	segment_tree(int _n) : n(_n) {
		build(1, 1, n);
	}

	template <class... T>
	void update(int a, int b, const T&... val) {
		update(1, 1, n, a, b, val...);
	}

	node query(int a, int b) {
		return query(1, 1, n, a, b);
	}

};

void process() {
	for (int i = 1; i < F && factor[i] != -1; ++i) {
		val[i] = 0;
		while (val[0] % factor[i] == 0) {
			val[0] /= factor[i];
			++val[i];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n >> MOD;

	int m = MOD;
	int cur = 0;
	memset(factor, -1, sizeof factor);
	for (int i = 2; i * i <= m; ++i) {
		if (m % i == 0) {
			factor[++cur] = i;
			while (m % i == 0) {
				m /= i;
			}
		}
	}
	if (m > 1) {
		factor[++cur] = m;
	}

	for (int i = 1; i <= cur; ++i) {
		pow_f[i][0] = 1;
		for (int j = 1; j < n * 32; ++j) {
			pow_f[i][j] = mul(pow_f[i][j - 1], factor[i]);
		}
	}

	segment_tree st(n);

	for (int i = 1; i <= n; ++i) {
		cin >> val[0];
		process();
		st.update(i, i, val);
	}

	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r;
			cin >> l >> r >> val[0];
			process();
			st.update(l, r, val);
		} else if (type == 2) {
			int p, x;
			cin >> p >> x;
			st.update(p, p, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << st.evaluate(st.query(l, r)) << "\n";
		}
	}
}