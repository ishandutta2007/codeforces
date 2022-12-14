// http://codeforces.com/problemset/problem/629/C

#include <iostream>
#include <vector>

typedef long long ll;
const ll mod = 1000000007;

ll inverse(const ll x, const ll y) {
    ll a = x, b = y, ax = 1, ay = 0, bx = 0, by = 1;
    while (b) {
        ll q = a / b, tmp;
        tmp = a  - q * b ; a  = b ; b  = tmp;
        tmp = ax - q * bx; ax = bx; bx = tmp;
        tmp = ay - q * by; ay = by; by = tmp;
    }
    if (a != 1) return -1;
    while (ax < 0) ax += y;
    return ax;
}

std::vector<ll> fact, invfact;

ll choose(int n, int k) {
    return ((fact[n] * invfact[k]) %mod * invfact[n-k]) %mod;
}

ll count(int len, int height) { // must return %mod, but still ll
    if (len < height || height < 0 || len < 0) return 0;
    if (len == height) return 1; // choose(n,k) don't accept k>n
    return (choose(len, (len + height) / 2) - choose(len, (len + height)/2 + 1) + mod) %mod;
}

int main() {
    fact.resize(2005); invfact.resize(2005); fact[0] = invfact[0] = 1;
    for (int i = 1; i < fact.size(); ++i) {
        invfact[i] = inverse(fact[i] = (fact[i-1]*i) %mod, mod);
    }

    std::ios_base::sync_with_stdio(false);
    int len_s, expected_len;
    std::cin >> expected_len >> len_s;
    if (expected_len % 2) {
        std::cout << 0;
        return 0;
    }
    char ch;
    int height_s = 0, min_height_s = 0;
    for (int i = 0; i < len_s; ++i) {
        std::cin >> ch;
        if (ch == '(') {
            ++height_s;
        } else {
            min_height_s = std::min(--height_s, min_height_s);
        }
    }
    ll res = 0;
    int _min_h_s = -min_height_s, diff = expected_len - len_s; // _min_h_s >= 0
    for (int len_p = _min_h_s; len_p <= diff - (height_s + _min_h_s); ++len_p) {
        for (int height_p = len_p; height_p >= _min_h_s; height_p -= 2) {
            res = (res + count(len_p, height_p) * count(diff - len_p, height_p + height_s)) %mod;
        }
    }
    std::cout << res;
}