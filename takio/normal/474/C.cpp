#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <ctime>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;
LL x[6], y[6], a[6], b[6];

LL dis (LL x, LL y) {
    return x * x + y * y;
}

LL jug () {
    LL mn = 1LL << 60;
    for (LL i = 1; i <= 4; i++) {
        for (LL j = i + 1; j <= 4; j++) {
            mn = min (mn, dis (x[i] - x[j], y[i] - y[j]));
        }
    }
    if (mn == 0) return 0;
    LL cnt1 = 0, cnt2 = 0;
    for (LL i = 1; i <= 4; i++) {
        for (LL j = i + 1; j <= 4; j++) {
            if (dis (x[i] - x[j], y[i] - y[j]) == mn) cnt1++;
            if (dis (x[i] - x[j], y[i] - y[j]) == mn * 2) cnt2++;
        }
    }
    if (cnt1 == 4 && cnt2 == 2) return 1;
    return 0;
}

LL res;

void dfs (LL k, LL cnt) {
    if (k == 5) {
        if (res > cnt && jug ()) {
            res = cnt;
//            if (cnt == 5) {
//            cout << cnt << endl;
//            for (LL i = 1; i <= 4; i++) {
//                cout << x[i] << ' ' << y[i] << endl;
//            }cout << endl;
//            }
        }
        return;
    }
    for (LL i = 0; i < 4; i++) {
        dfs (k + 1, cnt + (4 - i) % 4);
        LL tx = y[k] - b[k] + a[k], ty = a[k] - x[k] + b[k];
        x[k] = tx, y[k] = ty;
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    LL n;
    cin >> n;
    while (n--) {
        res = 1000;
        for (LL i = 1; i <= 4; i++) {
            cin >> x[i] >> y[i] >> a[i] >> b[i];
        }
//        int k = 1;
//        for (LL i = 0; i < 4; i++) {
//            dfs (k + 1, cnt + (4 - i) % 4);
//            LL tx = y[k] - b[k] + a[k], ty = a[k] - x[k] + b[k];
//            x[k] = tx, y[k] = ty;
//        }
        dfs (1, 0);
        if (res == 1000) cout << -1 << endl;
        else cout << res << endl;
    }
}