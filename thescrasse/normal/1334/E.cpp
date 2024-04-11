// 1334E
// Divisor Paths

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, d, q, u, v, t, n, m, pc, res, check1, check2, a, b, f1[40], f2[40], mc[40], g, ftrls[1010], finv[1010], mod;
vector<ll> fct;

ll fastexp(ll b, ll e) {
    ll i, j, k;
    if (e == 0) return 1;
    if (e % 2 == 0) {
        k = fastexp(b, e / 2);
        return (k * k) % mod;
    } else {
        k = fastexp(b, e - 1);
        return (b * k) % mod;
    }
}

ll factorize(ll m) {
    ll i, j, k, x, y, s, res;
    s = 0;
    if (m == 0) {
        x = u; y = g;
    } else {
        x = g; y = v;
    }
    for (i = 0; i < fct.size(); i++) {
        k = fct[i];
        f1[i] = 0; f2[i] = 0;
        while (x % k == 0) {
            f1[i]++; x /= k;
        }
        while (y % k == 0) {
            f2[i]++; y /= k;
        }
        mc[i] = abs(f1[i] - f2[i]);
        s += mc[i];
        // cout << mc[i] << ' ';
    }
    // cout << endl;

    res = ftrls[s];
    // cout << res << endl;
    for (i = 0; i < fct.size(); i++) {
        res = (res * finv[mc[i]]) % mod;
        // cout << res << ' ';
    }
    // cout << endl;

    return res;
}

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    mod = 998244353;

    ftrls[0] = 1;
    for (i = 1; i <= 1000; i++) {
        ftrls[i] = (i * ftrls[i - 1]) % mod;
    }
    for (i = 0; i <= 1000; i++) {
        finv[i] = fastexp(ftrls[i], mod - 2);
    }

    /* for (i = 0; i <= 10; i++) {
        cout << ftrls[i] << ' ' << finv[i] << endl;
    } */

    cin >> d >> q;
    check2 = d;

    for (i = 2; i <= sqrt(d); i++) {
        if (d % i == 0) {
            check1 = 1;
            if (!fct.empty()) {
                for (auto u : fct) {
                    if (i % u == 0) {
                        check1 = 0;
                        break;
                    }
                }
            }
            if (check1 == 1) {
                fct.push_back(i);
                pc = i; k = 0;
                while (d % pc == 0) {
                    check2 /= i; pc *= i;
                }
            }
        }
    }

    if (check2 > sqrt(d)) {
        fct.push_back(check2);
    }

    while (q--) {
        cin >> u >> v;
        // cout << u << ' ' << v << endl;

        g = __gcd(u, v);

        res = 1;
        for (i = 0; i < 2; i++) {
            res = (res * factorize(i)) % mod;
        }

        cout << res << endl;
    }

    return 0;
}