#include<bits/stdc++.h>/////////////////////////////////////////
#define deb(...)////////////////////////////////////////////////
#define DBP(...)////////////////////////////////////////////////
#ifdef LOC//////////////////////////////////////////////////////
#include"debuglib.h"////////////////////////////////////////////
#endif//////////////////////////////////////////////////////////
#define x first/////////////////////////////////////////////////
#define y second////////////////////////////////////////////////
#define pb push_back////////////////////////////////////////////
#define sz(x)int((x).size())////////////////////////////////////
#define each(a,x)for(auto&a:(x))////////////////////////////////
#define all(x)(x).begin(),(x).end()/////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)//////////////////////
using namespace std;using ll=int64_t;using Pii=pair<int,int>;///
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio//
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}///
//------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

void run() {
    vector<Pii> points(3);
    each(p, points) cin >> p.x >> p.y;

    sort(all(points), [](Pii l, Pii r) { return l.y < r.y; });

    vector<Pii> clean;

    rep(i, points[0].y, points[1].y) {
        clean.pb({ points[0].x, i });
    }

    rep(i, min(points[0].x, points[1].x), max(points[1].x, points[0].x)+1) {
        clean.pb({ i, points[1].y });
    }

    int fromX = points[2].x;
    fromX = max(fromX, min(points[0].x, points[1].x));
    fromX = min(fromX, max(points[0].x, points[1].x));

    rep(i, points[1].y+1, points[2].y+1) {
        clean.pb({ fromX, i });
    }

    rep(i, min(fromX, points[2].x), max(fromX, points[2].x)+1) {
        if (i != fromX) {
            clean.pb({ i, points[2].y });
        }
    }

    cout << sz(clean) << '\n';
    each(p, clean) cout << p.x << ' ' << p.y << '\n';
}