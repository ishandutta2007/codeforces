#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

const int N = 110;
int n, m;
int mp[4][N][N];

int jug1 (int k, int x, int c) {
    for (int i = 1; i <= m; i++) if (mp[k][x][i] == c) return 0;
    return 1;
}

int jug2 (int k, int y, int c) {
    for (int i = 1; i <= n; i++) if (mp[k][i][y] == c) return 0;
    return 1;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[1][i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
//            cout <<i << ' ' << j << ' ' << jug1 (1, i, 0) << ' ' << jug2 (1, j, 0) << endl;
            if (jug1 (1, i, 0) && jug2 (1, j, 0)) mp[2][i][j] = 1;
        }
    }
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int t = 0;
            if (!jug1 (2, i, 1) || !jug2 (2, j, 1)) t = 1;
            if (t != mp[1][i][j]) flag = 1;
        }
    }
    if (flag) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << mp[2][i][j];
                if (j == m) cout << endl;
                else cout << ' ';
            }
        }
    }
}