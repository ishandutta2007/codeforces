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
    int n, w; cin >> n >> w;
    vector<ll> ans(w);

    rep(j, 0, n) {
        int l; cin >> l;
        vector<pair<int, Pii>> events;

        rep(i, 0, l) {
            int k; cin >> k;
            events.pb({ i, {k, 1} });
            events.pb({ i+w-l+1, {k, 0} });
        }

        if (l < w) {
            events.pb({ 0, {0, 1} });
            events.pb({ w-l, {0, 0} });
            events.pb({ l, {0, 1} });
            events.pb({ w, {0, 0} });
        }

        sort(all(events));
        multiset<int> avail;
        int last = 0;

        each(e, events) {
            if (e.y.y == 1) {
                avail.insert(e.y.x);
            } else {
                avail.erase(avail.find(e.y.x));
            }

            if (e.x >= 0 && e.x < w && !avail.empty()) {
                int diff = *avail.rbegin() - last;
                ans[e.x] += diff;
                last = *avail.rbegin();
            }
        }
    }

    rep(i, 1, w) ans[i] += ans[i-1];
    each(a, ans) cout << a << ' ';
    cout << endl;
}