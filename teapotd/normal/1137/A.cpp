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
    vector<Vi> rows(n, Vi(m)), cols(m, Vi(n));

    rep(i, 0, n) rep(j, 0, m) {
        cin >> elems[i][j];
        cols[j][i] = rows[i][j] = elems[i][j];
    }

    each(r, rows) {
        sort(all(r));
        r.erase(unique(all(r)), r.end());
    }
    each(r, cols) {
        sort(all(r));
        r.erase(unique(all(r)), r.end());
    }

    rep(i, 0, n) {
        rep(j, 0, m) {
            int mid = elems[i][j];
            int p1 = int(lower_bound(all(rows[i]), mid) - rows[i].begin());
            int p2 = int(lower_bound(all(cols[j]), mid) - cols[j].begin());
            int p = max(p1, p2);
            cout << max(rows[i].size()-p1+p, cols[j].size()-p2+p) << ' ';
        }
        cout << '\n';
    }
}