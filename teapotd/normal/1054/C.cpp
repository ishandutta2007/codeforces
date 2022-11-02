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

bool G[1000][1000];
bool seen[1000];

int n, post = 1, last = -1;
Vi ans;

void dfs(int i) {
    if (seen[i]) return;
    seen[i] = 1;

    rep(j, 0, n) if (G[j][i]) {
        dfs(j);
    }

    if (last >= 0 && G[last][i]) {
        post++;
    }
    last = i;
    ans[i] = post;
}

void run() {
    cin >> n;
    Vi left(n), right(n);

    each(e, left) cin >> e;
    each(e, right) cin >> e;

    Vi lDec = left, rDec = right;

    rep(k, 1, n) {
        rep(j, k, n) {
            int i = j-k;
            if (lDec[j] > left[i]) {
                G[j][i] = 1;
                lDec[j]--;
            } else if (rDec[i] > right[j]) {
                G[i][j] = 1;
                rDec[i]--;
            }
        }
    }

    ans.resize(n);
    rep(i, 0, n) dfs(i);

    rep(i, 0, n) {
        int l = 0, r = 0;
        rep(j, 0, i) if (ans[j] > ans[i]) l++;
        rep(j, i+1, n) if (ans[j] > ans[i]) r++;

        if (l != left[i] || r != right[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    each(a, ans) cout << a << ' ';
    cout << endl;
}