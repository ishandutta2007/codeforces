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

template<class T, class S> struct bvec2 {
    T x, y;
    S operator+(S r) const {return{x+r.x,y+r.y};}
    S operator-(S r) const {return{x-r.x,y-r.y};}
    S operator*(T r) const { return {x*r, y*r}; }
    S operator/(T r) const { return {x/r, y/r}; }

    T dot(S r)   const { return x*r.x + y*r.y; }
    T cross(S r) const { return x*r.y - y*r.x; }
    T len2()     const { return x*x + y*y; }
    double len() const { return hypot(x, y); }
    S perp()     const { return {-y,x}; } // CCW

    pair<T, T> yx() const { return {y, x}; }

    double angle() const { //[0;2*PI] CCW from OX
        double a = atan2(y, x);
        return (a < 0 ? a+2*M_PI : a);
    }
};

struct vec2i : bvec2<ll, vec2i> {
    vec2i() : bvec2{0, 0} {}
    vec2i(ll a, ll b) : bvec2{a, b} {}

    bool upper() const { return (y ?: x) >= 0; }

    int angleCmp(vec2i r) const {
        ll c = cross(r);
        return r.upper()-upper() ?: (c<0) - (c>0);
    }

    bool operator<(vec2i r) const {
        return (angleCmp(r) ?: len2() - r.len2()) < 0;
    }

    bool operator==(vec2i r) const { return x == r.x && y == r.y; }
    bool operator!=(vec2i r) const { return x != r.x || y != r.y; }
};

using vec2 = vec2i;

void run() {
    int n; cin >> n;
    int k; cin >> k;
    k--;

    vector<vec2> points(n);
    each(p, points) cin >> p.x >> p.y;

    vector<vec2> line;
    vec2 dir, other;

    if (n == 3) {
        line.pb(points[0]);
        line.pb(points[1]);
        dir = points[1] - points[0];
        other = points[2];
    } else {
        rep(i, 0, 4) rep(j, i+1, 4) rep(l, j+1, 4) {
            vec2 a = points[i], b = points[j], c = points[l];
            if ((b-a).cross(c-a) == 0) {
                each(p, points) {
                    if ((p-a).cross(b-a) == 0) {
                        line.pb(p);
                    } else {
                        other = p;
                    }
                }
                dir = b-a;
                goto done;
            }
        }
        assert(0);
        done:;
        sort(all(line), [&](vec2 a, vec2 b) { return dir.dot(a) < dir.dot(b); });
    }

    double ans = 1e30;

    if (points[k] == other) {
        ans = (line.back() - line[0]).len() + min((other-line.back()).len(), (other-line[0]).len());
    } else {
        rep(t, 0, 2) {
            int i = 0;
            while (line[i] != points[k]) i++;
            int start = i;
            for (; i < sz(line); i++) {
                double alt = 0;
                if (i+1 < sz(line)) {
                    alt += (line.back() - line[i+1]).len() + min((line.back() - other).len(), (line[i+1] - other).len());
                }
                double x = (line[start] - line[0]).len();
                double y = (line[start] - line[i]).len();
                alt += min(x*2 + y + (line[i] - other).len(), y*2 + x + (line[0] - other).len());
                ans = min(ans, alt);
            }
            reverse(all(line));
        }
    }

    deb(line, dir, other);
    cout << ans << '\n';
}