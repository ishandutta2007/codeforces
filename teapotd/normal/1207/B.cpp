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
    int n, m; cin >> n >> m;
    vector<Vi> mat(n, Vi(m));
    each(row, mat) each(k, row) cin >> k;

    vector<Pii> steps;
    bool cont = 1;

    auto put = [&](int i, int j) {
        if (i < 0 || j < 0 || i+1 >= n || j+1 >= m) return 0;
        if (!mat[i][j] || !mat[i+1][j] || !mat[i][j+1] || !mat[i+1][j+1]) return 0;
        mat[i][j] = mat[i+1][j] = mat[i][j+1] = mat[i+1][j+1] = 2;
        steps.pb({i, j});
        return 1;
    };

    while (cont) {
        cont = 0;
        rep(i, 0, n) rep(j, 0, m) if (mat[i][j] == 1) {
            if (!put(i, j) && !put(i-1, j) && !put(i, j-1) && !put(i-1, j-1)) {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << sz(steps) << '\n';
    each(s, steps) cout << s.x+1 << ' ' << s.y+1 << '\n';
}