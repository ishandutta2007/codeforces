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
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

#undef LOC
#ifdef LOC

namespace com {
    int x = 50, y = 50, p = 500, q = 200;
    int remQueries = 40;

    void init() {
        mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
        x = rnd() % int(1e9) + 1;
        y = rnd() % int(1e9) + 1;
        p = rnd() % int(1e9) + 1;
        q = rnd() % int(1e9) + 1;
        if (x > p) swap(x, p);
        if (y > q) swap(y, q);
    }

    int ask(int i, int j) {
        assert(!(i >= x && i <= p && j >= y && j <= q));
        assert(remQueries-- > 0);
        int ret = 0;
        if (i < x) ret += x-i;
        else if (i > p) ret += i-p;
        if (j < y) ret += y-j;
        else if (j > q) ret += j-q;
        deb(x, y, p, q, i, j, ret, remQueries);
        return ret;
    }

    void answer(int x_, int y_, int p_, int q_) {
        deb(x, y, p, q, x_, y_, p_, q_, remQueries);
        assert(x_ == x);
        assert(y_ == y);
        assert(p_ == p);
        assert(q_ == q);
    }
};

#else

namespace com {
    void init() {
    }

    int ask(int i, int j) {
        cout << "? " << i << ' ' << j << endl;
        int ret; cin >> ret;
        return ret;
    }

    void answer(int x_, int y_, int p_, int q_) {
        cout << "! " << x_ << ' ' << y_ << ' ' << p_ << ' ' << q_ << endl;
    }
};

#endif

int ask(int i, int j) {
    static map<Pii, int> cache;
    if (!cache.count({i, j})) {
        cache[{i, j}] = com::ask(i, j);
    }
    return cache[{i, j}];
}

void answer(int x, int y, int p, int q) {
    com::answer(x, y, p, q);
    exit(0);
}

void run() {
    constexpr int lim = 1e9;
    com::init();

    int d1 = ask(1, 1), d2 = ask(lim, 1);
    int nice = (lim + 1 + d1 - d2) / 2;

    int y = ask(nice, 1) + 1;
    int q = lim - ask(nice, lim);
    int x = ask(1, y) + 1;
    int p = lim - ask(lim, y);
    answer(x, y, p, q);
}