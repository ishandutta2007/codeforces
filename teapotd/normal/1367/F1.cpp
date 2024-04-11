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

set<Pii> st;
int wrong;

void add(int pos, int val) {
    auto it = st.insert({pos, val}).x;
    auto nxt = next(it);

    if (it != st.begin()) {
        auto prv = prev(it);
        if (nxt != st.end()) {
            wrong -= prv->y > nxt->y;
        }
        wrong += prv->y > it->y;
    }

    if (nxt != st.end()) {
        wrong += it->y > nxt->y;
    }
}

void del(int pos, int val) {
    auto it = st.find({pos, val});
    auto nxt = next(it);

    if (it != st.begin()) {
        auto prv = prev(it);
        if (nxt != st.end()) {
            wrong += prv->y > nxt->y;
        }
        wrong -= prv->y > it->y;
    }

    if (nxt != st.end()) {
        wrong -= it->y > nxt->y;
    }

    st.erase(it);
}

void solve() {
    int n; cin >> n;
    Vi elems(n);
    each(e, elems) cin >> e;

    vector<int*> comp;
    each(e, elems) comp.pb(&e);
    sort(all(comp), [](int* l, int* r) { return *l < *r; });

    int lst = -1, ind = -1;
    each(e, comp) {
        if (*e != lst) {
            lst = *e;
            ind++;
        }
        *e = ind;
    }

    vector<Vi> pos(n);
    rep(i, 0, n) pos[elems[i]].pb(i);

    wrong = 0;
    st.clear();
    st.insert({-1, -1});
    st.insert({n+1, n+1});

    int end = n;
    int ans = INT_MAX;

    for (int begin = n-1; begin >= 0; begin--) {
        each(i, pos[begin]) add(i, begin);
        while (wrong > 0) {
            end--;
            each(i, pos[end]) del(i, end);
        }

        ans = min(ans, n - sz(pos[begin]));
        if (begin == end) {
            continue;
        }

        int first = next(st.begin())->x;
        int last = prev(prev(st.end()))->x;
        int alt = n - sz(st) + 2;

        if (begin > 0) {
            alt -= int(lower_bound(all(pos[begin-1]), first) - pos[begin-1].begin());
        }
        if (end < n) {
            alt -= int(pos[end].end() - lower_bound(all(pos[end]), last));
        }

        ans = min(ans, alt);
    }

    cout << ans << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}