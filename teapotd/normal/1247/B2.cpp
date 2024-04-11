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

int cnt[int(1e6)+5];
int tot = 0;

void add(int k) {
    tot += (++cnt[k] == 1);
}

void del(int k) {
    tot -= (--cnt[k] == 0);
}

void run() {
    int t; cin >> t;
    Vi elems;

    while (t--) {
        int n, k, d; cin >> n >> k >> d;
        elems.resize(n);
        each(e, elems) cin >> e;

        rep(i, 0, d) {
            add(elems[i]);
        }

        int best = tot;

        rep(i, d, n) {
            add(elems[i]);
            del(elems[i-d]);
            best = min(best, tot);
        }

        rep(i, n-d, n) {
            del(elems[i]);
        }

        cout << best << '\n';
    }
}