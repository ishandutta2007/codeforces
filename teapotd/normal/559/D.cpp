#define _USE_MATH_DEFINES////////////////////////////////////////
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

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

constexpr int MAX_DIST = 100;

using dbl = double;
using vec2 = vec2i;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lattice(vec2 a, vec2 b) {
    return gcd(abs(a.x-b.x), abs(a.y-b.y));
}

void run() {
    int n; cin >> n;
    vector<vec2> elems(n);
    each(e, elems) cin >> e.x >> e.y;

    dbl area = 0, border = 0;

    dbl degenProb = 1;
    rep(i, 0, n) degenProb *= 0.5;

    rep(i, 0, n) {
        vec2 p = elems[i];
        dbl prob = 0.5;

        rep(d, 1, min(MAX_DIST+1, n)) {
            vec2 q = elems[(i+d)%n];
            prob *= 0.5;
            area += dbl(p.cross(q)) * prob;
            border += dbl(lattice(p, q)) * (prob-degenProb);
        }
    }

    deb(area, border);

    dbl tmp = dbl(n*(n+1)/2 + 1);
    rep(i, 0, n) tmp *= 0.5;

    dbl ans = area/2 - border/2;
    ans /= 1-tmp;
    ans++;

    cout << setprecision(10) << ans << endl;
}