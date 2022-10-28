#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1501;

vector<pair<int, int>> colors[2][MAX_N];
int tiles[MAX_N][MAX_N], ans[MAX_N];

vector<pair<int, int>> merge(vector<pair<int, int>> &a, vector<pair<int, int>> &b) {
    vector<pair<int, int>> c;

    int i = 0, j = 0;
    while (i < (int) a.size() && j < (int) b.size()) {
        if (a[i].first < b[j].first) {
            c.push_back(a[i++]);
        } else if (a[i].first == b[j].first) {
            c.push_back(min(a[i++], b[j++]));
        } else {
            c.push_back(b[j++]);
        }
    }

    c.insert(c.end(), a.begin() + i, a.end());
    c.insert(c.end(), b.begin() + j, b.end());

    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tiles[i][j];
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        fill(colors[i % 2], colors[i % 2] + n, vector<pair<int, int>>());
        for (int j = n - 1; j >= 0; --j) {
            colors[i % 2][j] = {{tiles[i][j], 0}};
            if (i < n - 1) {
                colors[i % 2][j] = merge(colors[i % 2][j], colors[1 - i % 2][j]);
            }
            if (j < n - 1) {
                colors[i % 2][j] = merge(colors[i % 2][j], colors[i % 2][j + 1]);
            }
            if (i < n - 1 && j < n - 1) {
                colors[i % 2][j] = merge(colors[i % 2][j], colors[1 - i % 2][j + 1]);
            }

            int max_size = min(n - i, n - j);
            if ((int) colors[i % 2][j].size() > q) {
                sort(colors[i % 2][j].begin(), colors[i % 2][j].end(), [&](const auto &a, const auto &b) {
                    return a.second < b.second;
                });
                colors[i % 2][j].resize(q + 1);
                max_size = min(max_size, colors[i % 2][j][q].second);
                sort(colors[i % 2][j].begin(), colors[i % 2][j].end());
            }
            ++ans[max_size];

            for (auto &[color, dist] : colors[i % 2][j]) {
                ++dist;
            }
        }
    }

    for (int i = n - 1; i > 0; --i) {
        ans[i] += ans[i + 1];
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << "\n";
    }
}