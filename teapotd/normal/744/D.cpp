#pragma GCC optimize("Ofast")
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
#define mp make_pair/////////////////////////////////////////////
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
constexpr dbl EPS = 1e-8;

template<class T, class S> struct bvec2 {
    T x, y;
    S operator+(S r) const {return{x+r.x,y+r.y};}
    S operator-(S r) const {return{x-r.x,y-r.y};}
    S operator*(T r) const { return {x*r, y*r}; }
    S operator/(T r) const { return {x/r, y/r}; }
    T len2()     const { return x*x + y*y; }
    dbl len()    const { return sqrt(len2()); }
};

struct vec2d : bvec2<dbl, vec2d> {
    vec2d() : bvec2{0, 0} {}
    vec2d(dbl a, dbl b) : bvec2{a, b} {}
};

using vec2 = vec2d;

struct Event {
    ll ang;
    int color, add;
    bool operator<(const Event& r) const {
        return ang < r.ang;
    }
    DBP(ang, color, add);
};

vector<vec2> elems[2];
vector<pair<vec2, bool>> shuffled;
vector<Event> events;

bool check(vec2 origin, dbl r, bool isRed) {
    int cnt[2] = {isRed, 0}; // 0 = red, 1 = blue
    events.clear();

    rep(t, 0, 2) for (vec2 p : elems[t]) {
        p = p-origin;
        dbl len = p.len();
        if (len < 1e-5 || len >= r*2) continue;

        if (isRed) {
            return 0;
        }

        dbl a = acos(len/(r*2));
        dbl b = atan2(p.y, p.x);

        dbl begin = b-a, end = b+a;
        while (begin > 0) begin -= M_PI*2, end -= M_PI*2;
        while (begin < 0) begin += M_PI*2, end += M_PI*2;

        if (end+EPS > M_PI*2) {
            end -= M_PI*2;
            cnt[t]++;
        }

        ll nBegin = ll(begin*1e17);
        ll nEnd = ll(end*1e17);

        events.pb({nBegin, t, 1});
        events.pb({nEnd, t, -1});
    }

    if (cnt[0] > 0 && cnt[1] == 0) {
        return 1;
    }

    sort(all(events));

    rep(i, 0, sz(events)) {
        auto& e = events[i];
        cnt[e.color] += e.add;
        if (cnt[0] > 0 && cnt[1] == 0) {
            return 1;
        }
    }

    return 0;
}

dbl solve(vec2 p, dbl begin, bool isRed) {
    dbl add = 1e-5;
    while (check(p, begin+add, isRed)) {
        if (begin+add > 1e9) {
            return 2e9;
        }
        add *= 2;
    }

    dbl end = begin+add;

    while (true) {
        dbl err = (end-begin) / max(1.0, begin);
        if (err < 1e-5) break;

        dbl mid = sqrt(begin*end);

        if (check(p, mid, isRed)) {
            begin = mid;
        } else {
            end = mid;
        }
    }

    return sqrt(begin*end);
}

void run() {
    int s[2]; cin >> s[0] >> s[1];

    rep(i, 0, 2) {
        elems[i].resize(s[i]);
        each(e, elems[i]) {
            cin >> e.x >> e.y;
            shuffled.pb({e, !i});
        }
    }

    mt19937 rnd{1337};
    shuffle(all(elems[0]), rnd);
    shuffle(all(elems[1]), rnd);
    shuffle(all(shuffled), rnd);

    dbl ans = 1;

    each(p, elems[0]) {
        dbl alt = 1e18;
        each(q, elems[1]) {
            alt = min(alt, (p-q).len());
        }
        ans = max(ans, alt);
    }

    each(v, shuffled) {
        ans = max(ans, solve(v.x, ans, v.y));
    }

    cout << setprecision(10);

    if (ans > 1e9) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}