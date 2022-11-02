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
    int n; cin >> n;
    vector<Vi> mat(n, Vi(n));
    each(r, mat) each(k, r) cin >> k;

    Vi perm(n);

    rep(i, 1, n-1) {
        rep(r, 0, n) {
            int cnt = 0;
            rep(c, 0, n) cnt += mat[r][c] == i;
            if (cnt >= 2) {
                perm[r] = i;
                break;
            }
        }
    }

    int k = n-1;
    rep(i, 0, n) {
        if (!perm[i]) {
            perm[i] = k++;
        }
    }

    each(p, perm) {
        cout << p << ' ';
    }
    cout << '\n';
}