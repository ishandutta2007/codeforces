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
#define mp make_pair/////////////////////////////////////////////
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
    vector<Pii> inters;

    rep(i, 0, n) {
        int x, s; cin >> x >> s;
        inters.pb({x-s-1, x+s-1});
    }

    each(e, inters) {
        e.x = max(e.x, 0);
    }

    Vi dp(m+1);

    rep(i, 1, sz(dp)) {
        int best = INT_MAX;

        each(e, inters) {
            int minCost = max(0, i-e.y-1);
            int alt = max(minCost, e.x);
            best = min(best, alt);

            int left = e.x-minCost;
            if (left >= 0 && left < i) {
                best = min(best, dp[left]+minCost);
            }

            each(f, inters) {
                if (f.x < i) {
                    alt = dp[f.x] + max(minCost, e.x-f.y-1);
                    best = min(best, alt);
                }
            }
        }

        dp[i] = best;
    }

    cout << dp[m] << endl;
}