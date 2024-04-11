#include <bits/stdc++.h>
using namespace std;

const int I[] = {0, 1, 0, -1};
const int J[] = {1, 0, -1, 0};

const int N = 500;

string grid[N];
int n, m;

int neighbors[N][N], color[N][N];
vector<array<int, 2>> adj[N][N];

void add_edge(int ui, int uj, int vi, int vj) {
    adj[ui][uj].push_back({vi, vj});
    adj[vi][vj].push_back({ui, uj});
}

void dfs(int ui, int uj) {
    for (auto [vi, vj] : adj[ui][uj]) {
        if (color[vi][vj] == 0) {
            color[vi][vj] = -color[ui][uj];
            dfs(vi, vj);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                neighbors[i][j] = -1;
                continue;
            }

            for (int k = 0; k < 4; ++k) {
                neighbors[i][j] += grid[i + I[k]][j + J[k]] == '.';
            }

            if (neighbors[i][j] % 2 != 0) {
                cout << "NO\n";
                exit(0);
            } else if (neighbors[i][j] == 4) {
                add_edge(
                    i, j - 1,
                    i - 1, j
                );
                add_edge(
                    i, j + 1,
                    i + 1, j
                );
            } else if (neighbors[i][j] == 2) {
                for (int k1 = 0; k1 < 4; ++k1) {
                    for (int k2 = k1 + 1; k2 < 4; ++k2) {
                        if (grid[i + I[k1]][j + J[k1]] == '.' && grid[i + I[k2]][j + J[k2]] == '.') {
                            add_edge(
                                i + I[k1], j + J[k1],
                                i + I[k2], j + J[k2]
                            );
                        }
                    }
                }
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (neighbors[i][j] == -1) {
                if (color[i][j] == 0) {
                    color[i][j] = 1;
                    dfs(i, j);
                }
                cout << (color[i][j] == 1 ? 1 : 4) << " ";
            } else {
                cout << neighbors[i][j] * 5 / 2 << " ";
            }
        }
        cout << "\n";
    }
}