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

struct Fenwick {
    using T = int;
    static const T ID = 0;
    T f(T a, T b)  { return a+b; }

    vector<T> s;
    Fenwick(int n = 0) : s(n, ID) {}

    void modify(int i, T v) {
        for (; i < sz(s); i |= i+1) s[i]=f(s[i],v);
    }

    T query(int i) {
        T v = ID;
        for (; i > 0; i &= i-1) v = f(v, s[i-1]);
        return v;
    }

    int lowerBound(T val) {
        if (val <= ID) return 0;
        int i = -1, mask = 1;
        while (mask <= sz(s)) mask *= 2;
        T off = ID;

        while (mask /= 2) {
            int k = mask+i;
            if (k < sz(s)) {
                T x = f(off, s[k]);
                if (val > x) i=k, off=x;
            }
        }
        return i+2;
    }
};

#define tree sdklfsskdjg
int n;
vector<Vi> G;
Vi col, ans;
Fenwick tree;

void nope() {
    cout << "NO\n";
    exit(0);
}

Pii dfs(int v) {
    int pos = tree.lowerBound(col[v]+1)-1;
    if (pos >= n) nope();

    Pii reach = {pos, pos+1};
    tree.modify(pos, -1);
    ans[v] = pos;

    each(e, G[v]) {
        Pii sub = dfs(e);
        reach.x = min(reach.x, sub.x);
        reach.y = min(reach.y, sub.y);
    }

    if (tree.query(reach.y) - tree.query(reach.y) != 0) {
        nope();
    }
    return reach;
}

ordered_set<int> check(int v) {
    ordered_set<int> agg;

    each(e, G[v]) {
        auto tmp = check(e);
        if (sz(tmp) > sz(agg)) agg.swap(tmp);
        each(k, tmp) agg.insert(k);
    }

    if (agg.order_of_key(ans[v]) != size_t(col[v])) {
        nope();
    }

    agg.insert(ans[v]);
    return agg;
}

void run() {
    cin >> n;
    G.resize(n);
    col.resize(n);
    int root = 0;

    rep(i, 0, n) {
        int p, c; cin >> p >> c;
        col[i] = c;
        if (p == 0) {
            root = i;
        } else {
            G[p-1].pb(i);
        }
    }

    ans.resize(n, -1);
    tree = {n};
    rep(i, 0, n) tree.modify(i, 1);
    dfs(root);
    check(root);

    cout << "YES\n";
    each(a, ans) cout << a+1 << ' ';
    cout << '\n';
}