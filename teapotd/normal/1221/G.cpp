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

ll G[64], three[25];
int col[64];
bool isBipartite = 1;

/*ll independent(ll mask) {
    if (!mask) return 1;
    int v = __builtin_ctzll(mask);
    ll m1 = mask & (mask-1);
    ll m2 = m1 & ~G[v];
    if (m1 == m2) return independent(m1) * 2;
    return independent(m1) + independent(m2);
}*/

ll independent(ll mask) {
    if (!mask) return 1;
    int ones = 0;

    for (ll tmp = mask; tmp; tmp &= (tmp-1)) {
        int v = __builtin_ctzll(tmp);
        ll neigh = G[v] & mask;
        int s = __builtin_popcountll(neigh);

        if (s == 0) {
            return independent(mask & ~(1ll<<v)) * 2;
        }

        if (s >= 2) {
            ll m1 = mask & ~(1ll<<v);
            ll m2 = m1 & ~G[v];
            return independent(m1) + independent(m2);
        }

        ones++;
    }

    return three[ones/2];
}

void dfs(int v, int c) {
    col[v] = c+1;
    for (ll nei = G[v]; nei; nei &= (nei-1)) {
        int e = __builtin_ctzll(nei);
        if (col[e]) {
            if (col[e]-1 != !c) isBipartite = 0;
        } else {
            dfs(e, !c);
        }
    }
}

void run() {
    int n, m; cin >> n >> m;

    three[0] = 1;
    rep(i, 1, 25) three[i] = three[i-1] * 3;

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a] |= 1ll << b;
        G[b] |= 1ll << a;
    }

    int nConnected = 0, single = 0;
    rep(i, 0, n) {
        if (!col[i]) {
            dfs(i, 0);
            nConnected++;
        }
        single += (G[i] == 0);
    }

    ll ans = 1ll << n;
    ans -= independent((1ll<<n)-1) * 2; // 0 or 2
    ans -= 1ll << nConnected; // 1
    if (isBipartite) ans += 1ll << nConnected; // 0,2
    ans += 2ll << single; // 0,1 or 1,2
    if (m == 0) ans -= 1ll << n; // 0,1,2

    cout << ans << endl;
}