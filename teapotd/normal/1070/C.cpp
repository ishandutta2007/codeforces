#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

struct Fenwick {
    using T = ll;
    const T ID = 0;
    T f(T a, T b)  { return a+b; }

    vector<T> s;
    Fenwick(int n = 0) { init(n); }
    void init(int n)   { s.assign(n, ID); }

    void modify(int i, T v) {
        for (; i < sz(s); i |= i+1) s[i]=f(s[i],v);
    }

    T query(int i) {
        T v = ID;
        for (; i > 0; i &= i-1) v = f(v, s[i-1]);
        return v;
    }

    int lowerBound(T val) {
        if (val <= ID) return 0;
        int i = -1, mask = 1;
        while (mask <= sz(s)) mask *= 2;
        T off = ID;

        while (mask /= 2) {
            int k = mask+i;
            if (k < sz(s)) {
                T x = f(off, s[k]);
                if (val > x) i=k, off=x;
            }
        }
        return i+2;
    }
};

struct Plan {
    int begin, end, avail, price;

    bool operator<(const Plan& r) const {
        return price < r.price;
    }
};

void run() {
    int n, k, m; cin >> n >> k >> m;
    vector<Plan> plans(m);

    each(p, plans) {
        cin >> p.begin >> p.end >> p.avail >> p.price;
        p.begin--;
    }

    sort(all(plans));
    vector<Pii> events;

    rep(i, 0, m) {
        auto& p = plans[i];
        events.pb({ p.begin, i+1 });
        events.pb({ p.end, -i-1 });
    }

    sort(all(events));

    int j = 0;
    Fenwick avail(m), prices(m);

    ll ans = 0;

    rep(i, 0, n) {
        while (j < sz(events) && events[j].x <= i) {
            int sign = (events[j].y > 0 ? 1 : -1);
            int id = abs(events[j].y) - 1;
            auto& plan = plans[id];

            avail.modify(id, sign*plan.avail);
            prices.modify(id, ll(sign)*plan.avail*plan.price);
            j++;
        }

        int pref = avail.lowerBound(k)-1;
        ans += prices.query(pref);
        if (pref < m) ans += plans[pref].price * (k - avail.query(pref));
    }

    cout << ans << endl;
}