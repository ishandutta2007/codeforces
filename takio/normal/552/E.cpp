#include <stdio.h>
#include <map>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define xx first
#define yy second
#define LL long long
#define pii pair <LL, LL>
using namespace std ;

const int N = 10010;

char s[N];
int a[30];

pii solve (int l, int r, int k) {
//    cout << l << ' ' << r << ' ' << k << endl;
    if (l > r) return pii (0, 1);
    if (l == r) return pii (0, s[l]);
    LL res = 0, now;
    if (k == 0) {
        now = s[l];
        for (int i = l + 1; i <= r; i += 2) {
            if (s[i] == '+') {
                res += now;
                now = s[i + 1];
            } else {
                now *= s[i + 1];
            }
        }
    } else {
        now = s[r];
        for (int i = r - 1; i >= l; i -= 2) {
            if (s[i] == '+') {
                res += now;
                now = s[i - 1];
            } else {
                now *= s[i - 1];
            }
        }
    }
    return pii (res, now);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    scanf ("%s", s);
    int len = strlen (s);
    int an = 0;
    a[++an] = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == '*') a[++an] = i;
        else if (s[i] != '+') s[i] -= '0';
    }
    a[++an] = len;
    LL res = 0;
    for (int i = 1; i <= an; i++) {
        for (int j = i + 1; j <= an; j++) {
            pii t1 = solve (0, a[i] - 1, 0);
            pii t2 = solve (a[i] + 1, a[j] - 1, 0);
            pii t3 = solve (a[j] + 1, len - 1, 1);
            LL tmp = t1.xx + t1.yy * (t2.xx + t2.yy) * t3.yy + t3.xx;
            if (res < tmp) {
                res = tmp;
//                cout << res << ' ' << a[i] << ' ' << a[j] << ' ' << t2.xx << ' ' << t2.yy << endl;
            }
        }
    }
    cout << res << endl;
}