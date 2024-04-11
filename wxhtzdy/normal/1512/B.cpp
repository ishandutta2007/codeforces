#include <bits/stdc++.h>
using namespace std;

void run_case() {
    int N;
    cin >> N;
    vector<string> S(N);

    for (int  i = 0; i < N; i++) cin >> S[i];
    vector<pair<int, int>> pos;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == '*') {
                pos.emplace_back(i, j);
            }
        }
    }
    int x1 = pos[0].first, y1 = pos[0].second, x2 = pos[1].first, y2 = pos[1].second;
    if (x1 != x2 && y1 != y2) {
        S[min(x1, x2)][min(y1, y2)] = '*';
        S[max(x1, x2)][min(y1, y2)] = '*';
        S[min(x1, x2)][max(y1, y2)] = '*';
        S[max(x1, x2)][max(y1, y2)] = '*';
    } else {
        if (x1 == x2) {
            if (x1 == 0) {
                S[x1 + 1][y1] = '*';
                S[x2 + 1][y2] = '*';
            } else {
                S[x1 - 1][y1] = '*';
                S[x2 - 1][y2] = '*';
            }
        } else {
            if (y1 == 0) {
                S[x1][y1 + 1] = '*';
                S[x2][y2 + 1] = '*';
            } else {
                S[x1][y1 - 1] = '*';
                S[x2][y2 - 1] = '*';
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << S[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--)
        run_case();
}