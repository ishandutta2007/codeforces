#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 510;
char mp[N][N];
int vis[N][N];
int dx[5] = {0, 1, 0, -1}, dy[5] = {1, 0, -1, 0};
int sx, sy, tx, ty, n, m;

int jug (int x, int y) {
//    cout << x << ' ' << y << endl;
    return x >= 0 && x < n && y >= 0 && y < m && mp[x][y] == '.';
}

int bfs () {
    queue <pii> q;
    q.push (pii (sx, sy));
    while (!q.empty ()) {
        pii u = q.front(); q.pop();
        int x = u.xx, y = u.yy;
        for (int i = 0; i < 4; i++) {
            int tmpx = x + dx[i], tmpy = y + dy[i];
            if (tmpx == tx && tmpy == ty) return 1;
            if (!jug (tmpx, tmpy) || vis[tmpx][tmpy]) continue;
            vis[tmpx][tmpy] = 1;
            q.push (pii (tmpx, tmpy));
        }
    }
    return 0;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) scanf ("%s", mp[i]);
    cin >> sx >> sy >> tx >> ty;
    sx--, sy--, tx--, ty--;
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (jug (tx + dx[i], ty + dy[i])) cnt++;
    }
    for (int i = 0; i < 4; i++) {
        if (sx + dx[i] == tx && sy + dy[i] == ty && cnt) {
            cout << "YES";
            return 0;
        }
    }
//    cout <<cnt << endl;
    if (cnt <= 1 && mp[tx][ty] == '.') {
        cout << "NO";
        return 0;
    }
    if (bfs ()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}