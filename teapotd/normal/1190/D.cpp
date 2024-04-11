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

struct Fenwick {
    using T = int;
    static const T ID = 0;
    T f(T a, T b)  { return a+b; }

    vector<T> s;
    Fenwick(int n = 0) : s(n, ID) {}

    void modify(int i, T v) {
        for (; i < sz(s); i |= i+1) s[i]=f(s[i],v);
    }

    T query(int i) {
        T v = ID;
        for (; i > 0; i &= i-1) v = f(v, s[i-1]);
        return v;
    }
};

Vi compressVec(vector<int*>& vec) {
    sort(all(vec), [](int* l, int* r) { return *l < *r; });
    Vi old;
    each(e, vec) {
        if (old.empty() || old.back() != *e) old.pb(*e);
        *e = sz(old)-1;
    }
    return old;
}

ll inters(ll k) {
    return k*(k+1) / 2;
}

void run() {
    int n; cin >> n;
    vector<Pii> elems(n);
    each(e, elems) cin >> e.y >> e.x;

    vector<int*> comp;
    each(e, elems) comp.pb(&e.y);
    int xs = sz(compressVec(comp));

    sort(all(elems));
    each(e, elems) swap(e.x, e.y);

    Fenwick tree(xs);
    vector<bool> seen(xs);
    int nSeen = 0;

    ll ans = 0;

    for (int i = sz(elems)-1; i >= 0; i--) {
        if (i+1 < sz(elems) && elems[i].y == elems[i+1].y) {
            continue;
        }

        int j = i;
        while (j >= 0 && elems[j].y == elems[i].y) j--;
        j++;

        rep(k, j, i+1) {
            int e = elems[k].x;
            if (!seen[e]) {
                seen[e] = 1;
                nSeen++;
                tree.modify(e, 1);
            }
        }

        ans += inters(nSeen);
        ans -= inters(tree.query(elems[j].x));
        ans -= inters(nSeen - tree.query(elems[i].x+1));

        rep(k, j, i) {
            ans -= inters(tree.query(elems[k+1].x) - tree.query(elems[k].x+1));
        }
    }

    cout << ans << endl;
}