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

int inds[int(1e7+1)];

void run() {
    int n; cin >> n;
    int M = 0;

    pair<ll, Pii> ans = {INT64_MAX, {0,0}};

    rep(i, 0, n) {
        int k; cin >> k;
        if (inds[k]) {
            pair<ll, Pii> alt = {k, {inds[k], i+1}};
            ans = min(ans, alt);
        } else {
            inds[k] = i+1;
        }
        M = max(M, k+1);
    }

    rep(d, 1, M) {
        Pii a = {INT_MAX, INT_MAX}, b = {INT_MAX, INT_MAX};

        for (int k = d; k <= M; k += d) {
            int i = inds[k];
            if (!i) continue;
            Pii alt = {k, i};
            if (alt < a) {
                b = a;
                a = alt;
            } else {
                b = min(b, alt);
            }
        }

        if (a.x != INT_MAX && b.x != INT_MAX) {
            pair<ll, Pii> alt = {ll(a.x)*b.x/d, {a.y, b.y}};
            ans = min(ans, alt);
        }
    }

    if (ans.y.x > ans.y.y) swap(ans.y.x, ans.y.y);
    cout << ans.y.x << ' ' << ans.y.y << endl;
}