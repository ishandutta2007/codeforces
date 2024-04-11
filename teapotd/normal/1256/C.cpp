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
    int n, m, d; cin >> m >> n >> d;
    Vi lens(n);
    each(l, lens) cin >> l;

    int tot = accumulate(all(lens), 0);
    int reach = d-1;
    Vi ans(m);

    rep(j, 0, sz(lens)) {
        int l = lens[j];
        int pos = min(reach, m-tot);
        rep(i, 0, l) ans[pos+i] = j+1;
        tot -= l;
        reach = pos+l-1+d;
    }

    if (reach < m) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    each(a, ans) cout << a << ' ';
    cout << '\n';
}