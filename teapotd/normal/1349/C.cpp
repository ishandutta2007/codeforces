#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

int n, m, t;
char board[1005][1005];
int dist[1005][1005];
queue<Pii> que;

void check(int i, int j, int d) {
    if (i < 0 || j < 0 || i >= n || j >= m) return;
    if (dist[i][j] <= d) return;
    dist[i][j] = d;
    que.push({i, j});
}

void run() {
    cin >> n >> m >> t;

    rep(i, 0, n) {
        cin >> board[i];
    }

    rep(i, 0, n) rep(j, 0, m) {
        bool ok = 0;
        if (i > 0 && board[i-1][j] == board[i][j]) ok = 1;
        if (j > 0 && board[i][j-1] == board[i][j]) ok = 1;
        if (i+1 < n && board[i+1][j] == board[i][j]) ok = 1;
        if (j+1 < m && board[i][j+1] == board[i][j]) ok = 1;
        if (ok) {
            dist[i][j] = 0;
            que.push({i, j});
        } else {
            dist[i][j] = 1e9;
        }
    }

    while (!que.empty()) {
        int i = que.front().x, j = que.front().y;
        que.pop();
        check(i-1, j, dist[i][j]+1);
        check(i+1, j, dist[i][j]+1);
        check(i, j-1, dist[i][j]+1);
        check(i, j+1, dist[i][j]+1);
    }

    while (t--) {
        int i, j;
        ll p;
        cin >> i >> j >> p;
        i--; j--;

        int col = (board[i][j] == '1');

        if (dist[i][j] < p && dist[i][j] < int(1e9)) {
            if ((p-dist[i][j]) % 2) {
                col = !col;
            }
        }

        cout << col << '\n';
    }
}