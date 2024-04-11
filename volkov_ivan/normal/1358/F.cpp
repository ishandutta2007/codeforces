#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
int a[N], b[N];
int n;

bool check() {
    for (int i = 0; i < n; i++) if (a[i] != b[i]) return 0;
    return 1;
}

bool issorted() {
    for (int i = 1; i < n; i++) {
        if (b[i] <= b[i - 1]) return 0;
    }
    return 1;
}

void decr() {
    for (int i = n - 1; i > 0; i--) {
        //cout << i << endl;
        b[i] -= b[i - 1];
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    if (n == 1) {
        if (a[0] == b[0]) {
            cout << "SMALL" << endl << 0 << endl << endl;
            return 0;
        }
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int x1 = a[0], y1 = a[1], x2 = b[0], y2 = b[1];
    string res = "";
    int kek = 2000;
    if (n <= 10) kek = 1e7;
    int cnt = 0;
    for (int i = 0; i < kek; i++) {
        //cout << b[0] << ' ' << b[1] << endl;
        if (check()) break;
        reverse(b, b + n);
        if (check()) {
            res += "R";
            break;
        }
        reverse(b, b + n);
        if (issorted()) {
            decr();
            cnt++;
            res += "P";
        } else {
            reverse(b, b + n);
            res += "R";
            if (!issorted()) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            decr();
            res += "P";
            cnt++;
        }
    }
    if (!check() && n != 2) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    if (cnt <= 200000 && check()) {
        cout << "SMALL" << endl;
        reverse(res.begin(), res.end());
        cout << res.size() << endl;
        cout << res << endl;
        return 0;
    }
    if (check()) {
        cout << "BIG" << endl;
        cout << cnt << endl;
        return 0;
    }
    int xx = x2, yy = y2;
    if (y1 > x1) swap(x1, y1);
    int now = 0;
    while (xx != 0 && yy != 0) {
        if (yy > xx) swap(xx, yy);
        //cout << xx << ' ' << yy << endl;
        if (yy == y1) {
            if (xx >= x1 && (xx - x1) % yy == 0) {
                now += (xx - x1) / yy;
                cout << "BIG" << endl;
                cout << now << endl;
                return 0;
            }
        }
        if (xx == yy) break;
        int need = xx - yy;
        int need2 = need / yy;
        if (need % yy != 0) need2++;
        now += need2;
        xx -= yy * need2;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}