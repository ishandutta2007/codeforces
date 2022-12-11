#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    bool field[n][m];
    char now;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> now;
            if (now == '*') field[i][j] = 1;
            else field[i][j] = 0;
        }
    }
    int left[n][m], right[n][m], up[n][m], down[n][m], ans[n][m];
    int cnt;
    for (int i = 0; i < n; i++) {
        cnt = 0;
        for (int j = 0; j < m; j++) {
            if (field[i][j]) cnt++;
            else cnt = 0;
            left[i][j] = cnt;
        }
    }
    for (int i = 0; i < n; i++) {
        cnt = 0;
        for (int j = m - 1; j >= 0; j--) {
            if (field[i][j]) cnt++;
            else cnt = 0;
            right[i][j] = cnt;
        }
    }
    for (int j = 0; j < m; j++) {
        cnt = 0;
        for (int i = 0; i < n; i++) {
            if (field[i][j]) cnt++;
            else cnt = 0;
            up[i][j] = cnt;
        }
    }
    for (int j = 0; j < m; j++) {
        cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (field[i][j]) cnt++;
            else cnt = 0;
            down[i][j] = cnt;
        }
    }
    int gor[n + 1][m + 1], vert[n + 1][m + 1];
    bool used[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            gor[i][j] = vert[i][j] = 0;
            used[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = min(min(left[i][j], right[i][j]), min(up[i][j], down[i][j])) - 1;
            if (ans[i][j] <= 0) ans[i][j] = -1;
            else {
                gor[i][j - ans[i][j]]++;
                gor[i][j + ans[i][j] + 1]--;
                vert[i - ans[i][j]][j]++;
                vert[i + ans[i][j] + 1][j]--;
            }
        }
    }
    int bal;
    for (int i = 0; i < n; i++) {
        bal = 0;
        for (int j = 0; j < m; j++) {
            bal += gor[i][j];
            if (bal > 0) used[i][j] = 1;
        }
    }
    for (int j = 0; j < m; j++) {
        bal = 0;
        for (int i = 0; i < n; i++) {
            bal += vert[i][j];
            if (bal > 0) used[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] && !used[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    vector <pair <pair <int, int>, int>> ans2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] != -1) {
                ans2.push_back({{i + 1, j + 1}, ans[i][j]});
            }
        }
    }
    cout << ans2.size() << endl;
    for (auto elem : ans2) {
        cout << elem.first.first << ' ' << elem.first.second << ' ' << elem.second << "\n";
    }
    return 0;
}