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

int n, m, fromX, fromY, maxL, maxR;
char board[2001][2001];
int dists[2001][2001];

template<class T>
void eachNeigh(int x, int y, T func) {
    if (x > 0) func(x-1, y);
    if (y > 0) func(x, y-1);
    if (x < n) func(x+1, y);
    if (y < m) func(x, y+1);
}

void run() {
    cin >> n >> m >> fromX >> fromY >> maxL >> maxR;
    rep(i, 0, n) cin >> board[i];
    fromX--; fromY--;

    rep(i, 0, n) rep(j, 0, m) dists[i][j] = INT_MAX;

    priority_queue<pair<int, Pii>> que;
    que.push({ 0, {fromX, fromY} });
    dists[fromX][fromY] = 0;

    while (!que.empty()) {
        auto v = que.top();
        que.pop();
        int x = v.y.x, y = v.y.y;

        eachNeigh(x, y, [&](int i, int j) {
            if (board[i][j] == '*') return;
            int d = abs(y-j) + dists[x][y];
            if (d < dists[i][j]) {
                que.push({ -d, {i, j} });
                dists[i][j] = d;
            }
        });
    }

    int ans = 0;

    rep(i, 0, n) {
        rep(j, 0, m) {
            int d = dists[i][j];
            if (d == INT_MAX) continue;

            int l = max(0, fromY-j);
            int r = max(0, j-fromY);

            d -= l+r;
            l += d/2;
            r += d/2;

            if (l <= maxL && r <= maxR) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}