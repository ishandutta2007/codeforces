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
        vector<Pii> swaps;
        bool ok = 1;

        Vi sPos[26], tPos[26];

        rep(i, 0, n) {
            sPos[s[i]-'a'].pb(i);
            tPos[t[i]-'a'].pb(i);
        }

        auto mv = [&](int i, int j) {
            swaps.pb({i+1, j+1});
            swap(s[i], t[j]);
            sPos[s[i]-'a'].pb(i);
            tPos[t[j]-'a'].pb(j);
        };

        rep(i, 0, n) {
            if (s[i] == t[i]) continue;
            int c = s[i]-'a';

            while (!sPos[c].empty()) {
                int j = sPos[c].back();
                sPos[c].pop_back();

                if (j > i && s[i] == s[j]) {
                    mv(j, i);
                    break;
                }
            }

            if (s[i] == t[i]) continue;

            while (!tPos[c].empty()) {
                int j = tPos[c].back();
                tPos[c].pop_back();

                if (j > i && s[i] == t[j]) {
                    mv(j, j);
                    mv(j, i);
                    break;
                }
            }

            if (s[i] != t[i]) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            rep(i, 0, n) assert(s[i] == t[i]);
            cout << "Yes\n";
            cout << sz(swaps) << '\n';
            each(m, swaps) cout << m.x << ' ' << m.y << '\n';
        } else {
            cout << "No\n";
        }
    }
}