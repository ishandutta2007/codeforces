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

int check(vector<Vi>& ans) {
    int ret = 1e9;
    rep(i, 0, sz(ans)) rep(j, 0, sz(ans)) {
        if (i == j) continue;
        int alt = 0;
        each(a, ans[i]) each(b, ans[j]) alt += a < b;
        ret = min(ret, alt);
    }
    return ret;
}

void run() {
    int n; cin >> n;

    vector<Vi> ans(n, Vi(n));

    rep(i, 0, n) {
        rep(j, 0, n) {
            if (i%2 == 0) {
                ans[j][i] = n*i + j + 1;
            } else {
                ans[j][i] = n*i + n - j;
            }
        }
    }

    each(r, ans) {
        each(k, r) cout << k << ' ';
        cout << '\n';
    }

    //int got = check(ans);
    //int expected = n*n / 2;
    //deb(n, got, expected);
}