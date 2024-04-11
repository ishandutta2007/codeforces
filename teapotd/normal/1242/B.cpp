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
    vector<Vi> G(n);

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<bool> taken(n);
    Vi cnt(n);
    set<Pii> best;
    int ans = 0;

    rep(i, 0, n) {
        best.insert({0, i});
    }

    rep(i, 0, n) {
        Pii v = *best.begin();
        best.erase(best.begin());

        if (i > 0 && v.x == i) {
            ans++;
        }

        taken[v.y] = 1;

        each(e, G[v.y]) {
            if (taken[e]) continue;
            best.erase({cnt[e], e});
            cnt[e]++;
            best.insert({cnt[e], e});
        }
    }

    cout << ans << '\n';
}