#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,tree-vectorize")
#pragma GCC target("popcnt,mmx,sse,sse2,sse3,sse4.1,sse4.2,avx,tune=native")
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

int dp[2][1<<12], add[1<<12], bestAdd[1<<12], rot[1<<12];
int mat[2000][12];

void handle() {
    int n, m; cin >> n >> m;
    rep(i, 0, n) rep(j, 0, m) cin >> mat[j][i];

    Vi maxs(m);
    rep(col, 0, m) rep(i, 0, n) maxs[col] = max(maxs[col], mat[col][i]);

    Vi order(m);
    iota(all(order), 0);
    sort(all(order), [&](int l, int r) { return maxs[l] > maxs[r]; });
    m = min(n, m);

    memset(dp, 0, sizeof(dp));
    memset(rot, 0, sizeof(rot));

    Vi noRot;
    vector<vector<Pii>> subRots;

    rep(mask, 1, 1<<n) if (!rot[mask]) {
        rep(sh, 0, n) {
            int alt = (mask >> sh) | (mask << (n-sh));
            alt &= (1<<n)-1;
            rot[alt] = mask;
        }
        noRot.pb(mask);
    }

    each(mask, noRot) {
        subRots.emplace_back();
        auto& kek = subRots.back();
        for (int here = mask; here > 0; here = (here-1) & mask) {
            kek.pb({ rot[here], rot[here^mask] });
        }
        sort(all(kek));
        kek.erase(unique(all(kek)), kek.end());
    }

    rep(col, 0, m) {
        auto &cur = dp[(col+1)%2], &last = dp[col%2];
        memset(bestAdd, 0, sizeof(bestAdd));

        rep(mask, 1, 1<<n) {
            int row = __builtin_ctz(mask);
            int alt = add[mask&(mask-1)] + mat[order[col]][row];
            add[mask] = alt;
            int& out = bestAdd[rot[mask]];
            out = max(out, alt);
        }

        rep(i, 0, sz(noRot)) {
            int mask = noRot[i];
            int best = last[mask];
            each(here, subRots[i]) {
                best = max(best, last[here.y] + bestAdd[here.x]);
            }
            cur[mask] = best;
        }
    }

    cout << dp[m%2][(1<<n)-1] << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) handle();
}