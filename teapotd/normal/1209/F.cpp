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

constexpr int INF = 1e9;
constexpr int MOD = 1e9+7;

vector<vector<Pii>> G;

void addEdge(int s, int t, int dist) {
    while (dist >= 10) {
        int v = sz(G);
        G.emplace_back();
        G[v].pb({t, dist%10});
        t = v;
        dist /= 10;
    }
    G[s].pb({t, dist});
}

void run() {
    int n, m; cin >> n >> m;
    G.resize(n);

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        addEdge(a-1, b-1, i+1);
        addEdge(b-1, a-1, i+1);
    }

    Vi lvl(sz(G), INF), dist(sz(G), INF), ans(sz(G), -1);
    Vi cur, last;
    lvl[0] = dist[0] = ans[0] = 0;
    cur.pb(0);

    for (int i = 1; !cur.empty(); i++) {
        cur.swap(last);
        cur.clear();

        each(v, last) each(e, G[v]) {
            int alt = dist[v]*10 + e.y;
            if (lvl[e.x] >= i && dist[e.x] > alt) {
                if (lvl[e.x] > i) {
                    lvl[e.x] = i;
                    cur.pb(e.x);
                }
                dist[e.x] = alt;
                ans[e.x] = int((ll(ans[v])*10 + e.y) % MOD);
            }
        }

        sort(all(cur), [&](int l, int r) { return dist[l] < dist[r]; });

        int comp = -1, tmp = -1;
        each(v, cur) {
            if (dist[v] != tmp) {
                tmp = dist[v];
                comp++;
            }
            dist[v] = comp;
        }
    }

    rep(i, 1, n) {
        cout << ans[i] << '\n';
    }
}