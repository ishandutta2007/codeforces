#undef LOC
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

int n, k;

#ifdef LOC

Vi _hidden;
int _hidden_m;

void load() {
    n = 30;
    _hidden.resize(n);
    iota(all(_hidden), 1);
    k = 20;
    _hidden_m = 19;
    deb(n, k, _hidden, _hidden_m);
}

Pii ask(Vi& pos) {
    assert(sz(pos) == k);
    vector<Pii> tmp;

    each(p, pos) {
        assert(p >= 0 && p < sz(_hidden));
        tmp.pb({_hidden[p], p});
    }

    sort(all(tmp));
    auto kek = tmp[_hidden_m-1];
    return {kek.y, kek.x};
}

void answer(int m) {
    deb(m+1, _hidden_m);
    exit(0);
}

#else

void load() {
    cin >> n >> k;
}

Pii ask(Vi& pos) {
    assert(sz(pos) == k);
    cout << "? ";
    each(i, pos) cout << i+1 << ' ';
    cout << endl;
    int p, val; cin >> p >> val;
    return {p-1, val};
}

void answer(int m) {
    cout << "! " << m+1 << endl;
    exit(0);
}

#endif

void run() {
    load();

    vector<Pii> vec(k+1);

    rep(i, 0, k+1) {
        Vi pos;
        rep(j, 0, k+1) if (i != j) pos.pb(j);
        vec[i] = ask(pos);
    }

    int sm = -1, cnt = 0;

    each(e, vec) {
        if (e.y > sm) {
            sm = e.y;
            cnt = 1;
        } else if (e.y == sm) {
            cnt++;
        }
    }

    deb(vec);
    answer(cnt-1);
}