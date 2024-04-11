#include <bits/stdc++.h>
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
using namespace std;

const int N = 2505;

bitset <N> a[N];
piii b[N * N];
int mp[N][N];
int n, x, bn = 0;

int solve (int l, int r) {
    for (int i = l; i <= r; i++) {
        if ((a[b[i].yy.xx] | a[b[i].yy.yy]) != a[0]) return 0;
    }
    for (int i = l; i <= r; i++) {
        a[b[i].yy.xx][b[i].yy.yy] = 0;
        a[b[i].yy.yy][b[i].yy.yy] = 0;
    }
    return 1;
}

int solve () {
    for (int i = 1; i <= n; i++) {
        if (mp[i][i]) return 0;
        for (int j = 1; j <= n; j++) {
            if (mp[i][j] != mp[j][i]) return 0;
        }
    }
    return 1;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n;
    a[0].set ();
    for (int i = 1; i <= n; i++) {
        a[i].set ();
        for (int j = 1; j <= n; j++) {
            scanf ("%d", &mp[i][j]);
            b[++bn] = piii (mp[i][j], pii (i, j));
        }
    }
//    return 0;
    if (!solve ()) {
        cout << "NOT MAGIC";
        return 0;
    }
//    cout << a[0] << endl;
    sort (b + 1, b + bn + 1);
    for (int i = 1; i <= bn; ) {
        int j = i + 1;
        while (j <= bn && b[j].xx == b[i].xx) j++;
        if (!solve (i, j - 1)) {
            cout << "NOT MAGIC";
            return 0;
        }
        i = j;
    }
    cout << "MAGIC";
}