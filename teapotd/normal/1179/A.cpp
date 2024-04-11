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
    int n, q; cin >> n >> q;
    deque<int> elems(n);
    each(e, elems) cin >> e;

    vector<Pii> ans(n);

    rep(i, 0, n) {
        int a = elems[0], b = elems[1];
        ans[i] = {a, b};
        elems.pop_front();
        elems.pop_front();
        elems.push_front(max(a, b));
        elems.push_back(min(a, b));
    }

    rep(j, 0, q) {
        ll m; cin >> m;
        m--;
        if (m < n) {
            cout << ans[m].x << ' ' << ans[m].y << '\n';
        } else {
            int i = int((m-n) % (n-1) + 1);
            cout << elems[0] << ' ' << elems[i] << '\n';
        }
    }
}