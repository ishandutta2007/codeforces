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

struct RMQ {
    using T = Pii;
    T f(T a, T b)  { return min(a, b); }

    vector<vector<T>> s;

    RMQ(const vector<T>& vec = {}) {
        s = {vec};
        for (int h = 1; h <= sz(vec); h *= 2) {
            s.emplace_back();
            auto& prev = s[sz(s)-2];
            rep(i, 0, sz(vec)-h*2+1)
                s.back().pb(f(prev[i], prev[i+h]));
        }
    }

    T query(int b, int e) {
        if (b >= e) return {INT_MAX, -1};
        int k = 31 - __builtin_clz(e-b);
        return f(s[k][b], s[k][e - (1<<k)]);
    }
};

Vi perm;
RMQ rmq;
Vi pre, post, treeAdd, treeMax;
int len, cnt = 0;

void add(int vb, int ve, int val, int i = 1, int b = 0, int e = len) {
    if (vb >= e || b >= ve) return;

    if (b >= vb && e <= ve) {
        treeAdd[i] += val;
        treeMax[i] += val;
        return;
    }

    int m = (b+e) / 2;
    add(vb, ve, val, i*2, b, m);
    add(vb, ve, val, i*2+1, m, e);
    treeMax[i] = max(treeMax[i*2], treeMax[i*2+1]) + treeAdd[i];
}

void enable(int i, int d) {
    add(pre[i], post[i], d);
}

void dfs(int l, int r) {
    if (r-l <= 0) return;
    int m = rmq.query(l, r).y;
    pre[m] = cnt++;
    dfs(l, m);
    dfs(m+1, r);
    post[m] = cnt;
}

void run() {
    int n; cin >> n;
    perm.resize(n);
    pre.resize(n*2);
    post.resize(n*2);

    each(e, perm) cin >> e;
    rep(i, 0, n) perm.pb(perm[i]);

    vector<Pii> tmp;
    rep(i, 0, n*2) tmp.pb({perm[i], i});
    rmq = {tmp};

    dfs(0, n*2);

    for (len = 1; len < cnt; len *= 2);
    treeAdd.resize(len*2);
    treeMax.resize(len*2);

    rep(i, 0, n) {
        enable(i, 1);
    }

    int ans = treeMax[1];
    int shift = 0;

    rep(i, 0, n) {
        enable(i, -1);
        enable(i+n, 1);
        if (treeMax[1] < ans) {
            ans = treeMax[1];
            shift = i+1;
        }
    }

    cout << ans << ' ' << shift << endl;
}