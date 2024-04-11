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
    string s; cin >> s;
    int q; cin >> q;

    set<int> pos[26];
    rep(i, 0, sz(s)) {
        pos[s[i]-'a'].insert(i);
    }

    while (q--) {
        int t; cin >> t;

        if (t == 1) {
            string c;
            int i; cin >> i >> c;
            i--;
            pos[s[i]-'a'].erase(i);
            s[i] = c[0];
            pos[s[i]-'a'].insert(i);
        } else {
            int l, r; cin >> l >> r;
            l--;
            int ans = 0;
            each(p, pos) {
                auto it = p.lower_bound(l);
                if (it != p.end() && *it < r) ans++;
            }
            cout << ans << '\n';
        }
    }
}