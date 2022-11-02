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

struct Elem {
    int x, r, q;
    int compX;
};

struct Fenwick {
    using T = int;
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
};

int n, k;
vector<Elem> elems;
Fenwick tree;

int compressVec(vector<int*>& vec) {
    sort(all(vec), [](int* l, int* r) {
        return *l < *r;
    });
    int last = *vec[0], i = 0;
    each(e, vec) {
        if (*e != last) i++;
        last = *e; *e = i;
    }
    return i+1;
}

void run() {
    cin >> n >> k;
    elems.resize(n);
    each(e, elems) cin >> e.x >> e.r >> e.q;

    vector<int*> toComp;
    each(e, elems) {
        e.compX = e.x;
        toComp.pb(&e.compX);
    }

    tree.init(compressVec(toComp));
    sort(all(elems), [](Elem l, Elem r) { return l.q < r.q; });

    Vi sortedByX(n);
    iota(all(sortedByX), 0);
    sort(all(sortedByX), [](int l, int r) { return elems[l].x < elems[r].x; });

    int iqBegin = 0, iqEnd = 0;
    ll ans = 0;
    int iq = -1, iqPos = 0;

    while (true) {
        while (iqPos < sz(elems) && elems[iqPos].q == iq) iqPos++;
        if (iqPos >= sz(elems)) break;
        iq = elems[iqPos].q;

        while (iqEnd < sz(elems) && elems[iqEnd].q <= iq+k) {
            iqEnd++;
        }
        while (iqBegin < iqEnd && elems[iqBegin].q < iq-k) {
            iqBegin++;
        }

        vector<Pii> events;

        rep(i, iqBegin, iqEnd) {
            events.pb({ elems[i].x, i+1 });
            events.pb({ elems[i].x+elems[i].r+1, -i-1 });
        }

        sort(all(events));

        each(evt, events) {
            int i = abs(evt.y)-1;
            auto& e = elems[i];

            tree.modify(e.compX, evt.y < 0 ? -1 : 1);

            if (evt.y > 0 && e.q == iq) {
                int from = *lower_bound(all(sortedByX), e.x-e.r, [](int l, int r) {
                    return elems[l].x < r;
                });

                ans += tree.query(e.compX+1) - tree.query(elems[from].compX) - 1;
            }
        }
    }

    cout << ans << endl;
}