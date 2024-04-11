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

struct Fenwick {
    using T = int;
    T f(T a, T b)  { return a+b; }

    vector<T> s;
    Fenwick(int n = 0) : s(n, 0) {}

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

    // Find smallest i such that
    // f(A[0],...,A[i-1]) >= val; time: O(lg n)
    // Prefixes must have non-descreasing values.
    int lowerBound(T val) {
        if (val <= 0) return 0;
        int i = -1, mask = 1;
        while (mask <= sz(s)) mask *= 2;
        T off = 0;

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

Vi compressVec(vector<int*>& vec) {
    sort(all(vec), [](int* l, int* r) { return *l < *r; });
    Vi old;
    each(e, vec) {
        if (old.empty() || old.back() != *e) old.pb(*e);
        *e = sz(old)-1;
    }
    return old;
}

void run() {
    int n; cin >> n;
    Vi elems(n);
    each(e, elems) cin >> e;

    vector<int*> comp;
    each(e, elems) comp.pb(&e);
    Vi orig = compressVec(comp);

    vector<Vi> pos(sz(orig));
    rep(i, 0, n) {
        pos[elems[i]].pb(i);
    }

    each(p, pos) {
        reverse(all(p));
    }

    int m; cin >> m;
    vector<vector<Pii>> queries(n+1); // len -> (pos, ind)
    Vi ans(m);

    rep(i, 0, m) {
        int len, p; cin >> len >> p;
        queries[len].pb({p-1, i});
    }

    Vi sorted = elems;
    sort(all(sorted));
    reverse(all(sorted));

    Fenwick tree(n);

    rep(len, 1, n+1) {
        int p = pos[sorted[len-1]].back();
        pos[sorted[len-1]].pop_back();
        tree.modify(p, 1);

        each(q, queries[len]) {
            int ind = tree.lowerBound(q.x+1)-1;
            ans[q.y] = orig[elems[ind]];
        }
    }

    each(a, ans) {
        cout << a << '\n';
    }
}