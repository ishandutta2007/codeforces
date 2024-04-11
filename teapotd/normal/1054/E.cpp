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

using Move = pair<Pii, Pii>;

int n, m;

void simulate(vector<vector<string>>& board, const vector<vector<string>>& expected, vector<Move> moves) {
    rep(i, 0, n) {
        rep(j, 0, m) cerr << board[i][j] << ' ';
        cerr << '\n';
    }
    cerr << '\n';

    each(mv, moves) {
        assert(mv.x != mv.y);

        auto& src = board[mv.x.x][mv.x.y];
        assert(!src.empty());

        char chr = src[0];
        src.erase(src.begin());

        auto& dst = board[mv.y.x][mv.y.y];
        dst.pb(chr);

        deb(mv);
        rep(i, 0, n) {
            rep(j, 0, m) cerr << board[i][j] << ' ';
            cerr << '\n';
        }
        cerr << '\n';
    }

    rep(i, 0, n) {
        rep(j, 0, m) {
            assert(board[i][j] == expected[i][j]);
        }
        cerr << '\n';
    }
    cerr << '\n';
}

vector<Move> getMoves(vector<vector<string>>& board) {
    vector<Move> moves;

    each(c, board[0][0]) {
        if (c == '0') {
            moves.pb({ {0,0}, {1,0} });
            moves.pb({ {1,0}, {0,0} });
        } else {
            moves.pb({ {0,1}, {0,0} });
        }
    }

    each(c, board[0][1]) {
        if (c == '1') {
            moves.pb({ {0,1}, {1,1} });
            moves.pb({ {1,1}, {0,1} });
        } else {
            moves.pb({ {0,0}, {0,1} });
        }
    }

    rep(i, 1, n) {
        each(c, board[i][0]) if (c == '1') moves.pb({ {0,1}, {i,1} });
        each(c, board[i][1]) if (c == '0') moves.pb({ {0,0}, {i,0} });

        each(c, board[i][0]) {
            if (c == '0') {
                moves.pb({ {0,0}, {i,0} });
            } else {
                moves.pb({ {i,1}, {i,0} });
            }
        }

        each(c, board[i][1]) {
            if (c == '1') {
                moves.pb({ {0,1}, {i,1} });
            } else {
                moves.pb({ {i,0}, {i,1} });
            }
        }
    }

    for (int i = n-1; i >= 0; i--) {
        rep(j, 2, m) {
            each(c, board[i][j]) {
                if (c == '0') {
                    moves.pb({ {0,0}, {0,j} });
                } else {
                    moves.pb({ {0,1}, {0,j} });
                }
                if (i > 0) {
                    moves.pb({ {0,j}, {i,j} });
                }
            }
        }
    }

    return moves;
}

void run() {
    cin >> n >> m;
    vector<vector<string>> starting(n, vector<string>(m));
    vector<vector<string>> target(n, vector<string>(m));

    rep(i, 0, n) rep(j, 0, m) cin >> starting[i][j];
    rep(i, 0, n) rep(j, 0, m) cin >> target[i][j], reverse(all(target[i][j]));

    vector<Move> first = getMoves(starting);
    vector<Move> second = getMoves(target);

    reverse(all(first));
    each(mv, first) swap(mv.x, mv.y);
    first.insert(first.end(), all(second));

#ifdef LOC
    rep(i, 0, n) rep(j, 0, m) reverse(all(starting[i][j]));
    simulate(starting, target, first);
#endif

    cout << sz(first) << endl;
    each(mv, first) {
        cout << mv.x.x+1 << ' ' << mv.x.y+1 << ' ' << mv.y.x+1 << ' ' << mv.y.y+1 << '\n';
    }
}