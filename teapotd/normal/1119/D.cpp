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
    vector<ll> tune(n);
    each(e, tune) cin >> e;

    int q; cin >> q;
    vector<ll> queries(q);
    each(e, queries) {
        ll a, b; cin >> a >> b;
        e = b-a+1;
    }

    Vi order(q);
    iota(all(order), 0);
    sort(all(order), [&](int l, int r) { return queries[l] < queries[r]; });
    sort(all(tune));

    vector<ll> diffs;
    rep(i, 1, n) {
        diffs.pb(tune[i] - tune[i-1]);
    }
    sort(all(diffs));

    int j = 0;
    ll mult = n, add = 0;

    each(i, order) {
        ll& e = queries[i];

        while (j < sz(diffs) && diffs[j] <= e) {
            add += diffs[j];
            mult--;
            j++;
        }

        e = e*mult + add;
    }

    each(e, queries) {
        cout << e << ' ';
    }
    cout << '\n';
}