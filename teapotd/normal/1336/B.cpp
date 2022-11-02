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

void solve() {
    int n[3];
    rep(i, 0, 3) cin >> n[i];

    Vi elems[3];

    rep(i, 0, 3) {
        elems[i].resize(n[i]);
        each(e, elems[i]) cin >> e;
        sort(all(elems[i]));
    }

    int perm[3] = {0,1,2};
    ll ans = INT64_MAX;

    auto check = [&](ll a, ll b, ll c) {
        ll val = (a-b)*(a-b) + (a-c)*(a-c) + (b-c)*(b-c);
        ans = min(ans, val);
    };

    do {
        int left = perm[0];
        int mid = perm[1];
        int right = perm[2];

        each(l, elems[left]) {
            auto it_r = lower_bound(all(elems[right]), l);
            if (it_r == elems[right].end()) continue;
            int r = *it_r;

            auto it_m = lower_bound(all(elems[mid]), l+r, [](int a, int b) { return a*2 < b; });

            if (it_m != elems[mid].end()) {
                int m = *it_m;
                check(l, m, r);
            }

            if (it_m != elems[mid].begin()) {
                int m = *prev(it_m);
                check(l, m, r);
            }
        }
    } while (next_permutation(perm, perm+3));

    cout << ans << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}