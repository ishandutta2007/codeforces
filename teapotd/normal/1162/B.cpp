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
    vector<Vi> A(n, Vi(m)), B(n, Vi(m));

    rep(i, 0, n) rep(j, 0, m) cin >> A[i][j];

    rep(i, 0, n) rep(j, 0, m) {
        cin >> B[i][j];
        if (A[i][j] > B[i][j]) swap(A[i][j], B[i][j]);
    }

    bool ok = 1;

    rep(i, 0, n) rep(j, 0, m) {
        if (i > 0 && A[i-1][j] >= A[i][j]) ok = 0;
        if (j > 0 && A[i][j-1] >= A[i][j]) ok = 0;
        if (i > 0 && B[i-1][j] >= B[i][j]) ok = 0;
        if (j > 0 && B[i][j-1] >= B[i][j]) ok = 0;
    }

    cout << (ok ? "Possible\n" : "Impossible\n");
}