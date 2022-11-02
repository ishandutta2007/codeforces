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
    Vi elems(m);

    each(e, elems) {
        cin >> e;
        e--;
    }

    vector<Vi> events(n);
    ll ans = 0;

    rep(i, 1, m) {
        int a = elems[i-1], b = elems[i];
        if (a == b) continue;
        if (a > b) swap(a, b);
        ans += b-a;
        events[a].pb(b);
        events[b].pb(a);
    }

    rep(i, 0, n) {
        each(e, events[i]) ans -= (e > i);

        ll cur = ans;
        each(e, events[i]) {
            cur -= abs(e-i)-1;
            cur += e + (e < i);
        }
        cout << cur << ' ';

        each(e, events[i]) ans += (e < i);
    }

    cout << '\n';
}