#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;

char s[110];
pii pre[110][8];

int main () {
//    freopen ("in.txt", "r", stdin);
    for (int i = 0; i < 110; i++) {
        for (int j = 0; j < 8; j++) {
            pre[i][j] = pii (-1, -1);
        }
    }
    scanf ("%s", s);
    pre[0][0] = pii (-1, 0);
    for (int i = 0; s[i]; i++) {
        s[i] -= '0';
        for (int j = 0; j < 8; j++) pre[i + 1][j] = pre[i][j];
        for (int j = 0; j < 8; j++) if (pre[i][j] != pii (-1, -1)) {
            pre[i + 1][(j * 10 + s[i]) % 8] = pii (i, j);
        }
//        for (int j = 0; j < 8; j++) cout <<endl;
        if (pre[i + 1][0].xx != -1) {
            cout << "YES\n";
            int x = i + 1, y = 0;
//            cout << x << ' ' << y <<endl;
            vector <int> res;
            while (x != -1) {
                pii t = pre[x][y];
                x = t.xx;
                y = t.yy;
                res.push_back (s[x]);
//                cout << x <<' ' << y << endl;
            }
            for (int k = res.size() - 2; k >= 0; k--) {
                cout << res[k];
            }
            return 0;
        }
    }
    cout << "NO\n";
}