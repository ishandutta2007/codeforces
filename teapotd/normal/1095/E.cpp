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

constexpr int INF = 1e8;

void run() {
    int n; cin >> n;
    string str; cin >> str;

    Vi seq, prefMins, sufMins;
    seq.pb(0);
    prefMins.pb(INF);

    each(c, str) {
        seq.pb(seq.back() + (c == '(' ? 1 : -1));
        prefMins.pb(min(prefMins.back(), seq.back()));
        sufMins.pb(seq.back());
    }

    sufMins.pb(INF);
    for (int i = n-1; i >= 0; i--) {
        sufMins[i] = min(sufMins[i], sufMins[i+1]);
    }

    int ans = 0;

    if (seq.back() == 2) {
        rep(i, 0, n) if (str[i] == '(') {
            if (prefMins[i] >= 0 && sufMins[i] >= 2) ans++;
        }
    } else if (seq.back() == -2) {
        rep(i, 0, n) if (str[i] == ')') {
            if (prefMins[i] >= 0 && sufMins[i] >= -2) ans++;
        }
    }

    cout << ans << endl;
}