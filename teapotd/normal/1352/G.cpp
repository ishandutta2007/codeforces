#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

Vi get(int n) {
    Vi perm(n);
    assert(n >= 4);

    bool mode = 0;
    for (int i = 0; i+4 <= n; i += 4) mode = !mode;

    for (int i = 0; i+4 <= n; i += 4) {
        if (mode) {
            perm[i+0] = i+3;
            perm[i+1] = i+1;
            perm[i+2] = i+4;
            perm[i+3] = i+2;
        } else {
            perm[i+3] = i+3;
            perm[i+2] = i+1;
            perm[i+1] = i+4;
            perm[i+0] = i+2;
        }
        mode = !mode;
    }

    if (n%4 == 1) {
        perm[n-1] = n;
    } else if (n%4 == 2) {
        perm[n-3] = n;
        perm[n-2] = n-4;
        perm[n-1] = n-1;
    } else if (n%4 == 3) {
        perm[n-4] = n-1;
        perm[n-3] = n-5;
        perm[n-2] = n-2;
        perm[n-1] = n;
    }

    return perm;
}

void run() {
    /*
    rep(i, 4, 50) {
        Vi perm = get(i);
        rep(j, 1, sz(perm)) {
            int k = abs(perm[j] - perm[j-1]);
            assert(k >= 2 && k <= 4);
        }
        sort(all(perm));
        Vi kek(i);
        iota(all(kek), 1);
        assert(perm == kek);
    }
    */

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        if (n <= 3) {
            cout << -1 << '\n';
            continue;
        }

        Vi perm = get(n);
        each(p, perm) cout << p << ' ';
        cout << '\n';
    }
}