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

void run() {
    int z; cin >> z;

    while (z--) {
        string s; cin >> s;
        int cnt[26] = {0};
        each(c, s) cnt[c-'a']++;

        vector<string> parts;

        rep(i, 0, 26) {
            if (cnt[i] > 0) {
                parts.pb(string(cnt[i], char('a'+i)));
            }
        }

        string t;

        if (sz(parts) == 1) {
            t = parts[0];
        } else if (sz(parts) == 3) {
            if (parts[1][0]-parts[0][0] < parts[2][0]-parts[1][0]) {
                swap(parts[0], parts[2]);
            }
            t = parts[1] + parts[0] + parts[2];
        } else {
            for (int i = 1; i < sz(parts); i += 2) {
                t += parts[i];
            }
            for (int i = 0; i < sz(parts); i += 2) {
                t += parts[i];
            }
        }

        bool ok = 1;
        rep(i, 1, sz(t)) {
            if (abs(t[i-1]-t[i]) == 1) {
                ok = 0;
                break;
            }
        }

        if (ok) cout << t << '\n';
        else cout << "No answer\n";
    }
}