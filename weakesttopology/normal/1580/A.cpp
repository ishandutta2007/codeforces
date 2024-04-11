#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M)), B(N, vector<int>(M));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                char c;
                cin >> c;
                A[i][j] = c - '0';
                B[i][j] = A[i][j] + (i ? B[i - 1][j] : 0);
            }
        }
        auto query = [&](int j, int l, int r) {
            if (r < l) return 0;
            return B[r][j] - (l ? B[l - 1][j] : 0);
        };
        int ans = numeric_limits<int>::max();
        for (int xl = 0; xl < N; ++xl) {
            for (int xr = xl + 4; xr < N; ++xr) {
                int len = xr - xl - 1;
                vector<int> p(M);
                int best = numeric_limits<int>::max();
                for (int y = 0; y < M; ++y) {
                    p[y] = query(y, xl + 1, xr - 1) + !A[xl][y] + !A[xr][y] + (y ? p[y - 1] : 0);
                    if (y >= 3) {
                        best = min(best, -p[y - 3] + (len - query(y - 3, xl + 1, xr - 1)));
                        ans = min(ans, best + p[y - 1] + (len - query(y, xl + 1, xr - 1)));
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    exit(0);
}