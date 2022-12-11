#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 27, INF = 1e16;
int a[N][N];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dg = i + j;
            if (i % 2 == 0) a[i][j] = (1ll << dg);
            else a[i][j] = 0;
        }
    }
    a[0][0] = 0;
    a[1][0] = 0;
    a[0][1] = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    int q;
    cin >> q;
    for (int t = 0; t < q; t++) {
        int summ;
        cin >> summ;
        vector <pair <int, int>> res;
        res.push_back({0, 0});
        int x, y;
        if (summ >= INF) {
            summ -= INF;
            x = 0;
            y = 1;
        } else {
            x = 1;
            y = 0;
        }
        while (1) {
            res.push_back({x, y});
            if (x == n - 1 && y == n - 1) break;
            int dg = x + y + 1;
            int kek = summ & (1ll << dg);
            bool f1 = (kek > 0);
            bool f2 = (x % 2 == 0);
            if (f1 == f2) y++;
            else x++;
        }
        for (auto elem : res) {
            cout << elem.first + 1 << ' ' << elem.second + 1 << endl;
        }
    }
    return 0;
}