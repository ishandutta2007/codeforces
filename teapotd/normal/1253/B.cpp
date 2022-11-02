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
    Vi evt(n);
    each(e, evt) cin >> e;

    Vi ans, ver(1e6+5), seen(1e6+5);
    int siz = 0, tot = 0, curVer = 1;

    each(e, evt) {
        int id = abs(e)-1;
        siz++;

        if (ver[id] != curVer) {
            ver[id] = curVer;
            seen[id] = 0;
        }

        if (e > 0) {
            if (seen[id] == 0) {
                seen[id]++;
                tot++;
            } else {
                cout << -1 << '\n';
                return;
            }
        } else {
            if (seen[id] == 1) {
                seen[id]++;
                tot--;
            } else {
                cout << -1 << '\n';
                return;
            }
        }

        if (tot == 0) {
            ans.pb(siz);
            siz = 0;
            curVer++;
        }
    }

    if (siz != 0) {
        cout << -1 << '\n';
        return;
    }

    cout << sz(ans) << '\n';
    each(a, ans) cout << a << ' ';
    cout << '\n';
}