#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

// Correctness proved in https://github.com/kth-competitive-programming/kactl/blob/master/doc/modmul-proof.pdf
// twice faster than (__int128_t)a * b % M
using ull = unsigned long long;
ull mod_mul(ull a, ull b, ull M){
    long long res = a * b - M * ull(1.L / M * a * b);
    return res + M * (res < 0) - M * (res >= (long long)M);
}
ull mod_pow(ull b, ull e, ull mod){
    ull res = 1;
    for(; e; b = mod_mul(b, b, mod), e >>= 1) if(e & 1) res = mod_mul(res, b, mod);
    return res;
}
// Millar Rabin Primality Test
// 7 times slower than a^b mod c
bool isprime(ull n){
    if(n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull s = __builtin_ctzll(n - 1), d = n >> s;
    for(ull a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}){
        ull p = mod_pow(a, d, n), i = s;
        while(p != 1 && p != n - 1 && a % n && i --) p = mod_mul(p, p, n);
        if(p != n - 1 && i != s) return false;
    }
    return true;
}
// Pollard rho algorithm
// O(n^1/4)
ull get_factor(ull n){
    auto f = [n](ull x){ return mod_mul(x, x, n) + 1; };
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while(t ++ % 40 || gcd(prd, n) == 1){
        if(x == y) x = ++ i, y = f(x);
        if(q = mod_mul(prd, max(x, y) - min(x, y), n)) prd = q;
        x = f(x), y = f(f(y));
    }
    return gcd(prd, n);
}
// Returns the prime factors in arbitrary order
vector<ull> factorize(ull n){
    if(n == 1) return {};
    if(isprime(n)) return {n};
    ull x = get_factor(n);
    auto l = factorize(x), r = factorize(n / x);
    l.insert(l.end(), r.begin(), r.end());
    return l;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    int n, d; cin >> n >> d;

    int p = n, a = 0;
    while (p % d == 0){
        p /= d; a++;
    }
    if (a == 1){
        cout << "NO" << endl;
        continue;
    }
    if (a >= 3){
        if (a == 3 and d / p == p and p * p == d and isprime(p));
        else if (!isprime(d)){
            cout << "YES" << endl;
            continue;
        }
    }
    if (p == 1 or isprime(p)){
        cout << "NO" << endl;
        continue;
    }
    cout << "YES" << endl;
}
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/