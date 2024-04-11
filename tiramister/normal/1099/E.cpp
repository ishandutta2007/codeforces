#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> s;
map<char, int> c2i = {{'A', 0}, {'G', 1}, {'C', 2}, {'T', 3}};
string i2c = "AGCT";

int col_cost(int n, int a, int b) {
    int cost = 0;
    for (int m = 0; m < M; ++m) {
        if (m % 2 == 0) {
            cost += (a != s[n][m]);
        } else {
            cost += (b != s[n][m]);
        }
    }
    return cost;
}

int row_cost(int m, int a, int b) {
    int cost = 0;
    for (int n = 0; n < N; ++n) {
        if (n % 2 == 0) {
            cost += (a != s[n][m]);
        } else {
            cost += (b != s[n][m]);
        }
    }
    return cost;
}

int main() {
    cin >> N >> M;

    string S[N];
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    s.resize(N);
    for (int i = 0; i < N; ++i) {
        s[i].resize(M);
        for (int j = 0; j < M; ++j) {
            s[i][j] = c2i[S[i][j]];
        }
    }

    int mincost = N * M;
    int best[2];

    int a[2];
    for (a[0] = 0; a[0] < 4; ++a[0]) {
        for (a[1] = a[0] + 1; a[1] < 4; ++a[1]) {
            int b[2], j = 0;
            for (int i = 0; i < 4; ++i) {
                if (i != a[0] && i != a[1]) {
                    b[j] = i;
                    ++j;
                }
            }

            int cost = 0;

            for (int n = 0; n < N; ++n) {
                if (n % 2 == 0) {
                    cost += min(col_cost(n, a[0], a[1]), col_cost(n, a[1], a[0]));
                } else {
                    cost += min(col_cost(n, b[0], b[1]), col_cost(n, b[1], b[0]));
                }
            }

            if (cost < mincost) {
                memcpy(&best, &a, sizeof(best));
                mincost = cost;
            }
        }
    }

    bool row = false;
    for (a[0] = 0; a[0] < 4; ++a[0]) {
        for (a[1] = a[0] + 1; a[1] < 4; ++a[1]) {
            int b[2], j = 0;
            for (int i = 0; i < 4; ++i) {
                if (i != a[0] && i != a[1]) {
                    b[j] = i;
                    ++j;
                }
            }

            int cost = 0;

            for (int m = 0; m < M; ++m) {
                if (m % 2 == 0) {
                    cost += min(row_cost(m, a[0], a[1]), row_cost(m, a[1], a[0]));
                } else {
                    cost += min(row_cost(m, b[0], b[1]), row_cost(m, b[1], b[0]));
                }
            }

            if (cost < mincost) {
                memcpy(&best, &a, sizeof(best));
                mincost = cost;
                row = true;
            }
        }
    }

    memcpy(&a, &best, sizeof(a));
    int b[2], j = 0;
    for (int i = 0; i < 4; ++i) {
        if (i != a[0] && i != a[1]) {
            b[j] = i;
            ++j;
        }
    }

    vector<string> ans(N, string(M, '$'));

    if (!row) {
        for (int n = 0; n < N; ++n) {
            if (n % 2 == 0) {
                if (col_cost(n, a[0], a[1]) > col_cost(n, a[1], a[0])) swap(a[0], a[1]);
                for (int m = 0; m < M; ++m) {
                    ans[n][m] = i2c[a[m % 2]];
                }
            } else {
                if (col_cost(n, b[0], b[1]) > col_cost(n, b[1], b[0])) swap(b[0], b[1]);
                for (int m = 0; m < M; ++m) {
                    ans[n][m] = i2c[b[m % 2]];
                }
            }
        }
    } else {
        for (int m = 0; m < M; ++m) {
            if (m % 2 == 0) {
                if (row_cost(m, a[0], a[1]) > row_cost(m, a[1], a[0])) swap(a[0], a[1]);
                for (int n = 0; n < N; ++n) {
                    ans[n][m] = i2c[a[n % 2]];
                }
            } else {
                if (row_cost(m, b[0], b[1]) > row_cost(m, b[1], b[0])) swap(b[0], b[1]);
                for (int n = 0; n < N; ++n) {
                    ans[n][m] = i2c[b[n % 2]];
                }
            }
        }
    }

    for (int n = 0; n < N; ++n) {
        cout << ans[n] << endl;
    }
    return 0;
}