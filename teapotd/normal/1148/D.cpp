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

Vi solve(vector<pair<int, Pii>>& desc) {
    int n = sz(desc);
    set<Pii> avail;

    sort(all(desc), [](pair<int, Pii>& l, pair<int, Pii>& r) { return l.y.x < r.y.x; });

    rep(i, 0, n) {
        auto& e = desc[i];
        avail.insert({ e.y.y, i });
    }

    Vi ret;
    int low = -1e9, j = 0;

    while (true) {
        while (j < n && desc[j].y.x <= low) {
            avail.erase({ desc[j].y.y, j });
            j++;
        }

        if (avail.empty()) {
            break;
        }

        int best = avail.begin()->y;
        avail.erase(avail.begin());

        auto& e = desc[best];
        ret.pb(e.x);
        low = e.y.y;
    }

    return ret;
}

void run() {
    int n; cin >> n;
    vector<Pii> orig;
    vector<pair<int, Pii>> desc, asc;

    rep(i, 0, n) {
        int a, b; cin >> a >> b;
        if (a > b) {
            desc.pb({ i, {a, b} });
        } else {
            asc.pb({ i, {-a, -b} });
        }
        orig.pb({a, b});
    }

    auto v1 = solve(desc), v2 = solve(asc);

    if (sz(v2) > sz(v1)) {
        v1 = v2;
    }

    cout << sz(v1) << '\n';
    each(i, v1) cout << i+1 << ' ';
    cout << endl;

#ifdef LOC
    if (orig[v1[0]].x < orig[v1[0]].y) {
        rep(i, 1, sz(v1)) {
            assert(orig[v1[i]].x < orig[v1[i]].y);
            assert(orig[v1[i-1]].y > orig[v1[i]].x);
        }
    } else {
        rep(i, 1, sz(v1)) {
            assert(orig[v1[i]].x > orig[v1[i]].y);
            assert(orig[v1[i-1]].y < orig[v1[i]].x);
        }
    }

    sort(all(v1));
    assert(unique(all(v1)) == v1.end());
#endif
}