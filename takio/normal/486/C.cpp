#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

const int N = 100100;
char s[N];
int ok[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, p;
    cin >> n >> p;
    p--;
    scanf ("%s", s);
    int ti, tj;
    int res = 0;
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
        ok[i] = ok[j] = min (abs (s[i] - s[j]), 26 - abs (s[i] - s[j])), res += ok[i];
        ti = i, tj = j;
    }
    int t, x, te;
    if (p <= ti) t = ti, x = -1, te = 0;
    else t = tj, x = 1, te = n - 1;
    int flag = 0;
//    for (int i = 0; i < n; i++) cout << ok[i] <<' '; cout << endl;
//    cout << t << ' ' << te << endl;
    while (t >= 0 && t < n) {
        if (ok[t]) {flag = 1; break;}
        t += x;
    }
//    cout << t << ' ' << te << endl;
    if (!flag) { cout << 0 << endl; return 0; }
    while (te != t) {
        if (ok[te]) { break; }
        te -= x;
    }
//    cout << te << ' ' << t << endl;
    res += min (abs (p - t), abs (p - te)) + abs (t - te);
    cout << res << endl;
}