#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;

const LL INF = 1LL << 60;

LL res[10][10], a[10][10];
int t[10][10] = {
    {0, 1, 2, 3},
    {0, 1, 3, 2},
    {0, 2, 1, 3},
    {0, 2, 3, 1},
    {0, 3, 1, 2},
    {0, 3, 2, 1},
};

LL d (int i, int j) {
    LL tmp = 0;
    tmp += (res[i][1] - res[j][1]) * (res[i][1] - res[j][1]);
    tmp += (res[i][2] - res[j][2]) * (res[i][2] - res[j][2]);
    tmp += (res[i][3] - res[j][3]) * (res[i][3] - res[j][3]);
    return tmp;
}

LL dd[10][10];

int jug () {
    LL mn = INF;
    for (int i = 1; i <= 8; i++) {
        for (int j = i + 1; j <= 8; j++) {
            dd[i][j] = d(i, j);
            mn = min (dd[i][j], mn);
        }
    }
    int s1 = 0, s2 = 0, s3 = 0;
    for (int i = 1; i <= 8; i++) {
        for (int j = i + 1; j <= 8; j++) {
            if (dd[i][j] == mn) s1++;
            if (dd[i][j] == mn * 2) s2++;
            if (dd[i][j] == mn * 3) s3++;
        }
    }
    if (s1 == 12 && s2 == 12 && s3 == 4) return 1;
    return 0;
}

int dfs (int pos, int x, int y, int z) {
//    cout << pos << endl;
//    cout << x << ' ' << y << ' ' << z << ' ' << pos - 1 << endl;
    if (pos != 1) res[pos - 1][1] = x, res[pos - 1][2] = y, res[pos - 1][3] = z;
//    cout << res[pos - 1][1] << ' ' << res[pos - 1][2] << ' ' << res[pos - 1][3] << ' ' << pos - 1 << endl;
    if (pos == 9) {
//        cout << "jug" << jug () << endl;
        if (jug()) {
            cout << "YES\n";
            for (int i = 1; i <= 8; i++) {
                for (int j = 1; j <= 3; j++) {
                    if (j != 1) cout << ' ';
                    cout << res[i][j];
                }
                cout << endl;
            }
            return 1;
        }
        return 0;
    }
    for (int i = 0; i < 6; i++) {
        if (dfs (pos + 1, a[pos][t[i][1]], a[pos][t[i][2]], a[pos][t[i][3]])) return 1;
    }
    return 0;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
//            cout << a[i][j] <<' ';
        }
//        cout << endl;
    }

//    cout << jug () <<endl;
    if (!dfs (1, 0, 0, 0)) {
        cout << "NO";
    }
}