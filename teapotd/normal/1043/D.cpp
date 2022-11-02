#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

void run() {
    int n, m; cin >> n >> m;
    vector<Vi> perms(m, Vi(n));

    each(p, perms) each(c, p) {
        cin >> c;
        c--;
    }

    vector<Vi> pos(m, Vi(n));
    rep(i, 0, m) rep(j, 0, n) pos[i][perms[i][j]] = j;

    ll ans = 0;
    Vi cur(m);

    for (int i = 0; i < n;) {
        rep(k, 0, m) cur[k] = pos[k][perms[0][i]];

        while (1) {
            bool ok = 1;

            rep(k, 0, m) {
                cur[k]++;
                if (cur[k] >= n) {
                    ok = 0;
                    break;
                }

                if (perms[0][cur[0]] != perms[k][cur[k]]) {
                    ok = 0;
                    break;
                }
            }

            if (!ok) break;
        }

        ll len = cur[0]-i;
        i = cur[0];
        ans += len*(len+1)/2;

        deb(i, len);
    }

    cout << ans << endl;
}