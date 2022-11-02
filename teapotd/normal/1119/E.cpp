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

    ll ans = 0;
    int j = 0;

    rep(i, 0, n) {
        while (elems[i] > 0) {
            j = max(j, i);

            if (i == j) {
                int k = elems[i] / 3;
                elems[i] -= k*3;
                ans += k;
                j++;
            }

            while (j < sz(elems) && elems[j] < 2) {
                j++;
            }
            if (j >= sz(elems)) break;

            int k = min(elems[j]/2, elems[i]);
            ans += k;
            elems[i] -= k;
            elems[j] -= k*2;
        }
    }

    cout << ans << endl;
}