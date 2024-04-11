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

const int N = 200100;

char s[5][5], t[5][5];

int jug2 () {
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) if (s[i][j] != t[i][j]) return 0;
    return 1;
}

pii p[4][4];

int jug () {
    p[0][0] = pii (0, 1);
    p[0][1] = pii (1, 1);
    p[1][1] = pii (1, 0);
    p[1][0] = pii (0, 0);
    for (int k = 0; k < 100; k++) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (s[i][j] == 'X') {
                    int tx = p[i][j].xx, ty = p[i][j].yy;
                    swap (s[i][j], s[tx][ty]);
                    goto x;
                }
            }
        }

        x:;
//                for (int i = 0; i < 2; i++) {
//            for (int j = 0; j < 2; j++) cout << s[i][j]; cout << endl;
//        }
        if (jug2 ()) return 1;
    }
    return 0;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    scanf ("%s%s", s[0], s[1]);
    scanf ("%s%s", t[0], t[1]);
    if (jug ()) cout << "YES";
    else cout << "NO";
}