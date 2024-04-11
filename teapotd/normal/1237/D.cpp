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

Vi tree;
int len;

void update(int i, int val) {
    tree[i += len] = val;
    while (i /= 2) tree[i] = min(tree[i*2], tree[i*2+1]);
}

int query(int vb, int ve, int i = 1, int b = 0, int e = len) {
    if (b >= ve || vb >= e) return 1e9;
    if (b >= vb && e <= ve) return tree[i];
    int m = (b+e) / 2;
    return min(query(vb, ve, i*2, b, m), query(vb, ve, i*2+1, m, e));
}

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

    vector<int*> tmp;
    each(e, elems) tmp.pb(&e);
    Vi comp = compressVec(tmp);

    Vi from(sz(comp));

    rep(i, 1, sz(comp)) {
        from[i] = from[i-1];
        while (from[i] < i && comp[from[i]] < (comp[i]+1)/2) {
            from[i]++;
        }
    }

    for (len = 1; len < sz(comp); len *= 2);
    tree.resize(len*2, 1e9);

    rep(j, 0, 3) rep(i, 0, n) elems.pb(elems[i]);

    Vi reach(sz(elems));
    reach.back() = sz(elems);

    for (int i = sz(elems)-2; i >= 0; i--) {
        reach[i] = reach[i+1];
        int e = elems[i];
        update(e, i);
        reach[i] = min(reach[i], query(0, from[e]));
    }

    rep(i, 0, n) {
        int r = reach[i];
        cout << (r < sz(elems) ? r-i : -1) << ' ';
    }

    cout << endl;
}