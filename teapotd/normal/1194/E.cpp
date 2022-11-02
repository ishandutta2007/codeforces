#define _USE_MATH_DEFINES
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

struct Fenwick {
    using T = int;
    T f(T a, T b)  { return a+b; }

    vector<T> s;
    Fenwick(int n = 0) { init(n); }
    void init(int n)   { s.assign(n, 0); }

    // A[i] = f(A[i], v); time: O(lg n)
    void modify(int i, T v) {
        for (; i < sz(s); i |= i+1) s[i]=f(s[i],v);
    }

    // Get f(A[0], .., A[i-1]); time: O(lg n)
    T query(int i) {
        T v = 0;
        for (; i > 0; i &= i-1) v = f(v, s[i-1]);
        return v;
    }
};

struct Seg {
    int x1, y1, x2, y2;
};

struct Event {
    int type, key, ind; // 0 = begin horizontal, 1 = vertical, 2 = end horizontal

    bool operator<(const Event& r) const {
        return make_pair(key, type) < make_pair(r.key, r.type);
    }
};

void run() {
    int n; cin >> n;
    vector<Seg> ver, hor;
    vector<Event> events;

    rep(i, 0, n) {
        Seg s;
        cin >> s.x1 >> s.y1 >> s.x2 >> s.y2;

        if (s.x1 == s.x2) {
            if (s.y1 > s.y2) swap(s.y1, s.y2);
            events.pb({ 1, s.x1, sz(ver) });
            ver.pb(s);
        } else {
            if (s.x1 > s.x2) swap(s.x1, s.x2);
            events.pb({ 0, s.x1, sz(hor) });
            events.pb({ 2, s.x2, sz(hor) });
            hor.pb(s);
        }
    }

    Vi cnt;
    Fenwick tree;
    sort(all(events));

    ll ans = 0;

    rep(i, 0, sz(hor)) {
        auto& base = hor[i];
        int seenVer = 0;
        tree.init(10005);
        cnt.assign(sz(hor), 0);

        each(e, events) {
            if (e.type == 1) {
                auto& seg = ver[e.ind];
                if (seg.x1 >= base.x1 && seg.x1 <= base.x2 && base.y1 >= seg.y1 && base.y1 <= seg.y2) {
                    seenVer++;
                    tree.modify(seg.y2-base.y1, 1);
                }
            } else if (e.ind != i) {
                auto& seg = hor[e.ind];

                if (seg.y1 > base.y1) {
                    int cur = seenVer - tree.query(seg.y1-base.y1);

                    if (e.type == 0) {
                        cnt[e.ind] = cur;
                    } else {
                        ll add = cur - cnt[e.ind];
                        ans += add*(add-1) / 2;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}