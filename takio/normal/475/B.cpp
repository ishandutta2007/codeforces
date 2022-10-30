#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define LL long long
using namespace std;

int vis[30][30], n, m, cnt;
char a[30], b[30];

void dfs (int x, int y) {
//    cout << "xy" << x  << ' ' << y << endl;
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y]) return;
    vis[x][y] = 1;
    cnt++;
    if (a[x] == '>') dfs (x, y + 1);
    else dfs (x, y - 1);
//    cout << b[y] << endl;
    if (b[y] == 'v') dfs (x + 1, y);
    else dfs (x - 1, y);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    int all = n * m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            memset (vis, 0, sizeof (vis));
            cnt = 0;
            dfs (i, j);
            if (cnt != all) {
//                cout << i << ' ' << j << endl;
//                cout << cnt << endl;
//                for (int i = 1; i <= n; i++) {
//                    for (int j = 1; j <= m; j++) {
//                        cout << vis[i][j];
//                    } cout << endl;
//                }
                printf ("NO\n");
                return 0;
            }
        }
    }
    printf ("YES\n");
}