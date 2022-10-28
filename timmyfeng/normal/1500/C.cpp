#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1500;

int locks[MAX_N];
bool diff[MAX_N];

vector<vector<int>> read(int n, int m) {
    vector<vector<int>> matrix(n, vector<int>(m));
    for (auto &i : matrix) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    return matrix;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    auto initial = read(n, m);
    auto terminal = read(n, m);

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            locks[j] += terminal[i][j] > terminal[i + 1][j];
        }
    }

    vector<int> ans;
    while (count(locks, locks + m, 0) > 0) {
        int j = find(locks, locks + m, 0) - locks;
        ans.push_back(j);
        locks[j] = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (!diff[i] && terminal[i][j] < terminal[i + 1][j]) {
                diff[i] = true;
                for (int k = 0; k < m; ++k) {
                    locks[k] -= terminal[i][k] > terminal[i + 1][k];
                }
            }
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto i : ans) {
        stable_sort(initial.begin(), initial.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[i] < b[i];
        });
    }

    if (initial == terminal) {
        cout << ans.size() << "\n";
        for (auto i : ans) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}