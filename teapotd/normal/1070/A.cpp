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
    int d, s; cin >> d >> s;

    Vi prev, digit, rem, sum;
    queue<int> que;
    vector<vector<bool>> seen(d, vector<bool>(s+1));

    rep(c, 0, 10) {
        if (seen[c%d][c]) continue;
        seen[c%d][c] = 1;
        que.push(sz(prev));
        prev.pb(-1);
        digit.pb(c);
        rem.pb(c % d);
        sum.pb(c);
    }

    while (!que.empty() && clock() < ll(2.5*CLOCKS_PER_SEC)) {
        int i = que.front();
        que.pop();

        if (sum[i] == s && rem[i] == 0) {
            Vi digits;
            while (i != -1) {
                digits.pb(digit[i]);
                i = prev[i];
            }

            while (!digits.empty()) {
                cout << digits.back();
                digits.pop_back();
            }
            return;
        }

        rep(c, 0, 10) {
            int r = (rem[i]*10 + c) % d;
            int a = sum[i] + c;
            if (a > s || seen[r][a]) continue;
            seen[r][a] = 1;

            que.push(sz(prev));
            prev.pb(i);
            digit.pb(c);
            rem.pb((rem[i]*10 + c) % d);
            sum.pb(a);
        }
    }

    cout << -1 << endl;
}