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

constexpr int MAX_COLS = 2048;

// Solve system of linear equations over Z_2
// time: O(n^2*m/W), where W is word size
// - A - extended matrix, rows are equations,
//       columns are variables,
//       m-th column is equation result
//       (A[i][j] - i-th row and j-th column)
// - ans - output for variables values
// - m - variable count
// Returns 0 if no solutions found, 1 if one,
// 2 if more than 1 solution exist.
int bitGauss(vector<bitset<MAX_COLS>>& A,
             vector<bool>& ans, int m) {
    Vi col;
    ans.assign(m, 0);

    rep(i, 0, sz(A)) {
        int c = int(A[i]._Find_first());
        if (c >= m) {
            if (c == m) return 0;
            continue;
        }

        rep(k, i+1, sz(A)) if (A[k][c]) A[k]^=A[i];
        swap(A[i], A[sz(col)]);
        col.pb(c);
    }

    for (int i = sz(col); i--;) if (A[i][m]) {
        ans[col[i]] = 1;
        rep(k,0,i) if(A[k][col[i]]) A[k][m].flip();
    }

    return sz(col) < m ? 2 : 1;
}

void handle() {
    int n, m; cin >> n >> m;

    vector<bitset<MAX_COLS>> G(n);
    Vi degs(n);

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        a--; b--;

        G[a].set(b);
        G[b].set(a);

        degs[a]++;
        degs[b]++;
    }

    bool ok = 1;
    
    rep(i, 0, n) if (degs[i] % 2) {
        ok = 0;
        G[i].set(i);
        G[i].set(n);
    }

    if (ok) {
        cout << "1\n";
        rep(i, 0, n) cout << "1 ";
        cout << '\n';
        return;
    }

    vector<bool> ans;
    assert(bitGauss(G, ans, n));

    cout << "2\n";
    rep(i, 0, n) cout << ans[i]+1 << ' ';
    cout << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) handle();
}