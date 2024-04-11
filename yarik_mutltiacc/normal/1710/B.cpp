// Problem: B. Rain
// Contest: Codeforces - Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}

#include <algorithm>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

#define int ll
ll e() { return -(1ll<<60); }
ll mx(ll a, ll b) { return max(a, b); }
using RMQ = atcoder::segtree<ll, mx, e>;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, M;
		cin >> n >> M;
		vector<array<int, 2>> a(n);
		string ans(n, '.');
		vector<int> coord, run;
		for(auto &[x, y] : a) {
			cin >> x >> y;
			coord.push_back(x);
			coord.push_back(x-y);
			coord.push_back(x+y);
		}
		sort(all(coord));
		coord.erase(unique(all(coord)), coord.end());
		run.resize(coord.size());
		auto find = [&](int x) {
			return lower_bound(all(coord), x) - coord.begin();
		};
		//f(l+1) - f(l) = 1
		//...
		//f(m+1) - f(m) = -1
		//...
		//f(r+1) - f(r) = 0
		for(auto &[x, y] : a) {
			run[find(x-y)]++;
			run[find(x)] -= 2;
			run[find(x+y)]++;
		}
		for(int i = 1; i < run.size(); i++) {
			run[i] += run[i-1];
		}
		vector<ll> vals(coord.size());
		for(int i = 1; i < coord.size(); i++) {
			vals[i] = vals[i-1] + (coord[i] - coord[i-1])*run[i-1];
		}
		// for(auto i : vals) cout << i << endl;
		auto b = vals, c = vals;
		for(int i = 0; i < coord.size(); i++) {
			b[i] += coord[i];
			c[i] -= coord[i];
		}
		RMQ xs(vals), ys(b), zs(c);
		for(auto [x,y] : a) {
			int l = find(x-y);
			int m = find(x);
			int r = find(x+y);
			ll A = max(xs.prod(0, l), xs.prod(r, vals.size()));
			ll B = zs.prod(l, m) - y + x;
			ll C = ys.prod(m, r) - y - x;
			A = max({A, B, C});
			cout << (A<=M);
		}
		cout << '\n';
		
		// multiset<ll> A, B, C;
		// vector<ll> ans(coord.size(), 0);
		// for(int i = 0, j = 0; i < coord.size(); i++) {
			// B.insert(val[i] + i);//-(x-y) + i
			// while(coord[j] < x-y) {
				// B.erase(B.find(val[j] + j));
				// A.insert(val[j]);
				// j++;
			// }
			// ans[j] = max(A.empty() ? 0 : *A.rbegin(),
						 // B.empty() ? 0 : *B.rbegin() - (a[-y));
		// }
		// A.clear();
		// for(auto &i : coord) i *= -1;
		// reverse(all(coord));
		// reverse(all(val));
		// for(int i = 0, j = 0; i < coord.size(); i++) {
			// B.insert(val[i] + i);//-(x-y) + i
			// while(coord[j] < x-y) {
				// B.erase(B.find(val[j] + j));
				// A.insert(val[j]);
				// j++;
			// }
			// ll t = max(A.empty() ? 0 : *A.rbegin(),
						 // B.empty() ? 0 : *B.rbegin() - (x-y));
			// ans[j] = max(ans[j], t);
		// }
		// for(int i = 0; i < n; i++)
			// cout << (ans[find(a[i][0])] < m);
		// cout << '\n';
	});
	
}
//max{ai} i < l || i > r, max{ai +i} i in [l; m]