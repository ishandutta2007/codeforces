#include <bits/stdc++.h>
using namespace std;

int calc(vector<int> &row) {
    int ans = 0;
    for (int i = 0, j = 0; i < (int) row.size(); i = j) {
        while (j < (int) row.size() && row[i] == row[j]) {
            ++j;
        }

        if (row[i] == 1) {
            ans = max(ans, j - i);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> bears(n, vector<int>(m));
    for (auto &i : bears) {
        for (auto &j : i) {
            cin >> j;
        }
    }

    vector<int> score(n);
    for (int i = 0; i < n; ++i) {
        score[i] = calc(bears[i]);
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        bears[r - 1][c - 1] ^= 1;
        score[r - 1] = calc(bears[r - 1]);
        cout << *max_element(score.begin(), score.end()) << "\n";
    }
}