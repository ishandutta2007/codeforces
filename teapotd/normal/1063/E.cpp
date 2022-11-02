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
    int n; cin >> n;
    Vi perm;
    bool sorted = true;

    rep(i, 0, n) {
        int x; cin >> x;
        perm.pb(x-1);
        if (x != i+1) sorted = false;
    }

    vector<string> board(n, string(n, '.'));

    if (sorted) {
        cout << n << '\n';
        each(row, board) cout << row << '\n';
        return;
    }

    vector<bool> seen(n);
    int r = 0;

    rep(i, 0, n) if (!seen[i]) {
        Vi cycle = {i};
        seen[i] = true;

        for (int j = perm[i]; j != i; j = perm[j]) {
            cycle.pb(j);
            seen[j] = true;
        }

        if (sz(cycle) <= 1) continue;
        deb(cycle);

        if (i > 0) {
            board[r][0] = board[r][cycle[1]] = '/';
            r++;
        }

        rep(j, 1, sz(cycle)) {
            int a = cycle[j], b = cycle[(j+1) % sz(cycle)];
            board[r][a] = board[r][b] = (a < b ? '/' : '\\');
            r++;
        }

        board[r-1][0] = '\\';
    }

    cout << n-1 << '\n';
    each(row, board) cout << row << '\n';
}