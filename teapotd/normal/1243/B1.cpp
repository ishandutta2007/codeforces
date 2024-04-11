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
    int k; cin >> k;

    while (k--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;

        string kek;
        int nSeen = 0;

        rep(i, 0, n) {
            if (s[i] != t[i]) {
                if (++nSeen > 2) break;
                string alt;
                alt.pb(s[i]);
                alt.pb(t[i]);
                if (nSeen == 2 && alt != kek) {
                    nSeen = 50;
                    break;
                }
                kek = alt;
            }
        }

        if (nSeen == 0 || nSeen == 2) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}