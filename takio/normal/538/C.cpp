#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#define LL long long
#define pii pair <int, int>
using namespace std;

const int N = 100100;

char t[30] = {"CODEFORCES"}, s[1100];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int td, th, d, h;
    scanf ("%d%d", &td, &th);
    int res = th + td - 1;
//    cout << res << endl;
    for (int i = 2; i <= m; i++) {
        scanf ("%d%d", &d, &h);
        if (d - td < abs (h - th)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        res = max (res, (d - td - abs (h - th)) / 2 + max (h, th));
//        cout << (d - td - abs (h - th)) / 2 + max (h, th) << endl;
//        cout << res << endl;
        td = d;
        th = h;
    }
//    cout << n << ' ' << d << ' ' << h << endl;
    res = max (res, n - td + th);
    cout << res << endl;
}