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
    int num; cin >> num;
    int n = num;
    vector<Pii> seq;

    for (int i = 2; i*i <= n; i++) {
        int p = 0;
        while (n%i == 0) {
            n /= i;
            p++;
        }
        if (p > 0) seq.pb({ i, p });
    }

    if (n > 1) seq.pb({ n, 1 });

    int ans = num, minSteps = 0;
    int steps = 0;
    bool mult = 0;

    while (1) {
        int most = 0;
        each(p, seq) most = max(most, p.y);

        if (most <= 1) break;

        each(p, seq) {
            if (p.y%2) {
                p.y++;
                mult = 1;
            }
        }

        each(p, seq) p.y /= 2;
        steps++;

        int alt = 1;
        each(p, seq) rep(i, 0, p.y) alt *= p.x;

        if (alt < ans) {
            ans = alt;
            minSteps = steps+mult;
        }
    }
    
    cout << ans << ' ' << minSteps << endl;
}