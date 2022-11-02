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

char board[2001][2001];
int n, k;

int dp[2001][2001];
int lex[2001][2001];
bool toRight[2001][2001];

void run() {
    cin >> n >> k;
    rep(i, 0, n) cin >> board[i];

    rep(i, 0, n) rep(j, 0, n) {
        if (i == 0 && j == 0) {
            dp[i][j] = 0;
        } else {
            dp[i][j] = INT_MAX;
        }

        if (i > 0) {
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
        }
        if (j > 0) {
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }

        if (board[i][j] != 'a') {
            dp[i][j]++;
        }
    }

    if (dp[n-1][n-1] <= k) {
        rep(i, 0, n*2-1) cout << 'a';
        cout << endl;
        return;
    }

    lex[n][n] = 0;
    Pii from{0, 0};

    for (int sum = n*2-1; sum >= 0; sum--) {
        vector<pair<Pii, int>> pairs;
        int best = INT_MAX;
        Pii bestPos = {-1,-1};

        rep(i, 0, n) {
            int j = sum-i;
            if (j < 0 || j >= n) continue;

            int better = INT_MAX;
            if (j+1 < n) better = min(better, lex[i][j+1]);

            if (i+1 < n) {
                better = min(better, lex[i+1][j]);
                if (better == lex[i+1][j]) toRight[i][j] = 1;
            }

            pairs.pb({ { board[i][j], better }, i });

            if (dp[i][j] <= k) {
                if (better < best) {
                    best = better;
                    bestPos = {i,j};
                }
            }
        }

        if (best < INT_MAX) {
            from = bestPos;
            if (toRight[bestPos.x][bestPos.y]) from.x++;
            else from.y++;
            break;
        }

        sort(all(pairs));

        Pii last = {-1,-1};
        int ind = 0;

        each(p, pairs) {
            if (p.x != last) {
                ind++;
                last = p.x;
            }
            lex[p.y][sum-p.y] = ind;
        }
    }

    rep(i, 0, from.x+from.y) cout << 'a';

    while (from.x != n-1 || from.y != n-1) {
        cout << board[from.x][from.y];
        if (toRight[from.x][from.y]) from.x++;
        else from.y++;
    }
    cout << board[n-1][n-1] << endl;
}