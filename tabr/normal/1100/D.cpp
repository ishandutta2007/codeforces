#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 666;
    int x, y;
    cin >> x >> y;
    vector<pair<int, int>> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i].first >> r[i].second;
    }
    int p = (x == 500 && y == 500);
    int dx = 1, dy = 1;
    for (int tt = 0; tt < 2000; tt++) {
        if (p == 0) {
            dx = (x < 500 ? 1 : (x > 500 ? -1 : 0));
            dy = (y < 500 ? 1 : (y > 500 ? -1 : 0));
            x += dx, y += dy;
            for (int i = 0; i < n; i++) {
                if (r[i] == (pair<int, int>){x, y}) {
                    y -= dy;
                    break;
                }
            }
            cout << x << " " << y << endl;
            if (x == 500 && y == 500) {
                p = 1;
            }
        } else if (p == 1) {
            vector<int> cnt(4);
            for (int i = 0; i < n; i++) {
                int j = 2 * (r[i].second < 500) + (r[i].first > 500);
                cnt[j]++;
            }
            int mn = 0, sum = cnt[0];
            for (int i = 1; i < 4; i++) {
                if (sum > cnt[i]) {
                    mn = i;
                    sum = cnt[i];
                }
            }
            dx = dy = 1;
            if (mn & 1) {
                dx = -1;
            }
            if (mn < 2) {
                dy = -1;
            }
            p = 2;
        }
        if (p == 2) {
            x += dx, y += dy;
            for (int i = 0; i < n; i++) {
                if (r[i] == (pair<int, int>){x, y}) {
                    y -= dy;
                    break;
                }
            }
            cout << x << " " << y << endl;
        }
        int k, a, b;
        cin >> k >> a >> b;
        if (k < 1) {
            return 0;
        }
        r[k - 1] = {a, b};
    }
    return 0;
}