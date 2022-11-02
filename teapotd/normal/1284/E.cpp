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
    S perp()     const { return {-y,x}; } //90deg

    pair<T, T> yxPair() const { return {y,x}; }

    double angle() const { //[0;2*PI] CCW from OX
        double a = atan2(y, x);
        return (a < 0 ? a+2*M_PI : a);
    }
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

int n;
vector<vec2> elems;

ll solve(vec2 pivot) {
    vector<vec2> angs;

    each(e, elems) {
        if (e == pivot) continue;
        angs.pb(e-pivot);
    }

    ll ret = 0;
    sort(all(angs));

    int left = 0, right = 0;
    ll two = 0;

    auto countLeft = [&](vec2 a) {
        if (a.upper()) return 0;
        a = a*-1;
        int first = int(lower_bound(all(angs), a) - angs.begin());
        return max(first-left, 0);
    };

    auto countRight = [&](vec2 a) {
        if (!a.upper()) return 0;
        a = a*-1;
        int first = int(upper_bound(all(angs), a) - angs.begin());
        return max(right-first, 0);
    };

    rep(i, 0, sz(angs)) {
        vec2 sym = angs[i]*-1;
        bool up = angs[i].upper();
        while (right < sz(angs) && (!up || angs[right] < sym)) {
            two += countLeft(angs[right]);
            right++;
        }
        while (left < i && !up && angs[left] < sym) {
            two -= countRight(angs[left]);
            left++;
        }
        ret += two;
    }

    return ret;
}

void run() {
    cin >> n;
    elems.resize(n);
    each(e, elems) cin >> e.x >> e.y;

    ll ans = 0;

    each(e, elems) {
        ll tri = solve(e);
        ans += tri*3 * (n-4);
    }

    //deb(ans);
    assert(ans%6 == 0);
    ans /= 6;
    cout << ans << endl;
}