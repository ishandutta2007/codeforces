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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T, class Cmp = less<T>>
using ordered_set = tree<
    T, null_type, Cmp, rb_tree_tag,
    tree_order_statistics_node_update
>;

void run() {
    int n, m; cin >> n >> m;
    Vi msg(m);

    each(k, msg) {
        cin >> k;
        k--;
    }

    Vi pMin(n), pMax(n);
    iota(all(pMin), 0);
    iota(all(pMax), 0);

    each(k, msg) {
        pMin[k] = 0;
    }

    ordered_set<Pii> state;
    Vi prior(n);
    iota(all(prior), 0);
    rep(i, 0, n) state.insert({i, i});
    int cur = -1;

    each(k, msg) {
        pMax[k] = max(pMax[k], int(state.order_of_key({prior[k], k})));
        state.erase({prior[k], k});
        prior[k] = cur--;
        state.insert({prior[k], k});
    }

    rep(k, 0, n) {
        pMax[k] = max(pMax[k], int(state.order_of_key({prior[k], k})));
    }

    rep(i, 0, n) {
        cout << pMin[i]+1 << ' ' << pMax[i]+1 << '\n';
    }
}