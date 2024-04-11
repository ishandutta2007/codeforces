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
    int k, n; cin >> n >> k;
    Vi elems(n);
    each(e, elems) cin >> e;

    Vi order(n);
    rep(i, 0, n) order[n-elems[i]] = i;

    Vi prv(n), nxt(n);
    rep(i, 0, n) {
        prv[i] = i-1;
        nxt[i] = i+1;
    }

    bool flip = 0;

    each(pos, order) {
        if (elems[pos] < 0) continue;
        int t = (flip ? -2 : -1);
        flip = !flip;

        int l = prv[pos], r = nxt[pos];
        elems[pos] = t;

        rep(j, 0, k) {
            if (l < 0) break;
            elems[l] = t;
            l = prv[l];
        }

        rep(j, 0, k) {
            if (r >= n) break;
            elems[r] = t;
            r = nxt[r];
        }

        prv[r] = l;
        nxt[l] = r;
    }

    each(e, elems) {
        if (e < 0) cout << -e;
        else cout << "?";
    }
    cout << endl;
}