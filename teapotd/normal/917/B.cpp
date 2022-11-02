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

int dp[101][101][26]; // marble1, marble2, letter
int n, m;

vector<vector<Pii>> G;

bool solve(int i, int j, int c) {
    int& ret = dp[i][j][c];
    if (ret) return ret-1;
    ret = 1;

    each(e, G[i]) {
        if (e.y < c) continue;
        if (!solve(j, e.x, e.y)) {
            ret = 2;
            break;
        }
    }

    return ret-1;
}

void run() {
    cin >> n >> m;
    G.resize(n);
    rep(i, 0, m) {
        string chr;
        int a, b; cin >> a >> b >> chr;
        G[a-1].pb({b-1, chr[0]-'a'});
    }

    rep(i, 0, n) {
        rep(j, 0, n) {
            cout << "BA"[solve(i, j, 0)];
        }
        cout << '\n';
    }
}