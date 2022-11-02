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

void ans(bool win) {
    cout << (win ? "sjfnb" : "cslnb") << endl;
    exit(0);
}

void run() {
    int n; cin >> n;
    Vi elems(n);
    each(e, elems) cin >> e;

    if (n == 1) {
        ans(elems[0] % 2);
    }

    bool all0 = 1;
    each(e, elems) if (e) {
        all0 = 0;
        break;
    }

    if (all0) {
        ans(0);
    }

    sort(all(elems));

    ll kek = 0;
    rep(i, 1, n) kek += elems[i] == elems[i-1];

    if (kek >= 2) {
        ans(0);
    }

    if (kek == 1) {
        rep(i, 0, n+1) {
            if (elems[i] == elems[i+1]) {
                if (elems[i] == 0 || (i > 0 && elems[i-1] == elems[i]-1)) {
                    ans(0);
                }
                elems[i]--;
                break;
            }
        }
    }

    assert(elems[0] >= 0);
    rep(i, 1, n) assert(elems[i-1] < elems[i]);

    rep(i, 0, n) {
        kek += elems[i]-i;
    }

    ans(kek%2);
}