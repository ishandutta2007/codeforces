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

constexpr int MOD = 1e9+7;

void run() {
    int n; cin >> n;
    vector<Pii> inters(n);
    each(e, inters) cin >> e.y >> e.x;

    vector<pair<Pii, int>> events;
    int lastBegin = 0;

    rep(i, 0, n) {
        auto& e = inters[i];
        events.pb({{e.x, 1}, i});
        events.pb({{e.y, 0}, i});
        lastBegin = max(lastBegin, e.x);
    }

    Vi space(n), cnt(n);
    sort(all(events));

    map<int, Pii> cands; // spacePref -> cnt,num

    auto spacePref = [&](int i) { return space[i] - inters[i].y; };

    auto add = [&](int i) {
        Pii& out = cands[spacePref(i)];
        out.x = int((ll(out.x)+cnt[i]) % MOD);
        out.y++;
    };

    auto del = [&](int i) {
        Pii& out = cands[spacePref(i)];
        if (out.y == 1) {
            cands.erase(spacePref(i));
        } else {
            out.x = int((ll(out.x)-cnt[i]+MOD) % MOD);
            out.y--;
        }
    };

    int j = 0;

    each(e, events) {
        if (e.x.y == 1) {
            if (!cands.empty()) {
                auto it = cands.begin();
                space[e.y] = it->x + e.x.x;
                cnt[e.y] = it->y.x;
            } else {
                space[e.y] = e.x.x;
                cnt[e.y] = 1;
            }
        } else {
            while (j < sz(events) && events[j].x.x <= inters[e.y].x) {
                if (events[j].x.y == 0) {
                    del(events[j].y);
                }
                j++;
            }
            add(e.y);
        }
    }

    ll ans = 0, best = 2e9;

    rep(i, 0, n) {
        if (inters[i].y <= lastBegin) continue;

        if (space[i] < best) {
            best = space[i];
            ans = cnt[i];
        } else if (space[i] == best) {
            ans += cnt[i];
        }
    }

    ans %= MOD;
    cout << ans << endl;
}