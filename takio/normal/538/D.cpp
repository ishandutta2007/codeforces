#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 210;
char mp[N][N], res[N][N];
int n, ok[N][N];
vector <pii> g;

int jug (int dx, int dy) {
    for (int i = 0; i < (int) g.size(); i++) {
        int x = g[i].xx + dx, y = g[i].yy + dy;
//        if (dx == -1 && dy == -1) cout << x << ' ' << y << endl;
        if (x >= 1 && x <= n && y >= 1 && y <= n && mp[x][y] == '.') return 0;
    }
    return 1;
}

void updata (int dx, int dy) {
    for (int i = 0; i < (int) g.size(); i++) {
        int x = g[i].xx + dx, y = g[i].yy + dy;
        if (x >= 1 && x <= n && y >= 1 && y <= n) ok[x][y] = 1;
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%s", mp[i] + 1);
        for (int j = 1; j <= n; j++) {
            if (mp[i][j] == 'o') {
                g.push_back (pii (i, j));
//                cout << i << ' ' << j << endl;
            }
        }
    }
    res[n][n] = 'o';
    for (int i = -n + 1; i <= n - 1; i++) {
        for (int j = -n + 1; j <= n - 1; j++) {
            if (i == 0 && j == 0) continue;
            if (jug (i, j)) {
                res[i + n][j + n] = 'x';
                updata (i, j);
            }
            else res[i + n][j + n] = '.';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mp[i][j] == 'x' && !ok[i][j]) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= 2 * n - 1; i++) {
        printf ("%s\n", res[i] + 1);
    }
}