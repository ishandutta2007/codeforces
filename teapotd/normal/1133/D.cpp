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
    Vi a(n), b(n);
    each(k, a) cin >> k;
    each(k, b) cin >> k;

    vector<Pii> elems;
    int plus = 0;

    rep(i, 0, n) {
        if (a[i] == 0) {
            if (b[i] == 0) plus++;
            continue;
        }

        int g = gcd(abs(a[i]), abs(b[i]));
        int x = b[i]/g, y = a[i]/g;
        if (x < 0) {
            x *= -1;
            y *= -1;
        } else if (x == 0) {
            y = 1;
        }

        elems.pb({x, y});
    }

    int ans = 0;
    sort(all(elems));

    rep(i, 0, sz(elems)) {
        if (i > 0 && elems[i] == elems[i-1]) continue;
        int j = i+1;
        while (j < sz(elems) && elems[j] == elems[i]) j++;
        ans = max(ans, j-i);
    }

    cout << ans+plus << endl;
}