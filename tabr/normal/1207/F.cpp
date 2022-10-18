#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    vector<int> a(500001);
    vector<vector<int>> b(701, vector<int>(701));
    rep(tt, 0, q) {
        int w, x, y;
        cin >> w >> x >> y;
        if (w == 1) {
            a[x] += y;
            rep(i, 1, 701) {
                b[i][x % i] += y;
            }
        } else {
            if (x <= 700) {
                cout << b[x][y] << endl;
            } else {
                int res = 0;
                int i = -1;
                while (x * (i + 1) + y <= 500000) {
                    i++;
                    res += a[x * i + y];
                }
                cout << res << endl;
            }
        }
    }
    return 0;
}