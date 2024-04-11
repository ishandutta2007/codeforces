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
#define mp make_pair/////////////////////////////////////////////
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
    int n; cin >> n;
    string a, b; cin >> a >> b;

    int ans = 0;

    rep(i, 0, n) {
        int j = n-i-1;
        if (i > j) break;

        string up, down;
        up.pb(a[i]);
        down.pb(b[i]);
        
        if (i < j) {
            up.pb(a[j]);
            down.pb(b[j]);
        } else {
            if (up[0] != down[0]) {
                ans++;
            }
            continue;
        }

        sort(all(down));
        int opt = 100;

        rep(i, 0, 26) rep(j, 0, 26) {
            char x = char(i+'a');
            char y = char(j+'a');
            bool ok = 0;

            if (x == y) {
                if (down[0] == down[1]) ok = 1;
            } else {
                if (down[0] == x && down[1] == y) ok = 1;
                if (down[1] == x && down[0] == y) ok = 1;
            }

            if (ok) {
                int alt = (x != up[0]);
                alt += (y != up[1]);
                opt = min(opt, alt);
            }
        }

        ans += opt;
    }

    cout << ans << endl;
}