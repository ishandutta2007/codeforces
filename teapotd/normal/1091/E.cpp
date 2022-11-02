#include<bits/stdc++.h>/////////////////////////////////////////
#define deb(...)////////////////////////////////////////////////
#define DBP(...)////////////////////////////////////////////////
#ifdef LOC//////////////////////////////////////////////////////
#include"debuglib.h"////////////////////////////////////////////
#endif//////////////////////////////////////////////////////////
#define x first/////////////////////////////////////////////////
#define y second////////////////////////////////////////////////
#define pb push_back////////////////////////////////////////////
#define sz(x)int((x).size())////////////////////////////////////
#define each(a,x)for(auto&a:(x))////////////////////////////////
#define all(x)(x).begin(),(x).end()/////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)//////////////////////
using namespace std;using ll=int64_t;using Pii=pair<int,int>;///
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio//
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}///
//------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

struct SegmentTree {
    using T = ll;
    static constexpr T ID = INT_MAX;
    static T merge(T a, T b) { return min(a,b); }

    vector<T> V;
    int len;

    SegmentTree(int n=0, T def=ID){init(n,def);}

    void init(int n, T def) {
        for (len = 1; len < n; len *= 2);
        V.assign(len+n, def);
        V.resize(len*2, ID);
        for (int i = len-1; i > 0; i--) update(i);
    }

    void update(int i) {
        V[i] = merge(V[i*2], V[i*2+1]);
    }

    void set(int i, T val) {
        V[i+=len] = val;
        while ((i/=2) > 0) update(i);
    }

    T query(int begin, int end) {
        begin += len; end += len-1;
        if (begin > end)  return ID;
        if (begin == end) return V[begin];
        T x = merge(V[begin], V[end]);

        while (begin/2 < end/2) {
            if (~begin&1) x = merge(x, V[begin^1]);
            if (end&1)    x = merge(x, V[end^1]);
            begin /= 2; end /= 2;
        }
        return x;
    }
};

constexpr SegmentTree::T SegmentTree::ID;

// ---

int n;
Vi degs;
vector<ll> prefs;
SegmentTree kKek, kZero, kPlus;

int bsDegree(int k, int begin, int end) {
    int end2 = end;

    while (begin+1 < end) {
        int m = (begin+end) / 2;
        if (degs[m] >= k) begin = m;
        else end = m;
    }

    while (begin < end2 && degs[begin] >= k) begin++;
    return begin;
}

ll naiveCompute(int pref, int k) {
    ll ret = ll(k)*(k-1);
    rep(i, 0, pref) ret -= degs[i];
    rep(i, pref, n) ret += min(degs[i], k);
    return ret;
}

ll compute(int pref, int k) {
    ll ret = ll(k)*(k-1) - prefs[pref];

    int div = bsDegree(k, pref, n);
    ret += ll(k) * (div-pref);
    ret += prefs.back() - prefs[div];

#ifdef LOC
    ll alt = naiveCompute(pref, k);
    if (alt != ret) {
        deb(pref, k, div, ret, alt);
        assert(0);
    }
#endif

    return ret;
}

void process() {
    kKek.init(n+1, 0);
    kZero.init(n+1, 0);
    kPlus.init(n+1, 0);

    rep(i, 0, n+1) {
        ll a = compute(i, i), b = compute(i, i+1);
        kKek.set(i, a+i);
        kZero.set(i, a);
        kPlus.set(i, b);
    }
}

bool check(int d) {
    int pos = bsDegree(d, 0, n);

    ll val = kPlus.query(pos, n+1);
    if (val-d < 0) return 0;

    int start = min(d, pos);

    if (start > 0) {
        val = kKek.query(0, start);
        if (val < 0) return 0;
    }

    if (start < pos) {
        val = kZero.query(start, pos);
        if (val+d < 0) return 0;
    }

    return 1;
}

void run() {
    cin >> n;
    degs.resize(n);
    each(d, degs) cin >> d;

    sort(all(degs), [](int l, int r) { return l > r; });

    prefs.pb(0);
    each(d, degs) prefs.pb(prefs.back() + d);

    Vi ans;
    process();

    rep(i, 0, n+1) {
        if ((prefs.back()+i) % 2 == 0) {
            if (check(i)) ans.pb(i);
        }
    }

    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        each(a, ans) cout << a << ' ';
        cout << endl;
    }
}