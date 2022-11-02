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

void run() {
    int n; cin >> n;
    Vi has(n+5);

    rep(i, 0, n) {
        int k; cin >> k;
        has[k]++;
    }

    each(e, has) {
        e = min(e, 3);
    }

    vector<bool> sm(n+5), gr(n+5);

    rep(i, 1, n+5) {
        rep(j, 0, has[i]) {
            if (!sm[i-1] && !sm[i]) sm[i+1] = 1;
            if (!gr[i-1]) gr[i-1] = 1;
            else if (!gr[i]) gr[i] = 1;
            else gr[i+1] = 1;
        }
    }

    auto ansGr = count(all(gr), 1);
    auto ansSm = count(all(sm), 1);
    cout << ansSm << ' ' << ansGr << '\n';
}