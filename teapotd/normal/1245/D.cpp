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

struct FAU {
    Vi G;
    FAU(int n = 0) : G(n, -1) {}
    int size(int i) { return -G[find(i)]; }
    int find(int i) { return G[i] < 0 ? i : G[i] = find(G[i]); }
    bool join(int i, int j) {
        i = find(i); j = find(j);
        if (i == j) return 0;
        if (G[i] > G[j]) swap(i, j);
        G[i] += G[j]; G[j] = i;
        return 1;
    }
};

void run() {
    int n; cin >> n;
    vector<pair<ll, ll>> coords(n);
    vector<ll> buildCost(n), edgeCost(n);

    each(c, coords) cin >> c.x >> c.y;
    each(v, buildCost) cin >> v;
    each(v, edgeCost) cin >> v;

    vector<pair<ll, Pii>> edges;

    rep(i, 0, n) {
        rep(j, i+1, n) {
            Pii a = coords[i], b = coords[j];
            ll cost = (edgeCost[i]+edgeCost[j]) * ll(abs(a.x-b.x)+abs(a.y-b.y));
            edges.pb({ cost, {i+1, j+1} });
        }
        edges.pb({ buildCost[i], {0, i+1} });
    }

    FAU fau(n+1);
    sort(all(edges));

    ll ans = 0;
    Vi stations;
    vector<Pii> built;

    each(e, edges) if (fau.join(e.y.x, e.y.y)) {
        ans += e.x;
        if (e.y.x == 0) {
            stations.pb(e.y.y);
        } else {
            built.pb(e.y);
        }
    }

    cout << ans << '\n';

    cout << sz(stations) << '\n';
    each(s, stations) cout << s << ' ';
    cout << '\n';

    cout << sz(built) << '\n';
    each(s, built) cout << s.x << ' ' << s.y << '\n';
}