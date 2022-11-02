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

    bool operator!=(vec2i r) const {
        return x != r.x || y != r.y;
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
constexpr ll INF = INT64_MAX;

void run() {
    int n; cin >> n;
    vector<vec2> elems(n);

    each(p, elems) {
        cin >> p.x >> p.y;
    }

    vec2 a = elems[0], b, c;
    int ia = 0, ib = -1, ic = -1;
    ll best = INF;

    int i = 0;
    each(e, elems) {
        if (e != a) {
            ll alt = (e-a).len2();
            if (alt < best) {
                best = alt;
                b = e;
                ib = i;
            }
        }
        i++;
    }

    best = INF;

    i = 0;
    each(e, elems) {
        if (e != a && e != b) {
            ll alt = abs((e-a).cross(e-b));
            if (alt > 0 && alt < best) {
                best = alt;
                c = e;
                ic = i;
            }
        }
        i++;
    }

    cout << ia+1 << ' ' << ib+1 << ' ' << ic+1 << endl;
}