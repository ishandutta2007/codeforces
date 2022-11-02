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

int n, m;
char board[1001][1001], pattern[1001][1001];

void run() {
    cin >> n >> m;
    rep(i, 0, n) cin >> pattern[i];

    rep(i, 0, n) rep(j, 0, m) board[i][j] = '.';

    rep(i, 0, n-2) rep(j, 0, m-2) {
        bool ok = true;
        rep(a, i, i+3) rep(b, j, j+3) if (a != i+1 || b != j+1) {
            if (pattern[a][b] != '#') {
                ok = false;
                break;
            }
        }

        if (ok) {
            rep(a, i, i+3) rep(b, j, j+3) if (a != i+1 || b != j+1) {
                board[a][b] = '#';
            }
        }
    }

    rep(i, 0, n) rep(j, 0, m) {
        if (board[i][j] != pattern[i][j]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}