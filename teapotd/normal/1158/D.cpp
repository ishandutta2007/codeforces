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

template<class T, class S> struct bvec2 {
    T x, y;
    S operator+(S r) const {return{x+r.x,y+r.y};}
    S operator-(S r) const {return{x-r.x,y-r.y};}
    S operator*(T r) const { return {x*r, y*r}; }
    S operator/(T r) const { return {x/r, y/r}; }
    T dot(S r)   const { return x*r.x+y*r.y; }
    T cross(S r) const { return x*r.y-y*r.x; }
    T len2()     const { return x*x + y*y; }
    double len() const { return sqrt(len2()); }
    S perp()     const { return {-y,x}; }
    pair<T, T> yxPair() const { return {y,x}; }
};

struct vec2i : bvec2<ll, vec2i> {
    vec2i() : bvec2{0, 0} {}
    vec2i(ll a, ll b) : bvec2{a, b} {}
    bool operator==(vec2i r) const {
        return x == r.x && y == r.y;
    }
    bool operator<(vec2i r) const {
        if (upper() != r.upper()) return upper();
        auto t = cross(r);
        return t > 0 || (!t && len2() < r.len2());
    }
    bool upper() const {
        return y > 0 || (y == 0 && x >= 0);
    }
};

using vec2 = vec2i;

void run() {
    int n; cin >> n;
    vector<vec2> elems(n);
    each(e, elems) cin >> e.x >> e.y;
    string s; cin >> s;

    int last = 0;
    rep(i, 1, n) if (elems[i].yxPair() < elems[last].yxPair()) last = i;

    Vi ans;
    vector<bool> taken(n);
    taken[last] = 1;
    ans.pb(last);

    rep(j, 0, sz(s)) {
        int nxt = -1;
        vec2 best;

        rep(i, 0, n) if (!taken[i]) {
            vec2 alt = elems[i] - elems[last];
            bool ok = (nxt == -1);
            if (!ok) {
                if (s[j] == 'L') {
                    ok = alt.cross(best) > 0;
                } else {
                    ok = alt.cross(best) < 0;
                }
            }
            if (ok) {
                best = alt;
                nxt = i;
            }
        }

        last = nxt;
        taken[last] = 1;
        ans.pb(last);
    }

    rep(i, 0, n) if (!taken[i]) {
        ans.pb(i);
    }

    each(a, ans) cout << a+1 << ' ';
    cout << '\n';
}