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
    Vi elems(n);
    each(e, elems) cin >> e;

    Pii great = {elems[0], 0};
    rep(i, 1, n) great = max(great, make_pair(elems[i], i));

    vector<bool> seen(n+5);
    seen[great.x] = 1;

    rep(i, 1, great.y) {
        if (elems[i-1] >= elems[i] || seen[elems[i]]) {
            cout << "NO\n";
            return;
        }
        seen[elems[i]] = 1;
    }

    rep(i, great.y+1, n) {
        if (elems[i-1] <= elems[i] || seen[elems[i]]) {
            cout << "NO\n";
            return;
        }
        seen[elems[i]] = 1;
    }

    cout << "YES\n";
}