#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 800, mod = 1e9 + 7;
char s[N];

struct P {
    int a[3][3];
    void init () { memset (a, 0, sizeof a); }
    void printf () {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << a[i][j] << ' ';
            } cout << endl;
        } cout << endl;
    }
};

int a[N], nx[N];

void add (int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

P add (P a, P b) {
    P c;
    c.init();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (j == 1 && k == 1 || j == 2 && k == 2) continue;
//                    if (i == 0 && l == 0) cout << j << ' ' << k << ' ' << ' ' << a.a[i][j] << ' ' << b.a[k][l] << endl;
                    add (c.a[i][l], (int) (1LL * a.a[i][j] * b.a[k][l] % mod));
                }
            }
        }
    }
//    a.printf ();
//    b.printf ();
//    c.printf ();
    return c;
}

int len;

P solve (int l, int r) {
//    cout << l << ' ' << r << endl;
    P ans;
    ans.init();
    if (l + 1 == r) {
        ans.a[1][0] = ans.a[0][1] = ans.a[2][0] = ans.a[0][2] = 1;
        return ans;
    }
    ans.init();
    for (int i = l + 1; i < r; i = nx[i] + 1) {
        if (i == l + 1) ans = solve (i, nx[i]);
        else ans = add (ans, solve (i, nx[i]));
//        solve (i, nx[i]).printf();
    }
    P ans2;
    ans2.init();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) if (i && !l || !i && l) {
                    if (i == 1 && j == 1 || i == 2 && j == 2 || k == 1 && l == 1 || k == 2 && l == 2) continue;
                    add (ans2.a[i][l], ans.a[j][k]);
                }
            }
        }
    }
//    ans.printf();
//    ans2.printf();
    return ans2;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    scanf ("%s", s);
    len = strlen (s);
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') cnt++, a[cnt] = i;
        else nx[a[cnt]] = i, cnt--;
    }
//    for (int i = 0; i < len; i++) if (s[i] == '(') cout << i << ' ' << nx[i] << endl;
    int res = 0;
    P ans;
    for (int i = 0; i < len; i = nx[i] + 1) {
        if (i == 0) ans = solve (i, nx[i]);
        else ans = add (ans, solve (i, nx[i]));
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            add (res, ans.a[i][j]);
    cout << res << endl;
}