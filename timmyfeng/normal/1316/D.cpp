#include <bits/stdc++.h>
using namespace std;

vector<int> dR = {0, -1, 0, 1};
vector<int> dC = {1, 0, -1, 0};
vector<char> dir = {'R', 'U', 'L', 'D'};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> grid(n + 1, vector<pair<int, int>>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j].first >> grid[i][j].second;
        }
    }

    vector<vector<char>> sol(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (sol[i][j]) continue;
            if (grid[i][j].first == -1) {
                for (int k = 0; k < 4; ++k) {
                    int r = i + dR[k], c = j + dC[k];
                    if (r && r <= n && c && c <= n && grid[r][c].first == -1) {
                        sol[r][c] = dir[(k + 2) % 4];
                        sol[i][j] = dir[k];
                        break;
                    }
                }
                if (!sol[i][j]) {
                    cout << "INVALID" << '\n';
                    exit(0);
                }
            } else {
                int sR, sC;
                tie(sR, sC) = grid[i][j];
                queue<pair<int, int>> q;
                if (sol[sR][sC]) {
                    cout << "INVALID" << '\n';
                    exit(0);
                } else {
                    sol[sR][sC] = 'X';
                }
                q.emplace(sR, sC);
                while (!q.empty()) {
                    int r, c;
                    tie(r, c) = q.front();
                    q.pop();
                    for (int i = 0; i < 4; ++i) {
                        int nR = r + dR[i], nC = c + dC[i];
                        if (nR && nR <= n && nC && nC <= n && !sol[nR][nC] &&
                                grid[nR][nC] == grid[r][c]) {
                            sol[nR][nC] = dir[(i + 2) % 4];
                            q.emplace(nR, nC);
                        }
                    }
                }
                if (!sol[i][j]) {
                    cout << "INVALID" << '\n';
                    exit(0);
                }
            }
        }
    }
    cout << "VALID" << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << sol[i][j];
        }
        cout << '\n';
    }
}