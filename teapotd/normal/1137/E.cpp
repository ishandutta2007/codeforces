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

constexpr ll INF = 2e18;

struct Hull {
    static bool modeQ; // Toggles operator< mode

    struct Line {
        mutable ll a, b, end;

        ll intersect(const Line& r) const {
            if (a==r.a) return b > r.b ? INF : -INF;
            ll u = b-r.b, d = r.a-a;
            return u/d + ((u^d) >= 0 || !(u%d));
        }
        
        bool operator<(const Line& r) const {
            return modeQ ? end < r.end : a < r.a;
        }

        ll eval(ll x) const { return a*x+b; }
    };

    multiset<Line> S;
    map<ll, pair<ll, ll>> points;
    Hull() { S.insert({ 0, -INF, INF }); }

    void savePoint(multiset<Line>::iterator it, ll x) {
        bool ok = points.count(x);
        auto& p = points[x];
        auto alt = make_pair(it->eval(x), it->a);
        if (!ok || p < alt) p = alt;
    }

    bool update(multiset<Line>::iterator it) {
        auto cur = it++; cur->end = INF;
        if (it == S.end()) return false;
        cur->end = cur->intersect(*it);
        savePoint(it, cur->end-1);
        return cur->end >= it->end;
    }

    void insert(ll a, ll b) {
        auto it = S.insert({ a, b, INF });
        while (update(it)) it = --S.erase(++it);
        rep(i, 0, 2)
            while (it != S.begin() && update(--it))
                update(it = --S.erase(++it));
    }

    pair<ll, int> query(ll x) {
        modeQ = 1;
        auto l = *S.upper_bound({ 0, 0, x });
        modeQ = 0;

        auto p = make_pair(l.eval(x), l.a);
        if (points.count(x)) p = max(p, points[x]);
        return p;
    }
};

bool Hull::modeQ = false;

// ---

void run() {
    int n, m;
    cin >> n >> m;

    Hull hull;
    ll a = 0, b = 0;
    ll first = 0, last = n-1;
    hull.insert(0, 0);

    rep(i, 0, m) {
        int t; cin >> t;

        if (t == 1) {
            ll k; cin >> k;
            first -= k;
            hull.insert(-first, first*a+b);
        } else if (t == 2) {
            ll k; cin >> k;
            last++;
            hull.insert(-last, last*a+b);
            last += k-1;
        } else if (t == 3) {
            ll add, mult; cin >> add >> mult;
            a += mult;
            b += add - first*mult;
        }

        auto p = hull.query(a);
        ll ind = -p.y-first+1;
        ll val = -p.x+b;
        cout << ind << ' ' << val << '\n';
    }
}