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

void handle() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = sz(s)-1;

    for (int i = sz(s)-1; i >= 0; i--) {
        if (s[i] == '<') {
            ans = min(ans, sz(s)-i-1);
            break;
        }
    }

    rep(i, 0, sz(s)) {
        if (s[i] == '>') {
            ans = min(ans, i);
            break;
        }
    }

    cout << ans << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) handle();
}