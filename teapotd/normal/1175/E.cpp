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

constexpr int MAX_V = 5e5+5;

void run() {
    int n, m; cin >> n >> m;
    vector<Vi> inters(MAX_V);

    rep(i, 0, n) {
        int b, e; cin >> b >> e;
        inters[b].pb(e);
    }

    int lvl = uplg(n)+1;
    vector<Vi> jmp(lvl, Vi(MAX_V));
    int best = -1;

    rep(i, 0, MAX_V) {
        each(e, inters[i]) best = max(best, e);
        jmp[0][i] = max(best, i);
    }

    rep(i, 1, lvl) {
        rep(j, 0, MAX_V) {
            jmp[i][j] = jmp[i-1][jmp[i-1][j]];
        }
    }

    rep(i, 0, m) {
        int b, e; cin >> b >> e;
        int ans = 0;

        if (jmp[lvl-1][b] < e) {
            cout << -1 << '\n';
            continue;
        }

        for (int bit = lvl-1; bit >= 0; bit--) {
            if (jmp[bit][b] < e) {
                b = jmp[bit][b];
                ans |= 1<<bit;
            }
        }

        cout << ans+1 << '\n';
    }
}