#define _USE_MATH_DEFINES////////////////////////////////////////
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define mp make_pair/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int n, m;
vector<string> board;
vector<Vi> dists, dists2;

bool check(int maxTime, int toGet) {
    dists2.resize(n);
    rep(i, 0, n) dists2[i].assign(m, -1);

    queue<Pii> que;

    rep(i, 0, n) rep(j, 0, m) {
        if (board[i][j] == 'X' && dists[i][j] >= maxTime) {
            dists2[i][j] = maxTime;
            que.push({i, j});
            toGet--;
        }
    }

    while (!que.empty()) {
        int x = que.front().x, y = que.front().y;
        int d = dists2[x][y];
        que.pop();

        if (d == 1) continue;

        rep(a, -1, 2) {
            rep(b, -1, 2) {
                if (a != 0 || b != 0) {
                    int i = x+a, j = y+b;
                    if (board[i][j] != 'X') continue;
                    if (dists2[i][j] != -1) continue;
                    dists2[i][j] = d-1;
                    toGet--;
                    que.push({i, j});
                }
            }
        }
    }

    return toGet == 0;
}

void run() {
    cin >> n >> m;

    board.pb(string(m+2, '.'));

    rep(i, 0, n) {
        string t; cin >> t;
        board.pb("."+t+".");
    }

    board.pb(string(m+2, '.'));
    n += 2; m += 2;

    dists.resize(n, Vi(m, -1));
    queue<Pii> que;

    rep(i, 0, n) rep(j, 0, m) {
        if (board[i][j] == '.') {
            dists[i][j] = 0;
            que.push({i, j});
        }
    }

    auto relax = [&](int i, int j, int d) {
        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (dists[i][j] == -1) {
            dists[i][j] = d;
            que.push({i, j});
        }
    };

    while (!que.empty()) {
        int x = que.front().x, y = que.front().y;
        int d = dists[x][y]+1;
        que.pop();

        rep(a, -1, 2) {
            rep(b, -1, 2) {
                if (a != 0 || b != 0) {
                    relax(x+a, y+b, d);
                }
            }
        }
    }

    int begin = 1, end = 0;
    int toGet = 0;

    rep(i, 0, n) rep(j, 0, m) {
        if (board[i][j] == 'X') {
            toGet++;
            end = max(dists[i][j]+2, end);
        }
    }

    while (begin+1 < end) {
        int mid = (begin+end) / 2;
        if (check(mid, toGet)) {
            begin = mid;
        } else {
            end = mid;
        }
    }

    int answer = begin;
    cout << answer-1 << '\n';

    rep(i, 1, n-1) {
        rep(j, 1, m-1) {
            if (board[i][j] == 'X') {
                if (dists[i][j] >= answer) {
                    cout << 'X';
                } else {
                    cout << '.';
                }
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
}