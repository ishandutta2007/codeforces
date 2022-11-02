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

constexpr int MOD = 1e9+7;

ll modPow(ll a, ll e, ll m) {
    ll t = 1 % m;
    while (e) {
        if (e % 2) t = t*a % m;
        e /= 2; a = a*a % m;
    }
    return t;
}

struct Zp {
    ll x;
    Zp() : x(0) {}
    Zp(ll a) : x(a%MOD) { if (x < 0) x += MOD; }
    #define OP(c,d) Zp& operator c##=(Zp r) { x = x d; return *this; } Zp operator c(Zp r) const { Zp t = *this; return t c##= r; }
    OP(+, +r.x - MOD*(x+r.x >= MOD));
    OP(-, -r.x + MOD*(x-r.x < 0));
    OP(*, *r.x % MOD);
    OP(/, *r.inv().x % MOD);
    Zp inv() const { return pow(MOD-2); }
    Zp pow(ll e) const{ return modPow(x,e,MOD); }
    void print() { cerr << x; }
};

void run() {
    int n, m; cin >> n >> m;

    Vi sweet(n);
    each(s, sweet) {
        cin >> s;
        s--;
    }

    Vi fav, left, right;

    rep(i, 0, m) {
        int f, h; cin >> f >> h;
        f--;

        int seen = (sweet[0] == f);
        int l = 0;

        while (l < n && seen < h) {
            l++;
            if (l < n) seen += (sweet[l] == f);
        }

        seen = (sweet[n-1] == f);
        int r = n-1;

        while (r >= 0 && seen < h) {
            r--;
            if (r >= 0) seen += (sweet[r] == f);
        }

        if (l < n || r >= 0) {
            fav.pb(f);
            left.pb(l);
            right.pb(r);
        }
    }

    m = sz(fav);
    deb(fav);
    deb(left);
    deb(right);

    each(k, left) k = k*2+1;
    each(k, right) k = k*2;

    Vi rSorted(m), lSorted(m);
    iota(all(rSorted), 0);
    iota(all(lSorted), 0);
    sort(all(rSorted), [&](int l, int r) { return right[l] < right[r]; });
    sort(all(lSorted), [&](int l, int r) { return left[l] < left[r]; });

    Vi mustL(n), mustR(n), both(n);

    int curCnt = 0, bestCnt = 0;
    Zp curWays = 1, bestWays = 1;

    auto enable = [&](int i, bool b) {
        int ml = mustL[i], mr = mustR[i];
        int two = both[i];
        if (ml > mr) swap(ml, mr);

        assert(ml >= 0 && mr >= 0 && two >= 0);

        int cnt = 0;
        Zp ways = 1;

        if (ml == 0 && mr == 0) {
            if (two == 1) {
                cnt = 1;
                ways = 2;
            } else if (two >= 2) {
                cnt = 2;
                ways = Zp(two)*(two-1);
            }
        } else if (ml == 0 && mr >= 1) {
            if (two == 0) {
                cnt = 1;
                ways = mr;
            } else {
                cnt = 2;
                ways = Zp(mr+two-1) * two;
            }
        } else {
            cnt = 2;
            ways = Zp(ml+two)*mr;
            ways += Zp(ml)*two;
            ways += Zp(two)*(two-1);
        }

        if (b) {
            curCnt += cnt;
            curWays *= ways;
        } else {
            curCnt -= cnt;
            curWays /= ways;
        }
    };

    rep(i, 0, m) {
        if (left[i] >= 0) {
            mustR[fav[i]]++;
        }
    }

    rep(i, 0, n) {
        enable(i, 1);
    }

    bestCnt = curCnt;
    bestWays = curWays;
    int lastL = 0, lastR = 0;

    each(i, lSorted) {
        int x = left[i];

        while (lastL < m && left[lSorted[lastL]] <= x) {
            int l = left[lSorted[lastL]], r = right[lSorted[lastL]], f = fav[lSorted[lastL]];
            lastL++;
            enable(f, 0);

            if (l <= r) {
                mustR[f]--;
                both[f]++;
            } else {
                mustL[f]++;
            }

            enable(f, 1);
        }

        while (lastR < m && right[rSorted[lastR]] <= x) {
            int l = left[rSorted[lastR]], r = right[rSorted[lastR]], f = fav[rSorted[lastR]];
            lastR++;
            enable(f, 0);

            if (l <= r) {
                both[f]--;
                mustL[f]++;
            } else {
                mustR[f]--;
            }

            enable(f, 1);
        }

        int l = left[i], r = right[i], f = fav[i];
        int oldBoth = both[f], oldL = mustL[f];

        enable(f, 0);
        mustR[f] += oldBoth;
        both[f] = mustL[f] = 0;
        if (l < r) mustR[f]--;
        enable(f, 1);
        curCnt++;

        if (curCnt > bestCnt) {
            bestCnt = curCnt;
            bestWays = curWays;
        } else if (curCnt == bestCnt) {
            bestWays += curWays;
        }

        curCnt--;
        enable(f, 0);
        mustL[f] = oldL;
        both[f] = oldBoth;
        mustR[f] -= oldBoth;
        if (l < r) mustR[f]++;
        enable(f, 1);
    }

    cout << bestCnt << ' ' << bestWays.x << '\n';
}