#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

const int P = 998244353;

int add(int x, int y) {
	if (x + y >= P) return x + y - P;
	return x + y;
}

int sub(int x, int y) {
	if (x < y) return x - y + P;
	return x - y;
}

int mul(int x, int y) { return 1ull * x * y % P; }

int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1;
		x = mul(x, x);
	}
	return ans;
}

namespace Poly {
	vector<int> roots, rev;

	void getRevRoot(int base) {
		int n = 1 << base;
		if ((int)rev.size() == n) return;
		rev.resize(n);
		for (int i = 1; i < n; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (base - 1));
		if ((int)roots.size() >= n) return;
		int pren = max(1, (int)roots.size());
		roots.resize(n);
		for (int mid = pren; mid < n; mid <<= 1) {
			int wn = fpow(3, (P - 1) / (mid << 1));
			roots[mid] = 1;
			for (int i = 1; i < mid; i++) roots[i + mid] = mul(roots[i + mid - 1], wn);
		}
	}

	void ntt(vector<int>& a, int base) {
		int n = 1 << base;
		for (int i = 0; i < n; i++) {
			if (i < rev[i]) {
				swap(a[i], a[rev[i]]);
			}
		}
		for (int mid = 1; mid < n; mid <<= 1) {
			for (int i = 0; i < n; i += (mid << 1)) {
				for (int j = 0; j < mid; j++) {
					int x = a[i + j], y = mul(a[i + j + mid], roots[mid + j]);
					a[i + j] = add(x, y);
					a[i + j + mid] = sub(x, y);
				}
			}
		}
	}

	vector<int> operator*(vector<int> a, vector<int> b) {
		if ((int)a.size() <= 64 && (int)b.size() <= 64) {
			vector<int> ans(a.size() + b.size() - 1, 0);
			for (int i = 0; i < (int)a.size(); i++) {
				for (int j = 0; j < (int)b.size(); j++) {
					ans[i + j] = add(ans[i + j], mul(a[i], b[j]));
				}
			}
			return ans;
		}
		int n = (int)a.size() + (int)b.size() - 1, base = 0;
		while ((1 << base) < n) ++base;
		a.resize(1 << base);
		b.resize(1 << base);
		getRevRoot(base);
		ntt(a, base);
		ntt(b, base);
		for (int i = 0; i < (1 << base); i++) a[i] = mul(a[i], b[i]);
		reverse(a.begin() + 1, a.end());
		ntt(a, base);
		a.resize(n);
		int inv = fpow(1 << base, P - 2);
		for (int i = 0; i < n; i++) a[i] = mul(a[i], inv);
		return a;
	}
}

using Poly::operator*;

int n, k, f;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	k = read();
	f = read();
	if (f > k * 2) {
		printf("0\n");
		return 0;
	}
	vector<int> F(k + 1, 1);
	rep(i, 1, n - 1) {
		vector<int> G = F * F, tmp = G;
		per(j, (int)G.size() - 2, 0) G[j] = add(G[j], G[j + 1]);
		rep(j, 0, (int)G.size() - 1) {
			if (j > k) G[j] = 0;
			G[j] = add(G[j], mul(tmp[j], max(0, k - j)));
		}
		F = G;
		F.resize(k + 1);
	}
	F = F * F;
	printf("%d\n", F[f]);
}