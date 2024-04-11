#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pis pair <int, string>
using namespace std;

const int N = 110;

int mp[N][N][N];

int dx[5] = {1, 0, 0};
int dy[5] = {0, 1, 0};
int dz[5] = {0, 0, 1};

int jug (int i, int j, int k) {
    if (!mp[i][j][k]) return 0;
    for (int p = 0; p < 3; p++) if (mp[i - dx[p]][j - dy[p]][k - dz[p]]) {
        for (int q = 0; q < 3; q++) if (mp[i + dx[q]][j + dy[q]][k + dz[q]]) {
            if (p == q) return 1;
            else if (!mp[i - dx[p] + dx[q]][j - dy[p] + dy[q]][k - dz[p] + dz[q]]) return 1;
        }
    }
//    x:;
    return 0;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int x, y, z;
    cin >> x >> y >> z;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            for (int k = 1; k <= z; k++) {
                scanf ("%1d", &mp[i][j][k]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            for (int k = 1; k <= z; k++) {
                if (jug (i, j, k)) res++;
            }
        }
    }
    cout << res << endl;
}