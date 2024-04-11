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

struct Build {
    array<int, 10> elems = {};
    int strength = 0;
    bool operator<(const Build& r) const {
        return strength > r.strength;
    }
};

void run() {
    int n; cin >> n;
    vector<Vi> elems(n);

    each(e, elems) {
        int k; cin >> k;
        e.resize(k);
        each(f, e) cin >> f;
    }

    int m; cin >> m;
    vector<array<int, 10>> banned;
    set<array<int, 10>> seen;

    rep(j, 0, m) {
        array<int, 10> b = {};
        rep(i, 0, n) cin >> b[i], b[i]--;
        banned.pb(move(b));
    }

    sort(all(banned));

    multiset<Build> que;

    Build first;
    rep(i, 0, n) {
        first.elems[i] = sz(elems[i])-1;
        first.strength += elems[i].back();
    }
    que.insert(first);
    seen.insert(first.elems);

    for (int iter = 0;; iter++) {
        Build b = *que.begin();
        que.erase(que.begin());

        auto it = lower_bound(all(banned), b.elems);

        if (it == banned.end() || *it != b.elems) {
            rep(i, 0, n) cout << b.elems[i]+1 << ' ';
            cout << '\n';
            return;
        }

        rep(i, 0, n) {
            if (b.elems[i] > 0) {
                Build c = b;
                int k = c.elems[i]--;
                c.strength += elems[i][k-1] - elems[i][k];
                if (sz(que) < m+1 || que.rbegin()->strength < c.strength) {
                    if (!seen.count(c.elems)) {
                        que.insert(move(c));
                        seen.insert(c.elems);
                    }
                }
            }
        }

        while (sz(que) > m+1) {
            que.erase(--que.end());
        }
    }
}