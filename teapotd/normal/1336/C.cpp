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

struct KMR {
    vector<Vi> ids;

    KMR() {}

    // Initialize structure; time: O(n lg^2 n)
    // You can change str type to Vi freely.
    KMR(const string& str) {
        ids.clear();
        ids.pb(Vi(all(str)));

        for (int h = 1; h <= sz(str); h *= 2) {
            vector<pair<Pii, int>> tmp;

            rep(j, 0, sz(str)) {
                int a = ids.back()[j], b = -1; 
                if (j+h < sz(str)) b = ids.back()[j+h];
                tmp.pb({ {a, b}, j });
            }

            sort(all(tmp));
            ids.emplace_back(sz(tmp));

            int n = 0;
            rep(j, 0, sz(tmp)) {
                if (j > 0 && tmp[j-1].x != tmp[j].x)
                    n++;
                ids.back()[tmp[j].y] = n;
            }
        }
    }

    // Get representative of [begin;end); O(1)
    Pii get(int begin, int end) {
        if (begin >= end) return {0, 0};
        int k = 31 - __builtin_clz(end-begin);
        return {ids[k][begin], ids[k][end-(1<<k)]};
    }

    // Compare [b1;e1) with [b2;e2); O(1)
    // Returns -1 if <, 0 if ==, 1 if >
    int cmp(int b1, int e1, int b2, int e2) {
        int l1 = e1-b1, l2 = e2-b2;
        int l = min(l1, l2);
        Pii x = get(b1, b1+l), y = get(b2, b2+l);

        if (x == y) return (l1 > l2) - (l1 < l2);
        return (x > y) - (x < y);
    }
};

constexpr int MOD = 998244353;
constexpr int BASE = 257;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
int salt = rnd() % 256;

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

template<class T> Vi kmp(const T& str) {
    Vi ps; ps.pb(-1);
    each(x, str) {
        int k = ps.back();
        while (k >= 0 && str[k] != x) k = ps[k];
        ps.pb(k+1);
    }
    return ps;
}

string s, t;
Zp sub[3005][3005];
Zp ways[3005][3005]; // len, match len -> ways

void run() {
    cin >> s >> t;
    reverse(all(t));

    rep(i, 0, sz(t)+1) {
        sub[i][i] = 1;
    }

    Vi ps = kmp(t);
    KMR kmr(t);
    vector<pair<Pii, int>> kek;

    rep(len, 1, sz(t)+1) {
        char chr = s[len-1];
        kek.clear();

        rep(b, 0, sz(t)-len+1) {
            int e = b+len;
            if (t[b] == chr) {
                sub[b][e] += sub[b+1][e];
            }
            if (t[e-1] == chr) {
                sub[b][e] += sub[b][e-1];
            }

            Pii repr = kmr.get(b, e);
            kek.pb({ repr, b });
        }

        sort(all(kek));

        if (len < sz(s)) rep(i, 0, sz(kek)) {
            if (i > 0 && kek[i-1].x == kek[i].x) {
                continue;
            }

            chr = s[len];
            bool pre = 1, post = 1;

            for (int j = i; j < sz(kek) && kek[i].x == kek[j].x; j++) {
                int b = kek[j].y, e = b+len;
                if (b > 0 && t[b-1] == chr) pre = 0;
                if (e < sz(t) && t[e] == chr) post = 0;
            }

            int b = kek[i].y, e = b+len;
            int k = e;
            while (e-k < b) k = ps[k];

            if (pre) {
                ways[len+1][k] += sub[b][e];
            }

            if (post) {
                if (k == sz(t)) k = ps[k];
                while (k >= 0 && t[k] != chr) k = ps[k];
                ways[len+1][k+1] += sub[b][e];
            }
        }
    }

    if (sz(s) == sz(t)) {
        cout << sub[0][sz(t)].x << endl;
        return;
    }

    bool has[26] = {0};
    each(c, t) has[c-'a'] = 1;

    if (!has[s[0]-'a']) {
        ways[1][0] += 2;
    }

    vector<array<int, 26>> append(sz(t)+1); // match len, chr -> new match len

    rep(len, 0, sz(t)+1) {
        rep(chr, 0, 26) {
            int k = len;
            if (k == sz(t)) k = ps[k];
            while (k >= 0 && t[k]-'a' != chr) k = ps[k];
            append[len][chr] = k+1;
        }
    }

    rep(i, 0, sz(s)) {
        char chr = s[i];
        rep(len, 0, min(sz(t)+1, i)) {
            ways[i+1][append[len][chr-'a']] += ways[i][len];
            ways[i+1][len] += ways[i][len];
        }
    }

    Zp ans = sub[0][sz(t)];
    rep(i, 0, sz(s)+1) ans += ways[i][sz(t)];
    cout << ans.x << endl;
}