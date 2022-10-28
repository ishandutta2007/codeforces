#include <bits/stdc++.h>
using namespace std;
 
// puzzle is solvable implies that each number is adjacent to some number less than it
// find first bad cell, one of the 4 adjacent or that cell must be swapped
// try all combinations

const int N = 4e5;

vector<bool> bad[N];
vector<int> a[N];
int n, m;

int bad_cells;

inline bool in_grid(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

vector<pair<int, int>> adjacents(int i, int j) {
    vector<pair<int, int>> result = {{i, j}};
    
    if (in_grid(i - 1, j)) result.push_back({i - 1, j});
    if (in_grid(i + 1, j)) result.push_back({i + 1, j});
    if (in_grid(i, j - 1)) result.push_back({i, j - 1});
    if (in_grid(i, j + 1)) result.push_back({i, j + 1});

    return result;
}

void update_neighbors(int i, int j) {
    assert(0 <= i && i < n && 0 <= j && j < m);
    bad_cells -= bad[i][j];

    bad[i][j] = (!in_grid(i - 1, j) || a[i - 1][j] >= a[i][j]) &&
            (!in_grid(i + 1, j) || a[i + 1][j] >= a[i][j]) &&
            (!in_grid(i, j - 1) || a[i][j - 1] >= a[i][j]) &&
            (!in_grid(i, j + 1) || a[i][j + 1] >= a[i][j]);

    bad_cells += bad[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int x = -1, y = -1;
    for (int i = 0; i < n; ++i) {
        bad[i].resize(m);
        for (int j = 0; j < m; ++j) {
            update_neighbors(i, j);
            if (a[i][j] > 1 && bad[i][j]) {
                x = i, y = j;
            }
        }
    }

    if (bad_cells == 1) {
        cout << 0 << "\n";
        exit(0);
    }

    vector<pair<int, int>> swaps;
    for (auto [i1, j1] : adjacents(x, y)) {
        if (0 <= i1 && i1 < n && 0 <= j1 && j1 < m) {
            auto adj1 = adjacents(i1, j1);
            for (int i2 = 0; i2 < n; ++i2) {
                for (int j2 = 0; j2 < m; ++j2) {
                    if (i1 == i2 && j1 == j2) continue;
                    vector<pair<int, int>> cells = adj1;
                    for (auto p : adjacents(i2, j2)) cells.push_back(p);
                    sort(cells.begin(), cells.end());
                    cells.erase(unique(cells.begin(), cells.end()), cells.end());

                    swap(a[i1][j1], a[i2][j2]);
                    for (auto [i, j] : cells) update_neighbors(i, j);

                    if (bad_cells == 1) swaps.push_back({i1 * m + j1, i2 * m + j2});

                    swap(a[i1][j1], a[i2][j2]);
                    for (auto [i, j] : cells) update_neighbors(i, j);
                }
            }
        }
    }

    for (auto &[i, j] : swaps) {
        if (i > j) swap(i, j);
    }
    
    sort(swaps.begin(), swaps.end());
    swaps.erase(unique(swaps.begin(), swaps.end()), swaps.end());

    if (swaps.empty()) cout << 2 << "\n";
    else {
        cout << 1 << " " << swaps.size() << "\n";
    }
}