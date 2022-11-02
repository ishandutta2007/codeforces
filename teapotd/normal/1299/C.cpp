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

using dbl = double;

void run() {
    int n; cin >> n;
    vector<dbl> elems(n);

    each(e, elems) {
        int k; cin >> k;
        e = k;
    }

    vector<pair<dbl, int>> stk;

    for (int i = n-1; i >= 0; i--) {
        dbl sum = elems[i];
        int cnt = 1;

        while (!stk.empty()) {
            dbl alt = sum / cnt;
            if (stk.back().x > alt) break;
            sum += stk.back().x*stk.back().y;
            cnt += stk.back().y;
            stk.pop_back();
        }

        stk.pb({sum/cnt, cnt});
    }

    for (int i = sz(stk)-1; i >= 0; i--) {
        auto e = stk[i];
        rep(i, 0, e.y) {
            cout << e.x << '\n';
        }
    }
}