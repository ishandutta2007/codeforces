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

struct Vert {
    Vi E;
    int par{-1}, depth{0};
    int sum, val;
};

vector<Vert> G;

void run() {
    int n; cin >> n;
    G.resize(n);

    rep(i, 1, n) {
        int p; cin >> p;
        G[p-1].E.pb(i);
        G[i].par = p-1;
        G[i].depth = G[p-1].depth+1;
    }

    ll sum = 0;
    each(v, G) cin >> v.sum;

    each(v, G) {
        if (v.depth%2 == 1) {
            int del = G[v.par].sum;
            assert(v.sum == -1);

            if (v.E.empty()) {
                v.val = 0;
            } else {
                int m = INT_MAX;
                each(e, v.E) m = min(m, G[e].sum-del);
                v.val = m;

                if (v.val < 0) {
                    cout << -1 << endl;
                    return;
                }

                each(e, v.E) {
                    G[e].val = G[e].sum-del-v.val;
                }
            }
        }
    }

    G[0].val = G[0].sum;
    each(v, G) sum += v.val;
    cout << sum << endl;
}