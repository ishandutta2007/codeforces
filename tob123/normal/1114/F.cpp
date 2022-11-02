#include <bits/stdc++.h>
#define D(x)
using namespace std;

typedef long long ll;

const int P = 62;
const int M = 1e9 + 7;
const int ps[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};

#define left(i) (2 * (i) + 1)
#define right(i) (2 * (i) + 2)
#define parent(i) (((i) - 1) / 2)

const int N = 1 << 19; // must be a power of 2
const int ts = 2 * N, offset = N - 1;

int n;

// return a % b (positive value)
ll mod(ll a, ll b) {
	return ((a % b) + b) % b;
}

// return a^b mod m
ll powmod(ll a, ll b, ll m) {
	ll res = 1;
	while(b > 0)
		if(b & 1) res = (res * a) % m, --b;
		else a = (a * a) % m, b >>= 1;
	return res % m;
}

// returns d = gcd(a,b); finds x,y such that d = ax + by
int extended_euclid(int a, int b, int &x, int &y) {
	int xx = y = 0;
	int yy = x = 1;
	while(b) {
		int q = a / b;
		int t = b;
		b = a % b;
		a = t;
		t = xx;
		xx = x - q * xx;
		x = t;
		t = yy;
		yy = y - q * yy;
		y = t;
	}
	return a;
}

// computes b such that ab = 1 (mod n), returns -1 on failure
int mod_inverse(int a, int n) {
	int x, y;
	int d = extended_euclid(a, n, x, y);
	if(d > 1) return -1;
	return mod(x, n);
}

// the value with default values
struct value {
	ll b = 0;
	ll  v = 1, l = N, r = 0;
	value() {}
	value(ll b, int v, int l, int r): b(b), v(v), l(l), r(r) {}
};

// the operation with default values
// this default operation applies a * v + b to every element v
struct operation {
	ll b = 0;
	ll  v = 1;
	operation() {}
	operation(ll b, int v): b(b), v(v) {}
};

value t[2 * N];
operation o[2 * N];

// combine the value from different branches
value combine(value l, value r) {
	return value(l.b | r.b, ((ll)l.v * r.v) % M, min(l.l, r.l), max(l.r, r.r));
}

// apply an operation on top of an other operation
operation combine(operation ot, operation ob) {
	return operation(ot.b | ob.b, ((ll)ot.v * ob.v) % M);
}

// apply an operation on a range with value
value apply(operation ot, value d) {
	return value(ot.b | d.b, ((ll)d.v *  powmod(ot.v, d.r - d.l, M)) % M, d.l, d.r);
}

value getValue(int x) {
	return apply(o[x], t[x]);
}

void calcValue(int x) {
	t[x] = combine(getValue(left(x)), getValue(right(x)));
}

void propagate(int x) {
	o[left(x)] = combine(o[x], o[left(x)]);
	o[right(x)] = combine(o[x], o[right(x)]);
	o[x] = operation();
}

// query the value on the range [a, b[
value query(int a, int b, int x = 0, int l = 0, int r = N) {
	if(a <= l && r <= b)
		return getValue(x);
	if(b <= l || r <= a)
		return value();
	int m = (l + r) / 2;
	propagate(x);
	value d = combine(query(a, b, left(x), l, m), query(a, b, right(x), m, r));
	calcValue(x);
	return d;
}

// apply an operation on the range [a, b[
void apply(int a, int b, operation v, int x = 0, int l = 0, int r = N) {
	if(a <= l && r <= b) {
		o[x] = combine(v, o[x]);
		return;
	}
	if(b <= l || r <= a)
		return;
	int m = (l + r) / 2;
	propagate(x);
	apply(a, b, v, left(x), l, m);
	apply(a, b, v, right(x), m, r);
	calcValue(x);
}

void init() {
	for(int i = 0; i < N; ++i) {
		t[offset + i].l = i;
		t[offset + i].r = i + 1;
	}
	for(int x = offset - 1; x >= 0; x--)
		calcValue(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout << setprecision(12) << fixed;

	int q, l, r, x;
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> x;
		t[offset + i].v = x;
		for(int j = 0; j < P; ++j) {
			if(x % ps[j] == 0) {
				t[offset + i].b |= 1LL << j;
			}
		}
	}
	init();
	for(int i = 0; i < q; i++) {
		string s;
		cin >> s;
		if(s == "MULTIPLY") {
			cin >> l >> r >> x;
			ll b = 0;
			for(int j = 0; j < P; ++j) {
				if(x % ps[j] == 0) {
					b |= 1LL << j;
				}
			}
			apply(l - 1, r, {b, x});
		} else {
			cin >> l >> r;
			value y = query(l - 1, r);
			ll res = y.v;
			ll b = y.b;
			for(int j = 0; j < P; ++j) {
				if((b & (1LL << j)) == 0)
					continue;
				D(cout << "prime: " << ps[j] << ", res: " << res << ", b: " << b << endl;)
				res = (res * (ps[j] - 1)) % M;
				res = (res * mod_inverse(ps[j], M)) % M;

			}
			cout << res << "\n";
		}
	}

	return 0;
}