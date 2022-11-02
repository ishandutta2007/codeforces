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

constexpr int MOD = 1e9+7;

ll modPow(ll a, ll e, ll m) {
    ll t = 1 % m;
    while (e) {
        if (e % 2) t = t*a % m;
        e /= 2; a = a*a % m;
    }
    return t;
}

struct Zp {
    ll x;
    Zp() {}
    Zp(ll a) : x(a%MOD) { if (x < 0) x += MOD; }
    #define OP(c,d) Zp& operator c##=(Zp r) { x = x d; return *this; } Zp operator c(Zp r) const { Zp t = *this; return t c##= r; }
    OP(+, +r.x - MOD*(x+r.x >= MOD));
    OP(-, -r.x + MOD*(x-r.x < 0));
    OP(*, *r.x % MOD);
    OP(/, *r.inv().x % MOD);
    Zp inv() const { return pow(MOD-2); }
    Zp pow(ll e) const { return modPow(x,e,MOD); }
    void print() { cerr << x; }
};

constexpr int MAX_N = 7;

struct State {
    Zp prob;
    char G[MAX_N][MAX_N];
    char match1[MAX_N], match2[MAX_N], dfsVert[MAX_N], dfsEdge[MAX_N];
    char dfsDepth, last, more;
    int16_t seen;
};

Zp probs[MAX_N][MAX_N];
Zp ans;
int n, branches;

void solve(State& st) {
    branches++;
    while (true) {
        if (st.dfsDepth == -1) {
            if (++st.last == n) {
                if (st.more) {
                    st.last = st.more = 0;
                } else {
                    rep(i, 0, n) if (st.match1[i] == -1) return;
                    ans += st.prob;
                    return;
                }
            }

            int v = st.last;
            if (v == 0) st.seen = 0;
            if (st.match1[v] >= 0) continue;

            st.dfsDepth = 0;
            st.dfsVert[0] = char(v);
            st.dfsEdge[0] = 0;
            st.seen |= int16_t(1<<v);
        }

        int d = st.dfsDepth;
        int v = st.dfsVert[d];
        int e = st.dfsEdge[d]++;

        if (e >= n) {
            st.dfsDepth--;
            continue;
        }

        int u = st.match2[e];

        if (u != -1 && ((st.seen >> u) & 1)) {
            continue;
        }

        if (st.G[v][e] == 2) {
            State cp = st;
            cp.G[v][e] = 0;
            cp.prob *= Zp(1)-probs[v][e];
            solve(cp);
            st.G[v][e] = 1;
            st.prob *= probs[v][e];
        } else if (st.G[v][e] == 0) {
            continue;
        }

        if (u == -1) {
            for (; d >= 0; d--) {
                v = st.dfsVert[d];
                e = st.dfsEdge[d]-1;
                st.match1[v] = char(e);
                st.match2[e] = char(v);
            }
            st.dfsDepth = -1;
            st.more = 1;
            continue;
        }

        if (!((st.seen >> u) & 1)) {
            st.dfsVert[d+1] = char(u);
            st.dfsEdge[d+1] = 0;
            st.seen |= int16_t(1<<u);
            st.dfsDepth++;
        }
    }
}

void run() {
    cin >> n;
    rep(i, 0, n) rep(j, 0, n) {
        int k; cin >> k;
        probs[i][j] = Zp(k) / 100;
    }

    State st;
    st.prob = 1;
    st.dfsDepth = -1;
    st.last = -1;
    st.more = 0;
    rep(i, 0, n) {
        rep(j, 0, n) st.G[i][j] = 2;
        st.match1[i] = st.match2[i] = -1;
    }

    solve(st);
    cout << ans.x << endl;
    deb(branches);
}