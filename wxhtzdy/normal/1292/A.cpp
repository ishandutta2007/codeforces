#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(2, vector<int>(n, 0));
    int cnt = 0;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (a[x][y] == 0) {
            a[x][y] = 1;
            if (x == 1 && a[x - 1][y] == 1) cnt++;
            if (x == 1 && y > 0 && a[x - 1][y - 1] == 1) cnt++;
            if (x == 1 && y < n - 1 && a[x - 1][y + 1] == 1) cnt++;
            if (x == 0 && a[x + 1][y] == 1) cnt++;
            if (x == 0 && y > 0 && a[x + 1][y - 1] == 1) cnt++;
            if (x == 0 && y < n - 1 && a[x + 1][y + 1] == 1) cnt++;
            if (cnt == 0) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
            continue;
        }
        a[x][y] = 0;
        if (x == 1 && a[x - 1][y] == 1) cnt--;
        if (x == 1 && y > 0 && a[x - 1][y - 1] == 1) cnt--;
        if (x == 1 && y < n - 1 && a[x - 1][y + 1] == 1) cnt--;
        if (x == 0 && a[x + 1][y] == 1) cnt--;
        if (x == 0 && y > 0 && a[x + 1][y - 1] == 1) cnt--;
        if (x == 0 && y < n - 1 && a[x + 1][y + 1] == 1) cnt--;
        if (cnt == 0) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }

    }
    return 0;
}