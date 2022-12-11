#include <iostream>
#include <vector>

using namespace std;

vector <char> kek;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    char field[n][m];
    char ans[n][m];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
            if (field[i][j] == 'R') cnt++;
        }
    }
    int need = cnt / k;
    int cnt_more = cnt % k;
    int pos = 0, i = 0, j = 0, cur = 0;
    while (i != n) {
        if (pos == k) pos = k - 1;
        ans[i][j] = kek[pos];
        if (field[i][j] == 'R') cur++;
        if ((cur == need + 1 && pos < cnt_more) || (cur == need && pos >= cnt_more)) {
            pos++;
            cur = 0;
        }
        if (i % 2 == 0) {
            j++;
            if (j == m) {
                j--;
                i++;
            }
        } else {
            j--;
            if (j == -1) {
                j++;
                i++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    for (char i = 'a'; i <= 'z'; i++) {
        kek.push_back(i);
        kek.push_back(i + 'A' - 'a');
    }
    for (char i = '0'; i <= '9'; i++) kek.push_back(i);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}