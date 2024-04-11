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

constexpr int MOD = 1e9+7;

ll modInv(ll a, ll m) {
    if (a == 1) return 1;
    return ((a - modInv(m%a, a))*m + 1) / a;
}

struct SegTree {
    vector<ll> sum, mul;
    int len;

    SegTree(int n) {
        for (len = 1; len < n; len *= 2);
        sum.resize(len*2, 0);
        mul.resize(len*2, 1);
    }

    void push(int i) {
        if (mul[i] != 1) {
            rep(j, 0, 2) {
                sum[i*2+j] = sum[i*2+j]*mul[i] % MOD;
                mul[i*2+j] = mul[i*2+j]*mul[i] % MOD;
            }
            mul[i] = 1;
        }
    }

    void update(int i) {
        sum[i] = (sum[i*2] + sum[i*2+1]) % MOD;
    }

    ll getSum(int b, int e, int i = 1, int vb = 0, int ve = -1) {
        if (ve < 0) ve = len;
        if (b >= ve || vb >= e) return 0;
        if (vb >= b && ve <= e) return sum[i];
        int vm = (vb+ve) / 2;
        push(i);
        return (getSum(b, e, i*2, vb, vm) + getSum(b, e, i*2+1, vm, ve)) % MOD;
    }

    void multiply(int b, int e, ll val, int i = 1, int vb = 0, int ve = -1) {
        if (ve < 0) ve = len;
        if (b >= ve || vb >= e) return;

        if (vb >= b && ve <= e) {
            sum[i] = sum[i]*val % MOD;
            mul[i] = mul[i]*val % MOD;
            return;
        }

        int vm = (vb+ve) / 2;
        push(i);
        multiply(b, e, val, i*2, vb, vm);
        multiply(b, e, val, i*2+1, vm, ve);
        update(i);
    }

    void set(int pos, ll val, int i = 1, int vb = 0, int ve = -1) {
        if (ve < 0) ve = len;

        if (i >= len) {
            sum[i] = val % MOD;
            mul[i] = 1;
            return;
        }

        int vm = (vb+ve) / 2;
        push(i);
        if (pos < vm) set(pos, val, i*2, vb, vm);
        else set(pos, val, i*2+1, vm, ve);
        update(i);
    }
};

vector<Vi> G;
vector<ll> vals;
vector<Pii> queries;
Vi pre, post, coeffs, parents;
int cnt;

void dfs(int v) {
    pre[v] = cnt++;
    each(e, G[v]) dfs(e);
    post[v] = cnt;
}

void run() {
    int v1, q; cin >> v1 >> q;
    G.resize(1);
    vals.resize(1, v1);
    parents.resize(1, -1);

    rep(i, 0, q) {
        int t; cin >> t;
        if (t == 1) {
            int p, v; cin >> p >> v;
            queries.pb({1, sz(G)});
            G[p-1].pb(sz(G));
            G.emplace_back();
            vals.pb(v);
            parents.pb(p-1);
        } else {
            int v; cin >> v;
            queries.pb({2, v-1});
        }
    }

    pre.resize(sz(G));
    post.resize(sz(G));
    dfs(0);

    SegTree tree(sz(G));
    tree.set(pre[0], vals[0]);
    coeffs.resize(sz(G), 1);

    each(e, queries) {
        int v = e.y;
        if (e.x == 1) {
            int p = parents[v];
            ll scale = (coeffs[p]+1) * modInv(coeffs[p], MOD) % MOD;
            coeffs[p]++;
            tree.multiply(pre[p], post[p], scale);
            ll tmp = tree.getSum(pre[p], pre[p]+1) * modInv(vals[p], MOD) % MOD;
            tree.set(pre[v], vals[v]*tmp % MOD);
        } else {
            ll ans = tree.getSum(pre[v], post[v]);
            ans *= coeffs[v] * modInv(tree.getSum(pre[v], pre[v]+1), MOD) % MOD;
            ans %= MOD;
            ans = ans*vals[v] % MOD;
            cout << ans << '\n';
        }
    }
}