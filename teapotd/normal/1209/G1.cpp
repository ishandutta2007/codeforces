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

constexpr int INF = 1e8;
constexpr int MAX_V = 2e5 + 10;

void run() {
    int n, q; cin >> n >> q;
    Vi elems(n);
    each(e, elems) cin >> e;

    assert(q == 0);

    Vi pMin(MAX_V, INF), pMax(MAX_V, -INF);
    rep(i, 0, n) {
        int e = elems[i];
        pMin[e] = min(pMin[e], i);
        pMax[e] = max(pMax[e], i);
    }

    vector<Pii> events;

    rep(i, 0, MAX_V) {
        if (pMin[i] == INF) continue;
        events.pb({ pMin[i], 1 });
        events.pb({ pMax[i]+1, -1 });
    }

    vector<Pii> inters;
    int begin = 0, open = 0;

    sort(all(events));

    each(e, events) {
        open += e.y;
        if (open == 1 && e.y == 1) {
            begin = e.x;
        } else if (open == 0 && e.y == -1) {
            inters.pb({begin, e.x});
        }
    }

    int ans = 0;
    Vi cnt(MAX_V), ver(MAX_V);

    each(e, inters) {
        int best = 0;
        rep(i, e.x, e.y) {
            if (ver[elems[i]] != e.x) {
                ver[elems[i]] = e.x;
                cnt[elems[i]] = 0;
            }
            best = max(best, ++cnt[elems[i]]);
        }
        ans += e.y-e.x-best;
    }

    cout << ans << '\n';
}