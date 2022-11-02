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

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void run() {
    int n; cin >> n;
    vector<Vi> elems(n, Vi(n));
    each(row, elems) each(e, row) cin >> e;

    Vi ans(n);

    auto check = [&](int a1) {
        ans[0] = a1;
        rep(i, 1, n) ans[i] = elems[0][i] / a1;

        rep(i, 0, n) rep(j, 0, n) if (i != j) {
            if (ll(ans[i])*ans[j] != elems[i][j]) return;
        }

        each(a, ans) cout << a << ' ';
        cout << endl;
        exit(0);
    };

    int g = elems[0][1];
    rep(i, 2, n) g = gcd(g, elems[0][i]);

    for (int d = 1; d*d <= g; d++) {
        check(d);
        check(g/d);
    }
}