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
    int k, n; cin >> n >> k;
    vector<Pii> segs(n);
    each(s, segs) cin >> s.x >> s.y;

    vector<Vi> add(2e5+5), del(2e5+5);

    rep(i, 0, n) {
        Pii s = segs[i];
        add[s.x].pb(i);
        del[s.y].pb(i);
    }

    vector<bool> active(n, 1);
    set<Pii> vis;
    Vi ans;

    rep(pos, 0, sz(add)) {
        each(i, add[pos]) {
            assert(active[i]);
            vis.insert({segs[i].y, i});
        }

        while (sz(vis) > k) {
            Pii best = *vis.rbegin();
            active[best.y] = 0;
            vis.erase({segs[best.y].y, best.y});
            ans.pb(best.y);
        }

        each(i, del[pos]) {
            if (active[i]) {
                vis.erase({segs[i].y, i});
            }
        }
    }

    sort(all(ans));
    cout << sz(ans) << '\n';
    each(a, ans) cout << a+1 << ' ';
    cout << '\n';
}