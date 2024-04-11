#include <algorithm>
#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define LL long long
#define pii pair <LL, int>
#define xx first
#define yy second
using namespace std;

//const int N = 2010;
//char mp[N][N];
//int vis[N][N];
//int n, m;
//int dx[5] = {0, 1, 0, -1}, dy[5] = {1, 0, -1, 0};
//
//struct dat {
//    int x1, y1, x2, y2, x, y;
//    dat (int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int x = 0, int y = 0) : x1(x1), y1(y1), x2(x2), y2(y2), x(x), y(y) {}
//};
//
//void dfs (int x1, int y1, int x2, int y2, int x, int y) {
//    queue <dat> q;
//    q.push (dat (x1, y1, x2, y1, x, y));
//    mp[x][y] = '.';
//    while (!q.empty ()) {
//        dat u = q.front(); q.pop();
//        x1 = u.x1, y1 = u.y1, x2 = u.x2, y2 = u.y2, x = u.x, y = u.y;
//        cout << x << ' ' << y << endl;
//        for (int i = 0; i < 4; i++) {
//            int tx = x + dx[i], ty = y + dy[i];
//            if (tx < 1 || tx > n || ty < 1 || ty > m || vis[tx][ty]) continue;
//            if ((x1 <= tx && tx <= x2 && y1 <= ty && ty <= y2) || mp[tx][ty] == '.') {
//                vis[tx][ty] = 1;
//                mp[tx][ty] = '.';
//                q.push (dat (min (x1, tx), min (y1, ty), max (x2, tx), max (y2, ty), tx, ty));
//            }
//        }
//    }
////    vis[x][y] = 1;
////    for (int i = 0; i < 4; i++) {
////        int tx = x + dx[i], ty = y + dy[i];
////        if (tx < 1 || tx > n || ty < 1 || ty > m || vis[tx][ty]) continue;
////        if ((x1 <= tx && tx <= x2 && y1 <= ty && ty <= y2) || mp[tx][ty] == '.')
////            dfs (min (x1, tx), min (y1, ty), max (x2, tx), max (y2, ty), tx, ty);
////    }
//}
//
//int main () {
//    freopen ("in.txt", "r", stdin);
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) {
//        scanf ("%s", mp[i] + 1);
//    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) if (mp[i][j] == '.' && !vis[i][j]) {
//            dfs (i, j, i, j, i, j);
//        }
//    }
//    for (int i = 1; i <= n; i++) {
//        printf ("%s\n", mp[i] + 1);
//    }
//}
//
const int N = 100100;
int a[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
    }
    sort (a + 1, a + 1 + n);
    LL res = 0, now = 1, cnt = 0;
    for (int i = n; i >= 2; i--) {
        if (a[i] == a[i - 1] || a[i] == a[i - 1] + 1) {
            now *= a[i - 1];
            if (++cnt == 2) {
                res += now;
                cnt = 0;
                now = 1;
            }
            i--;
        }
    }
    cout << res << endl;
}