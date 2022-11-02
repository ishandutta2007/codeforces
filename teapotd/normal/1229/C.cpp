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

void run() {
    int n, m; cin >> n >> m;
    vector<Vi> in(n);
    Vi out(n);

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);
        in[a].pb(b);
        out[b]++;
    }

    ll ans = 0;
    rep(i, 0, n) {
        ans += ll(sz(in[i])) * out[i];
    }

    int q; cin >> q;
    cout << ans << '\n';

    rep(i, 0, q) {
        int v; cin >> v;
        v--;
        ans -= ll(out[v]) * sz(in[v]);

        each(e, in[v]) {
            ans += out[e] - sz(in[e]) - 1;
            out[e]--;
            in[e].pb(v);
            out[v]++;
        }

        in[v].clear();
        cout << ans << '\n';
    }
}