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

using dbl = double;
constexpr dbl eps = 1e-9;
int cmp(dbl a, dbl b) { return (a > b+eps) - (a+eps < b); }

template<class T, class S> struct bvec2 {
    T x, y;
    S operator+(S r) const {return{x+r.x,y+r.y};}
    S operator-(S r) const {return{x-r.x,y-r.y};}
    S operator*(T r) const { return {x*r, y*r}; }
    S operator/(T r) const { return {x/r, y/r}; }
    T dot(S r)   const { return x*r.x+y*r.y; }
    T cross(S r) const { return x*r.y-y*r.x; }
    T len2()     const { return x*x + y*y; }
    dbl len() const { return sqrt(len2()); }
    S perp()     const { return {-y,x}; } //90deg
    dbl angle() const { //[0;2*PI] CCW from OX
        dbl a = atan2(y, x);
        return (a < 0 ? a+2*M_PI : a);
    }
};

struct vec2d : bvec2<dbl, vec2d> {
    vec2d() : bvec2{0, 0} {}
    vec2d(dbl a, dbl b) : bvec2{a, b} {}
    vec2d unit() const { return *this/len(); }
    vec2d rotate(dbl a) const { return {x*cos(a) - y*sin(a), x*sin(a) + y*cos(a)}; }
    bool operator==(vec2d r) const { return !cmp(x, r.x) && !cmp(y, r.y); }
    bool operator<(vec2d r) const {
        int t = cmp(angle(), r.angle());
        return t < 0 || (!t && len2()<r.len2());
    }
    vec2d& operator+=(vec2d r) { return *this = *this + r; }
    vec2d& operator-=(vec2d r) { return *this = *this - r; }
    vec2d& operator*=(dbl r) { return *this = *this * r; }
    vec2d& operator/=(dbl r) { return *this = *this / r; }
};

using vec2 = vec2d;

// Find size of smallest set of points
// such that each arc contains at least one
// of them; time: O(n lg n)
int arcCover(vector<pair<dbl, dbl>>& inters,
             dbl wrap) {
    int n = sz(inters);

    rep(i, 0, n) {
        auto& e = inters[i];
        e.x = fmod(e.x, wrap);
        e.y = fmod(e.y, wrap);
        if (e.x < 0) e.x += wrap, e.y += wrap;
        if (e.x > e.y) e.x += wrap;
        inters.pb({e.x+wrap, e.y+wrap});
    }

    Vi nxt(n);
    deque<dbl> que;
    dbl r = wrap*4;
    sort(all(inters));

    for (int i = n*2-1; i--;) {
        r = min(r, inters[i].y);
        que.push_front(inters[i].x);
        while (!que.empty() && que.back() > r)
            que.pop_back();
        if (i < n) nxt[i] = i+sz(que);
    }

    int a = 0, b = 0;
    do {
        a = nxt[a] % n;
        b = nxt[nxt[b]%n] % n;
    } while (a != b);

    int ans = 0;
    while (b < a+n) {
        b += (nxt[b%n] - b%n);
        ans++;
    }
    return ans;
}

int solve(const vector<vec2>& elems, dbl radius) {
    vector<pair<dbl, dbl>> inters;

    for (vec2 p : elems) {
        dbl a = acos(radius/p.len());
        dbl b = atan2(p.y, p.x);
        inters.pb({b-a, b+a});
    }

    return arcCover(inters, M_PI*2);
}

void run() {
    int n, m; cin >> n >> m;
    vector<vec2> elems(n);

    each(e, elems) {
        int x, y; cin >> x >> y;
        if (!x && !y) {
            cout << 0.0 << '\n';
            return;
        }
        e = {dbl(x), dbl(y)};
    }

    dbl begin = 0, end = 1e18;
    each(e, elems) end = min(end, e.len());

    while (1) {
        dbl err = (end-begin) / max(1.0, begin);
        if (err < 1e-7) break;

        dbl mid = (begin+end) / 2;
        if (solve(elems, mid) <= m) {
            begin = mid;
        } else {
            end = mid;
        }
    }

    cout << (begin+end)/2 << '\n';
}