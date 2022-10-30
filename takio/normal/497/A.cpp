#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int N = 1010;
char mp[N][N];
int n, m, ok[N];

int jug (int y) {
    for (int i = 2; i <= n; i++) {
        if (!ok[i] && mp[i][y] < mp[i - 1][y]) return 0;
    }
    return 1;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        getchar();
        for (int j = 1; j <= m; j++) {
            scanf ("%c", &mp[i][j]);
        }
    }
    int res = 0;
    for (int i = 1; i <= m; i++) {
        if (jug(i)) {
            for (int j = 2; j <= n; j++) {
                if (!ok[j] && mp[j][i] > mp[j - 1][i]) ok[j] = 1;
            }
        } else {
            res++;
//            cout << "--" << i << endl;
        }
    }
    cout << res << endl;
}