#include <iostream>
#include <vector>
#include <assert.h>

#define int long long

const int MOD = 1000000007;

// WARNING! throw exception
template <typename T>
T inverse(T x, T y) {
    if (y == 1) return 0;
    T a = x, b = y, ax = 1, ay = 0, bx = 0, by = 1;
    while (b) {
        T q = a / b, tmp;
        tmp = a  - q * b ; a  = b ; b  = tmp;
        tmp = ax - q * bx; ax = bx; bx = tmp;
        tmp = ay - q * by; ay = by; by = tmp;
    }
    if (a != 1) {
		throw 0;
    }
    while (ax < 0) ax += y;
    return ax;
}

typedef long long ll;
std::vector<int> fact;
/// Alternative version using pre-calculated {fact} table.
ll binom(ll a, int k) {
	// k = std::min(k, a-k);
	if (fact.empty()) { // init code. Move to begin of main if necessary
		fact.resize(100005); fact[0] = 1; // change 10000 accordingly
		for (ll i = 1; i < fact.size(); ++i) fact[i] = fact[i-1] * i %MOD;
	}
	if (a == -1 && k == -1) return 1;
	k = std::min(k, a - k);
	if (k < 0) return 0;
	if (a == 0) {assert(k == 0); return 1;} // redundant
	return fact[a] * inverse<ll>(static_cast<ll>(fact[k]) * fact[a-k] %MOD, MOD) %MOD;
}

void add(int& a, int b) { a = (a + b) % MOD; }

int mul(int a, int b) { return (a * b) % MOD; }

signed main() {
    int nvalid = 0, nall = 0;
    int nf, nw, h;
    std::cin >> nf >> nw >> h;
    ++h; // this alg use >= h : like
    for (int sw = 0; sw <= nw; ++sw) {
        int sf;
//        sf = sw - 1;
//        add(nvalid, mul(nf == 0 ? (sf == 0 ? 1 : 0) : binom(nf - 1, sf - 1), binom(nw - 1 - (h-1)*sw, sw - 1)));
//        add(nall, mul(nf == 0 ? (sf == 0 ? 1 : 0) : binom(nf - 1, sf - 1), nw == 0 ? (sw == 0 ? 1 : 0) : binom(nw - 1, sw - 1)));
//
//        sf = sw;
//        add(nvalid, 2*mul(nf == 0 ? (sf == 0 ? 1 : 0) : binom(nf - 1, sf - 1), binom(nw - 1 - (h-1)*sw, sw - 1)));
//        add(nall, 2*mul(nf == 0 ? (sf == 0 ? 1 : 0) : binom(nf - 1, sf - 1), nw == 0 ? (sw == 0 ? 1 : 0) : binom(nw - 1, sw - 1)));
//        // safe because int = long long
//
//        sf = sw + 1;
//        add(nvalid, mul(nf == 0 ? (sf == 0 ? 1 : 0) : binom(nf - 1, sf - 1), binom(nw - 1 - (h-1)*sw, sw - 1)));
//        add(nall, mul(nf == 0 ? (sf == 0 ? 1 : 0) : binom(nf - 1, sf - 1), nw == 0 ? (sw == 0 ? 1 : 0) : binom(nw - 1, sw - 1)));

        sf = sw - 1;
        add(nvalid, mul(binom(nf - 1, sf - 1), binom(nw - 1 - (h-1)*sw, sw - 1)));
        add(nall, mul(binom(nf - 1, sf - 1), binom(nw - 1, sw - 1)));

        sf = sw;
        add(nvalid, 2*mul(binom(nf - 1, sf - 1), binom(nw - 1 - (h-1)*sw, sw - 1)));
        add(nall, 2*mul(binom(nf - 1, sf - 1), binom(nw - 1, sw - 1)));
        // safe because int = long long

        sf = sw + 1;
        add(nvalid, mul(binom(nf - 1, sf - 1), binom(nw - 1 - (h-1)*sw, sw - 1)));
        add(nall, mul(binom(nf - 1, sf - 1), binom(nw - 1, sw - 1)));
    }
//    std::cout << nvalid << '\n';
//    std::cout << nall << '\n';
    std::cout << nvalid * inverse(nall, MOD) % MOD << '\n';
}