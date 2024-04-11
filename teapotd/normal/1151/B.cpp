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
    vector<Vi> elems(n, Vi(m));
    each(r, elems) each(e, r) cin >> e;

    int col = 0;
    each(r, elems) col ^= r[0];

    if (col == 0) {
        rep(i, 0, n) {
            rep(j, 1, m) {
                if (elems[i][0] != elems[i][j]) {
                    cout << "TAK\n";
                    rep(k, 0, n) cout << (i == k ? j+1 : 1) << ' ';
                    cout << endl;
                    return;
                }
            }
        }

        cout << "NIE\n";
        return;
    }

    cout << "TAK\n";
    rep(i, 0, n) cout << 1 << ' ';
    cout << endl;
}