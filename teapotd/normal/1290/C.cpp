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

Vi par, val, siz, ones;
vector<bool> forced;

Pii find(int i) {
    if (par[i] == -1) {
        return {i, val[i]};
    }
    auto t = find(par[i]);
    return {t.x, t.y ^ val[i]};
}

void join(int i, int j) {
    i = find(i).x;
    j = find(j).x;
    if (i == j) return;

    if (siz[i] > siz[j]) {
        swap(i, j);
    }

    siz[j] += siz[i];
    ones[j] += ones[i];
    par[i] = j;
    val[i] ^= val[j];
    forced[j] = forced[i] || forced[j];
}

void flip(int i) {
    i = find(i).x;
    val[i] ^= 1;
    ones[i] = siz[i]-ones[i];
}

int score(int i) {
    i = find(i).x;
    int ret = ones[i];
    if (!forced[i]) {
        ret = min(ret, siz[i]-ones[i]);
    }
    return ret;
}

void run() {
    int n, k; cin >> n >> k;
    string state; cin >> state;

    vector<Vi> lampToSet(n);

    rep(i, 0, k) {
        int c; cin >> c;
        rep(j, 0, c) {
            int x; cin >> x;
            lampToSet[x-1].pb(i);
        }
    }

    par.resize(k, -1);
    val.resize(k, 0);
    siz.resize(k, 1);
    ones.resize(k, 0);
    forced.resize(k, 0);

    int ans = 0;

    rep(i, 0, n) {
        int need = state[i] == '0';

        if (sz(lampToSet[i]) == 1) {
            int v = lampToSet[i][0];
            auto tmp = find(v);
            ans -= score(tmp.x);
            if (tmp.y != need) {
                flip(tmp.x);
                assert(!forced[tmp.x]);
            }
            forced[tmp.x] = 1;
            ans += score(tmp.x);
        } else if (sz(lampToSet[i]) == 2) {
            int v = lampToSet[i][0];
            int u = lampToSet[i][1];
            Pii a = find(v), b = find(u);
            if (a.x != b.x) {
                ans -= score(a.x);
                ans -= score(b.x);
                if ((a.y^b.y) != need) {
                    if (forced[a.x]) {
                        assert(!forced[b.x]);
                        flip(b.x);
                    } else {
                        flip(a.x);
                    }
                }
                join(u, v);
                ans += score(find(v).x);
            }
        } else {
            assert(!need);
        }

        cout << ans << '\n';
    }
}