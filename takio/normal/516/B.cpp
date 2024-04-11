#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define getm int m = (l + r) >> 1
#define LL long long
#define ULL unsigned long long
#define pii pair <LL, LL>

using namespace std;

const int N = 2010;

char mp[N][N];
int n, m, cnt1, cnt2, in[N][N];
int xx[6] = {0, 0, 1, 0, -1};
int yy[6] = {0, 1, 0, -1, 0};
queue <pii> q;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m;
    while (cin >> n >> m) {
        memset (in, 0, sizeof in);
        for (int i = 1; i <= n; i++) {
            scanf ("%s", mp[i] + 1);
        }
        cnt1 = cnt2 = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) if (mp[i][j] == '.') {
                cnt1++;
                for (int k = 1; k <= 4; k++)
                    if (mp[i + xx[k]][j + yy[k]] == '.') in[i][j]++;
                if (in[i][j] == 1) {
                    q.push (pii (i, j));
                }
            }
        }
        while (!q.empty ()) {
            pii u = q.front (); q.pop();
            int x = u.first, y = u.second, tx, ty, i;
            for (i = 1; i <= 4; i++) {
                tx = x + xx[i];
                ty = y + yy[i];
                if (mp[tx][ty] == '.') {
                    cnt2 += 2;
                    if (i == 1) mp[x][y] = '<', mp[tx][ty] = '>';
                    if (i == 2) mp[x][y] = '^', mp[tx][ty] = 'v';
                    if (i == 3) mp[x][y] = '>', mp[tx][ty] = '<';
                    if (i == 4) mp[x][y] = 'v', mp[tx][ty] = '^';
                    break;
                }
            }
            if (i == 5) continue;
//            cout << x << ' ' << y << ' ' << tx << ' ' << ty << endl;
            x = tx, y = ty;
            for (int i = 1; i <= 4; i++) {
                tx = x + xx[i];
                ty = y + yy[i];
                if (mp[tx][ty] == '.') {
                    in[tx][ty]--;
                    if (in[tx][ty] == 1) {
                        q.push (pii (tx, ty));
                    }
                }
            }
        }
        if (cnt1 < cnt2) {
            cout << cnt1 << ' ' << cnt2 << endl;
            for (int i = 1; i <= n; i++) {
                printf ("%s\n", mp[i] + 1);
            }
            break;
        }
//        cout << cnt1 << ' ' << cnt2 << endl;
        if (cnt1 != cnt2) {
            printf ("Not unique\n");
    //        if (n == 100 && mp[2][4] == '*') cout << cnt1 << ' ' << cnt2 << endl;
            continue;
        }
        for (int i = 1; i <= n; i++) {
            printf ("%s\n", mp[i] + 1);
        }
    }
}